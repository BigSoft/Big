#include "BigOrigin.h"

#include "BigWindowsListener.h"
#include "BigSceneManager.h"
#include "BigScene.h"
#include "BigSceneNode.h"
#include "BigSceneEntity.h"
#include "BigWindowsUtility.h"

bool Origin::createDirect3DDevice()
{
	// Step 1: Create the IDirect3D9 object.

	IDirect3D9* d3d9 = NULL;
	d3d9 = Direct3DCreate9(D3D_SDK_VERSION);

	if( !d3d9 )
	{
		MessageBox(0, "Direct3DCreate9() - FAILED", 0, 0);
		return false;
	}

	// Step 2: Check for hardware vp.

	D3DCAPS9 caps;
	d3d9->GetDeviceCaps(D3DADAPTER_DEFAULT, mDeviceType, &caps);

	DWORD vp = 0;
	if( caps.DevCaps & D3DDEVCAPS_HWTRANSFORMANDLIGHT )
		vp = D3DCREATE_HARDWARE_VERTEXPROCESSING;
	else
		vp = D3DCREATE_SOFTWARE_VERTEXPROCESSING;

	// Step 3: Fill out the D3DPRESENT_PARAMETERS structure.

	D3DPRESENT_PARAMETERS d3dpp;
	d3dpp.BackBufferWidth            = nWidth;
	d3dpp.BackBufferHeight           = nHeight;
	d3dpp.BackBufferFormat           = D3DFMT_A8R8G8B8;
	d3dpp.BackBufferCount            = 1;
	d3dpp.MultiSampleType            = D3DMULTISAMPLE_NONE;
	d3dpp.MultiSampleQuality         = 0;
	d3dpp.SwapEffect                 = D3DSWAPEFFECT_DISCARD; 
	d3dpp.hDeviceWindow              = hWnd;
	d3dpp.Windowed                   = windowed;
	d3dpp.EnableAutoDepthStencil     = true; 
	d3dpp.AutoDepthStencilFormat     = D3DFMT_D24S8;
	d3dpp.Flags                      = 0;
	d3dpp.FullScreen_RefreshRateInHz = D3DPRESENT_RATE_DEFAULT;
	d3dpp.PresentationInterval       = D3DPRESENT_INTERVAL_IMMEDIATE;

	// Step 4: Create the device.

	HRESULT hr = NULL;
	hr = d3d9->CreateDevice(
		D3DADAPTER_DEFAULT, // primary adapter
		mDeviceType,         // device type
		hWnd,               // window associated with device
		vp,                 // vertex processing
		&d3dpp,             // present parameters
		&pD3DDevice);            // return created device

	if( FAILED(hr) )
	{
		// try again using a 16-bit depth buffer
		d3dpp.AutoDepthStencilFormat = D3DFMT_D16;

		hr = d3d9->CreateDevice(
			D3DADAPTER_DEFAULT, // primary adapter
			mDeviceType,         // device type
			hWnd,               // window associated with device
			vp,                 // vertex processing
			&d3dpp,             // present parameters
			&pD3DDevice);            // return created device

		if( FAILED(hr) )
		{
			d3d9->Release(); // done with d3d9 object
			MessageBox(0, "CreateDevice() - FAILED", 0, 0);
			return false;
		}
	}

	d3d9->Release(); // done with d3d9 object

	return true;
}

bool Origin::createSprite()
{
	if(D3DXCreateSprite(pD3DDevice, &pSprite) == S_OK)
		return true;
	else
	{
		MessageBox(0, "CreateSprite() - FAILED", 0, 0);
		return false;
	}
}

bool Origin::createScene()
{
	pBigScene = new Scene();
	return true;
}

//void Origin::helpRenderOneFrame(SceneNode* pRootNode)
//{
//	if( ! pRootNode->isLegal())
//	{
//		MessageBox(0, "helpRenderOneFrame() - enlegal node", 0, 0);
//		return;
//	}
//
//	if(pRootNode->pChildSceneNodes.size() == 0)
//	{
//		PBIGSCENEENTITY pEntity = pRootNode->GetAttachedSceneEntity();
//		if(pEntity != NULL)
//		{
//			D3DXMATRIX tramatrix;
//			D3DXMatrixTransformation2D(&tramatrix, NULL, NULL, NULL, NULL, pEntity->GetAngle(), &(pEntity->GetPosition()));
//			pSprite->SetTransform(&tramatrix);
//			pSprite->Draw(pEntity->GetTexture(), NULL, NULL,
//				&D3DXVECTOR3(-float(pEntity->GetTextureWidth()) / 2, -float(pEntity->GetTextureHeight()) / 2, 0.0),
//				D3DCOLOR_RGBA(255, 255, 255, 255));
//		}
//		else
//			return;
//	}
//	else
//	{
//		for(std::set<SceneNode*>::iterator cursor = pRootNode->pChildSceneNodes.begin();
//			cursor != pRootNode->pChildSceneNodes.end(); cursor++)
//		{
//			this->helpRenderOneFrame(*cursor);
//		}
//	}
//}

