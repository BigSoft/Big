#include "BigSceneNode.h"

#include "Windows.h"

#include "BigSceneEntity.h"
#include "BigScene.h"

bool SceneNode::isLegal()
{
	if((pChildSceneNodes.size() != 0) && (pAttachedEntity != NULL))
		return false;
	else
		return true;
}

SceneEntity* SceneNode::GetAttachedSceneEntity()
{
	return this->pAttachedEntity;
}

SceneNode::SceneNode(Scene *_pScene, SceneNode *_pParentSceneNode)
: pScene(_pScene), pParentSceneNode(_pParentSceneNode), pAttachedEntity(NULL)
{
}

SceneNode::~SceneNode()
{
	for(std::set<SceneNode*>::iterator cursor = pChildSceneNodes.begin(); cursor != pChildSceneNodes.end(); cursor++)
		delete (*cursor);
}

bool SceneNode::AttachSceneEntity(SceneEntity *_pEntity)
{
	if((pAttachedEntity == NULL) && (pChildSceneNodes.size() == 0) && (_pEntity->GetTexture() != NULL))
	{
		pAttachedEntity = _pEntity;
		pAttachedEntity->SetAttachedSceneNode(this);
		pScene->DeleteUseableSceneNode(this);
		pScene->AddAttachedSceneEntity(this->pAttachedEntity);
		return true;
	}
	else
		return false;
}

bool SceneNode::DetachSceneEntity()
{
	if(pAttachedEntity != NULL)
	{
		pScene->DeleteAttachedSceneEntity(pAttachedEntity);
		pScene->AddUseableSceneNode(this);
		pAttachedEntity->pAttachedSceneNode = NULL;
		pAttachedEntity = NULL;
		return true;
	}
	else
		return false;
}

SceneNode* SceneNode::CreateChildSceneNode()
{
	if(this->pAttachedEntity == NULL)
	{
		if(this->pChildSceneNodes.size() == 0)
			pScene->DeleteUseableSceneNode(this);

		SceneNode* pChildSceneNode = new SceneNode(this->pScene, this);
		pChildSceneNodes.insert(pChildSceneNode);
		pScene->AddUseableSceneNode(pChildSceneNode);
		return pChildSceneNode;
	}
	else
		return NULL;
}

void SceneNode::DeleteAllChildSceneNodes()
{
	if(pChildSceneNodes.size() != 0)
	{
		SceneEntity* pChildSceneNode_Entity;
		for(std::set<SceneNode*>::iterator cursor = pChildSceneNodes.begin(); cursor != pChildSceneNodes.end(); cursor++)
		{
			pChildSceneNode_Entity = (*cursor)->GetAttachedSceneEntity();
			if(pChildSceneNode_Entity == NULL)
			{
				(*cursor)->DeleteAllChildSceneNodes();
				pScene->DeleteUseableSceneNode(*cursor);
			}
			else
			{
				pScene->DeleteAttachedSceneEntity(pChildSceneNode_Entity);
			}
			delete (*cursor);
		}
		pChildSceneNodes.clear();
		pScene->AddUseableSceneNode(this);
	}
}

bool SceneNode::DeleteChildSceneNode(SceneNode *pChildSceneNode)
{
	std::set<SceneNode*>::iterator cursor = pChildSceneNodes.find(pChildSceneNode);
	if(cursor != pChildSceneNodes.end())
	{
		(*cursor)->DeleteAllChildSceneNodes();
		SceneEntity* pChildSceneNode_Entity = (*cursor)->GetAttachedSceneEntity();
		if(pChildSceneNode_Entity == NULL)
		{
			pScene->DeleteUseableSceneNode(*cursor);
		}
		else
		{
			pScene->DeleteAttachedSceneEntity(pChildSceneNode_Entity);
		}
		delete (*cursor);
		pChildSceneNodes.erase(cursor);
		if(pChildSceneNodes.size() == 0)
			pScene->AddUseableSceneNode(this);

		return true;
	}
	else
		return false;
}

SceneNode* SceneNode::GetParentSceneNodeP()
{
	return pParentSceneNode;
}

