#ifndef __BIGORIGIN_H_
#define __BIGORIGIN_H_

#include "d3dx9.h"

class WindowsListener;
class SceneManager;
class Scene;
class SceneNode;

class Origin
{
private:
	int topLeftX, topLeftY;								//�������Ͻ�λ��
	int nWidth, nHeight;									//���ڿ���
	HWND hWnd;											//���ھ��
	D3DDEVTYPE mDeviceType;					//DirectX3D��ͼ�豸����
	bool windowed;											//�Ƿ�Ϊ����ģʽ
	PDIRECT3DDEVICE9 pD3DDevice;		//DirectX3D��ͼ�豸
	LPD3DXSPRITE pSprite;							//�㾫��
	Scene* pBigScene;										//����ͼ
	WindowsListener* pBigWinListener;		//���ڼ�����
	SceneManager* pSceneManager;				//����������

public:

private:
	//����DirectX3D��ͼ�豸
	bool createDirect3DDevice();

	//�����㾫��
	bool createSprite();

	//�������������������ٰ������ڵ��һ���ӽڵ�
	bool createScene();

	//void helpRenderOneFrame(SceneNode* m_pRootNode);

public:
	//
	Origin(HINSTANCE _hInstance, int nCmdShow);
	
	//
	~Origin();
	
	//��ó���������ָ��,��������ɾ���������Ը�
	SceneManager* GetSceneManager();

	//��Ӵ��ڼ�����
	void AddWindowsListener(WindowsListener* pWindowsListener);
	
	//��Ⱦһ�γ���
	void RenderOneFrame();
	
	//������Ϣѭ����ʼ��Ⱦ
	void StartRendering();

	//
	void UpdateParticals(DWORD deltaTime);

};

#endif