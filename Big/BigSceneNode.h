#ifndef __BIGSCENENODE_H_
#define __BIGSCENENODE_H_

#include <set>

class Scene;
class SceneEntity;

class SceneNode
{
private:
	Scene* pScene;															//节点所在场景图指针
	std::set<SceneNode*> pChildSceneNodes;				//子节点
	SceneEntity* pAttachedEntity;								//挂载到当前节点的实体
	SceneNode* pParentSceneNode;								//父节点

public:
	
private:
	//茎节点必须为空挂载
	bool isLegal();

public:
	//
	SceneNode(Scene* _pScene, SceneNode* _pParentSceneNode = NULL);

	//
	~SceneNode();

	//获得挂载到当前节点的实体，空节点返回NULL
	SceneEntity* GetAttachedSceneEntity();

	//挂载实体到当前节点，非空节点返回false
	bool AttachSceneEntity(SceneEntity* _pEntity);

	//卸载挂载到当前节点的实体，空节点返回false
	bool DetachSceneEntity();

	//删除所有的子节点，并晋升自己
	void DeleteAllChildSceneNodes();

	//创建子节点
	SceneNode* CreateChildSceneNode();

	//删除子节点，非子节点false
	bool DeleteChildSceneNode(SceneNode* pChildSceneNode);

	//获得父节点
	SceneNode* GetParentSceneNodeP();

friend class Origin;
friend class SceneManager;
};

#endif