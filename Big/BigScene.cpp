#include "BigScene.h"

#include <assert.h>

#include "Windows.h"
#include "BigSceneNode.h"

Scene::Scene()
{
	pOriginSceneNode = new SceneNode(this);
	pUseableSceneNodes.insert(pOriginSceneNode);
	pOriginSceneNode->CreateChildSceneNode();
}

Scene::~Scene()
{
	delete pOriginSceneNode;
	for(std::set<psys::PSystem*>::iterator cursor = pBigPSyses.begin(); cursor != pBigPSyses.end(); cursor++)
		delete (*cursor);
}

SceneNode* Scene::GetOriginSceneNodeP()
{
	return pOriginSceneNode;
}

bool Scene::AddUseableSceneNode(SceneNode* pSceneNode)
{
	std::set<SceneNode*>::iterator cursor = pUseableSceneNodes.find(pSceneNode);
	if(cursor == pUseableSceneNodes.end())
	{
		pUseableSceneNodes.insert(pSceneNode);
		return true;
	}
	else
	{
		MessageBox(0, "AddUseableSceneNode() - Aim have been have.", 0, 0);
		return false;
	}
}

bool Scene::DeleteUseableSceneNode(SceneNode *pSceneNode)
{
	std::set<SceneNode*>::iterator cursor = pUseableSceneNodes.find(pSceneNode);
	if(cursor != pUseableSceneNodes.end())
	{
		pUseableSceneNodes.erase(cursor);
		return true;
	}
	else
	{
		MessageBox(0, "DeleteUseableSceneNode() - Aim is not find.", 0, 0);
		return false;
	}
}

bool Scene::AddAttachedSceneEntity(SceneEntity *pSceneEntity)
{
	std::set<SceneEntity*>::iterator cursor = pAttachedSceneEntities.find(pSceneEntity);
	if(cursor == pAttachedSceneEntities.end())
	{
		pAttachedSceneEntities.insert(pSceneEntity);
		return true;
	}
	else
	{
		MessageBox(0, "AddAttachedSceneEntitie() - Aim have been have.", 0, 0);
		return false;
	}
}

bool Scene::DeleteAttachedSceneEntity(SceneEntity *pSceneEntity)
{
	std::set<SceneEntity*>::iterator cursor = pAttachedSceneEntities.find(pSceneEntity);
	if(cursor != pAttachedSceneEntities.end())
	{
		pAttachedSceneEntities.erase(cursor);
		return true;
	}
	else
	{
		MessageBox(0, "DeleteAttachedSceneEntitie() - Aim is not find.", 0, 0);
		return false;
	}
}

RenderCursor Scene::GetStartRenderEntity()
{
	return pAttachedSceneEntities.begin();
}

RenderCursor Scene::GetEndRenderEntity()
{
	return pAttachedSceneEntities.end();
}

ParticalCursor Scene::GetStartParticalCursor()
{
	return this->pBigPSyses.begin();
}

ParticalCursor Scene::GetEndParticalCursor()
{
	return this->pBigPSyses.end();
}

void Scene::UpdateParticals(DWORD deltaTime)
{
	for(ParticalCursor cursor = GetStartParticalCursor();
		cursor != GetEndParticalCursor(); cursor++)
	{
		if(!(*cursor)->isDead())
		{
			(*cursor)->update(deltaTime * 0.001f);		//ºÁÃë->Ãë
			if((*cursor)->isDead())
				pBigDiedPSyses.insert(*cursor);
		}
	}
}
