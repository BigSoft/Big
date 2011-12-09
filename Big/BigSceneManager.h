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
	PDIRECT3DDEVICE9 pD3DDevice;		//DirectX3D绘图设备
	Scene* pScene;												//场景图

public:

private:

public:
	//
	SceneManager();

	//
	//SceneNode* GetOriginSceneNode();

	//创建一个可以挂载到场景实体上的材质
	Texture* CreateTexture(const std::string &sourceFileName, unsigned int Width, unsigned int Height);

	//删除指定场景节点，不建议使用
	void DeleteSceneNode(SceneNode** ppSceneNode);

	//获得目前可用的空场景节点数目
	unsigned int GetUseableSceneNodesNumber();

	//获得一个可用的场景节点
	SceneNode* GetAUseableSceneNode();

	//获得可用的粒子系統
	psys::PSystem* GetAUseablePSys(D3DXVECTOR2* origin, int numParticles = 8);

	//
	//unsigned int GetALLSceneNodesNumber();

friend class Origin;
};

#endif