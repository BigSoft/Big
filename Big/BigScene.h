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
	SceneNode* pOriginSceneNode;								//�������ڵ�
	std::set<SceneNode*> pUseableSceneNodes;				//�����п��õ�(δ����ʵ��)�սڵ�
	std::set<SceneEntity*> pAttachedSceneEntities;		//�ѹ��ص������е�ʵ��,��Ⱦʹ��
	std::set<psys::PSystem*> pBigPSyses;									//�����е�����ϵ�y
	std::set<psys::PSystem*> pBigDiedPSyses;							//������ʧЧ������ϵ�y

public:

private:

public:
	//
	Scene();

	//
	~Scene();

	//��ӿ��õĿսڵ�
	bool AddUseableSceneNode(SceneNode* pSceneNode);

	//ɾ�����õĿսڵ�
	bool DeleteUseableSceneNode(SceneNode* pSceneNode);

	//��ӹ��ص������е�ʵ��
	bool AddAttachedSceneEntity(SceneEntity* pSceneEntity);

	//ɾ��һ�����ص������е�ʵ��
	bool DeleteAttachedSceneEntity(SceneEntity* pSceneEntity);

	//��ó����и��ڵ�
	SceneNode* GetOriginSceneNodeP();

	//����ѹ��ص�������ʵ�弯�ϵĿ�ʼ�������
	RenderCursor GetStartRenderEntity();

	//����ѹ��ص�������ʵ�弯�ϵĽ����������
	RenderCursor GetEndRenderEntity();
	
	ParticalCursor GetStartParticalCursor();
	ParticalCursor GetEndParticalCursor();
	void UpdateParticals(DWORD deltaTime);

friend class SceneManager;
};

#endif