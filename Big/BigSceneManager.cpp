#include "BigSceneManager.h"

#include "BigSceneNode.h"
#include "BigTexture.h"
#include "BigScene.h"

SceneManager::SceneManager() : pD3DDevice(NULL), pScene(NULL)
{
}

//SceneNode* SceneManager::GetOriginSceneNode()
//{
//	return pScene->GetOriginSceneNodeP();
//}

Texture* SceneManager::CreateTexture(const std::string &sourceFileName, unsigned int Width, unsigned int Height)
{
	Texture* pTexture = new Texture();
	pTexture->Width = Width;
	pTexture->Height = Height;
	if(D3DXCreateTextureFromFileEx(pD3DDevice, sourceFileName.c_str(),
																D3DX_DEFAULT_NONPOW2, D3DX_DEFAULT_NONPOW2,D3DX_DEFAULT,
																D3DUSAGE_RENDERTARGET, D3DFMT_FROM_FILE,
																D3DPOOL_DEFAULT, D3DX_DEFAULT,
																D3DX_DEFAULT, 0xFF000000,
																NULL, NULL,
																&(pTexture->pD3DTexture)) == D3D_OK)
		return pTexture;
	else
		return NULL;
}

void SceneManager::DeleteSceneNode(SceneNode **ppSceneNode)
{
	SceneNode* pParentSceneNode = (*ppSceneNode)->pParentSceneNode;
	if((pParentSceneNode != NULL) &&
		((pParentSceneNode != pScene->pOriginSceneNode) || (pParentSceneNode->pChildSceneNodes.size() > 1)))
	{
		pParentSceneNode->DeleteChildSceneNode(*ppSceneNode);
		*ppSceneNode = NULL;
	}
	else
		MessageBox(0, "DeleteSceneNode() - Origine node and it's last only one node can't be deleted.", 0, 0);
}

//unsigned int SceneManager::GetALLSceneNodesNumber()
//{
//	this->pScene->pUseableSceneNodes.size();
//}

unsigned int SceneManager::GetUseableSceneNodesNumber()
{
	return this->pScene->pUseableSceneNodes.size();
}

SceneNode* SceneManager::GetAUseableSceneNode()
{
	if(this->pScene->pUseableSceneNodes.size() > 0)
		return *(this->pScene->pUseableSceneNodes.begin());
	else
		return this->pScene->GetOriginSceneNodeP()->CreateChildSceneNode();
}

psys::PSystem* SceneManager::GetAUseablePSys(D3DXVECTOR2* origin, int numParticles)
{
	psys::PSystem* tempP = 0;
	if(this->pScene->pBigDiedPSyses.size() > 0)
	{
		tempP = *(pScene->pBigDiedPSyses.begin());
		pScene->pBigDiedPSyses.erase(pScene->pBigDiedPSyses.begin());
		tempP->reset(*origin);
	}
	else
	{
		tempP = new psys::Firework(origin, numParticles);
		tempP->init(this->pD3DDevice, "../high/particle.PNG");
		pScene->pBigPSyses.insert(tempP);
	}

	return tempP;
}
