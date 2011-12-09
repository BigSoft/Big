#ifndef __BIGSCENE_H_
#define __BIGSCENE_H_

#include <set>
#include "BigParticalSystem.h"

class SceneNode;
class SceneEntity;

typedef std::set<SceneEntity*>::iterator RenderCursor;
typedef std::set<psys::PSystem*>::iterator ParticalCursor;

class Scene
{
private:
	SceneNode* pOriginSceneNode;								//场景根节点
	std::set<SceneNode*> pUseableSceneNodes;				//场景中可用的(未挂载实体)空节点
	std::set<SceneEntity*> pAttachedSceneEntities;		//已挂载到场景中的实体,渲染使用
	std::set<psys::PSystem*> pBigPSyses;									//场景中的粒子系統
	std::set<psys::PSystem*> pBigDiedPSyses;							//场景中失效的粒子系統

public:

private:

public:
	//
	Scene();

	//
	~Scene();

	//添加可用的空节点
	bool AddUseableSceneNode(SceneNode* pSceneNode);

	//删除可用的空节点
	bool DeleteUseableSceneNode(SceneNode* pSceneNode);

	//添加挂载到场景中的实体
	bool AddAttachedSceneEntity(SceneEntity* pSceneEntity);

	//删除一个挂载到场景中的实体
	bool DeleteAttachedSceneEntity(SceneEntity* pSceneEntity);

	//获得场景中跟节点
	SceneNode* GetOriginSceneNodeP();

	//获得已挂载到场景中实体集合的开始点迭代器
	RenderCursor GetStartRenderEntity();

	//获得已挂载到场景中实体集合的结束点迭代器
	RenderCursor GetEndRenderEntity();
	
	ParticalCursor GetStartParticalCursor();
	ParticalCursor GetEndParticalCursor();
	void UpdateParticals(DWORD deltaTime);

friend class SceneManager;
};

#endif