Origin::Origin(HINSTANCE _hInstance, int _nCmdShow)
: mDeviceType(D3DDEVTYPE_HAL), windowed(TRUE),
pBigWinListener(NULL), pSceneManager(NULL)
{
	topLeftX = 50;
	topLeftY = 50;
	nWidth = 1024;
	nHeight = 768;
	::MyRegisterClass(_hInstance);
	::InitInstance(hWnd, _hInstance, _nCmdShow, topLeftX, topLeftY, nWidth, nHeight);
	this->createDirect3DDevice();
	this->createSprite();
	this->createScene();
}

Origin::~Origin()
{
	pD3DDevice->Release();
	pSprite->Release();
	delete pBigScene;
	if(pSceneManager != NULL)
		delete pSceneManager;
}

SceneManager* Origin::GetSceneManager()
{
	if(pSceneManager == NULL)
	{
		pSceneManager = new SceneManager();
		pSceneManager->pD3DDevice = this->pD3DDevice;
		pSceneManager->pScene = this->pBigScene;
	}

	return pSceneManager;
}

void Origin::AddWindowsListener(WindowsListener *pWindowsListener)
{
	pBigWinListener = pWindowsListener;
}

void Origin::RenderOneFrame()
{
	//
	pD3DDevice->SetTextureStageState(0, D3DTSS_ALPHAARG1, D3DTA_TEXTURE);
	pD3DDevice->SetTextureStageState(0, D3DTSS_ALPHAOP, D3DTOP_SELECTARG1);
	pD3DDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, true);
	pD3DDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_ONE);
	pD3DDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_ONE);

	//
	pD3DDevice->Clear(0, 0, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, 0x00000000, 1.0f, 0);
	pD3DDevice->BeginScene();
	pSprite->Begin(D3DXSPRITE_DONOTSAVESTATE);

	//PBIGSCENENODE pOrigineSceneNodeP = pBigScene->GetOriginSceneNodeP();
	//helpRenderOneFrame(pOrigineSceneNodeP);
	
	D3DXMATRIX tramatrix;
	PDIRECT3DTEXTURE9 pTexture = NULL;
	for(RenderCursor cursor = pBigScene->GetStartRenderEntity();
		cursor != pBigScene->GetEndRenderEntity(); cursor++)
	{
		D3DXMatrixTransformation2D(&tramatrix, NULL, NULL, NULL, NULL, (*cursor)->GetAngle(), &((*cursor)->GetPosition()));
		pSprite->SetTransform(&tramatrix);
		pTexture = (*cursor)->GetTexture();
		if(pTexture != NULL)
		{
			pSprite->Draw(pTexture, NULL, NULL,
			&D3DXVECTOR3(-float((*cursor)->GetTextureWidth()) / 2, -float((*cursor)->GetTextureHeight()) / 2, 0.0),
			D3DCOLOR_RGBA(255, 255, 255, 255));
		}
		else
		{
			MessageBox(0, "RenderOneFrame() - NULL Texture", 0, 0);
		}
	}

	for(ParticalCursor cursor = pBigScene->GetStartParticalCursor();
		cursor != pBigScene->GetEndParticalCursor(); cursor++)
	{
		if( !(*cursor)->isDead())
			(*cursor)->render();
	}

	pSprite->End();
	pD3DDevice->EndScene();
	pD3DDevice->Present(0, 0, 0, 0);
}

void Origin::StartRendering()
{
	if(pBigWinListener != NULL)
		::EnterMsgLoop(pBigWinListener, this);
	else
		MessageBox(0, "WindowsListener is not available.", 0, 0);
}

void Origin::UpdateParticals(DWORD deltaTime)
{
	pBigScene->UpdateParticals(deltaTime);
}