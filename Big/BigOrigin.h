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
	int topLeftX, topLeftY;								//窗口左上角位置
	int nWidth, nHeight;									//窗口宽、高
	HWND hWnd;											//窗口句柄
	D3DDEVTYPE mDeviceType;					//DirectX3D绘图设备类型
	bool windowed;											//是否为窗口模式
	PDIRECT3DDEVICE9 pD3DDevice;		//DirectX3D绘图设备
	LPD3DXSPRITE pSprite;							//点精灵
	Scene* pBigScene;										//场景图
	WindowsListener* pBigWinListener;		//窗口监听者
	SceneManager* pSceneManager;				//场景管理器

public:

private:
	//创建DirectX3D绘图设备
	bool createDirect3DDevice();

	//创建点精灵
	bool createSprite();

	//创建场景，场景中至少包括根节点和一个子节点
	bool createScene();

	//void helpRenderOneFrame(SceneNode* m_pRootNode);

public:
	//
	Origin(HINSTANCE _hInstance, int nCmdShow);
	
	//
	~Origin();
	
	//获得场景管理器指针,不许随意删除否则后果自负
	SceneManager* GetSceneManager();

	//添加窗口监听者
	void AddWindowsListener(WindowsListener* pWindowsListener);
	
	//渲染一次场景
	void RenderOneFrame();
	
	//进入消息循环开始渲染
	void StartRendering();

	//
	void UpdateParticals(DWORD deltaTime);

};

#endif