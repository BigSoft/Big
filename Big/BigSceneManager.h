#ifndef __BIGSCENEMANAGER_H_
#define __BIGSCENEMANAGER_H_

#include "d3dx9.h"
#include <string>

#include "BigParticalSystem.h"

class SceneNode;
class Texture;
class Scene;

class SceneManager
{
private:
	PDIRECT3DDEVICE9 pD3DDevice;		//DirectX3D��ͼ�豸
	Scene* pScene;												//����ͼ

public:

private:

public:
	//
	SceneManager();

	//
	//SceneNode* GetOriginSceneNode();

	//����һ�����Թ��ص�����ʵ���ϵĲ���
	Texture* CreateTexture(const std::string &sourceFileName, unsigned int Width, unsigned int Height);

	//ɾ��ָ�������ڵ㣬������ʹ��
	void DeleteSceneNode(SceneNode** ppSceneNode);

	//���Ŀǰ���õĿճ����ڵ���Ŀ
	unsigned int GetUseableSceneNodesNumber();

	//���һ�����õĳ����ڵ�
	SceneNode* GetAUseableSceneNode();

	//��ÿ��õ�����ϵ�y
	psys::PSystem* GetAUseablePSys(D3DXVECTOR2* origin, int numParticles = 8);

	//
	//unsigned int GetALLSceneNodesNumber();

friend class Origin;
};

#endif