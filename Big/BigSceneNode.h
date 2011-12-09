#ifndef __BIGSCENENODE_H_
#define __BIGSCENENODE_H_

#include <set>

class Scene;
class SceneEntity;

class SceneNode
{
private:
	Scene* pScene;															//�ڵ����ڳ���ͼָ��
	std::set<SceneNode*> pChildSceneNodes;				//�ӽڵ�
	SceneEntity* pAttachedEntity;								//���ص���ǰ�ڵ��ʵ��
	SceneNode* pParentSceneNode;								//���ڵ�

public:
	
private:
	//���ڵ����Ϊ�չ���
	bool isLegal();

public:
	//
	SceneNode(Scene* _pScene, SceneNode* _pParentSceneNode = NULL);

	//
	~SceneNode();

	//��ù��ص���ǰ�ڵ��ʵ�壬�սڵ㷵��NULL
	SceneEntity* GetAttachedSceneEntity();

	//����ʵ�嵽��ǰ�ڵ㣬�ǿսڵ㷵��false
	bool AttachSceneEntity(SceneEntity* _pEntity);

	//ж�ع��ص���ǰ�ڵ��ʵ�壬�սڵ㷵��false
	bool DetachSceneEntity();

	//ɾ�����е��ӽڵ㣬�������Լ�
	void DeleteAllChildSceneNodes();

	//�����ӽڵ�
	SceneNode* CreateChildSceneNode();

	//ɾ���ӽڵ㣬���ӽڵ�false
	bool DeleteChildSceneNode(SceneNode* pChildSceneNode);

	//��ø��ڵ�
	SceneNode* GetParentSceneNodeP();

friend class Origin;
friend class SceneManager;
};

#endif