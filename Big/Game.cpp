#include "Game.h"

#include "BigBoundingGeometry.h"
#include "GameListener.h"
#include "GameEntity.h"
#include "PlayerEntity.h"
#include "SightEntity.h"

#include "BulletEntity.h"
#include "FanEntity.h"
#include "BluediamondEntity.h"
#include "GreensquareEntity.h"
#include "Purplesquare1Entity.h"
#include "Purplesquare2Entity.h"
#include "IndigotriangleEntity.h"
#include "BluecircleEntity.h"
#include "OrangetriangleEntity.h"
#include "RedcircleEntity.h"
#include "RedcloneEntity.h"

void Game::initScene()
{
	pTextures[whiteplayer] = pSceneManager->CreateTexture("../high/whiteplayer.png", 64, 64);
	pTextures[yellowshot] = pSceneManager->CreateTexture("../high/yellowshot.png", 32, 32);
	pTextures[sight] = pSceneManager->CreateTexture("../high/sight.png", 32, 32);
	pTextures[pinkpinwheel] = pSceneManager->CreateTexture("../high/pinkpinwheel.png", 64, 64);
	pTextures[bluediamond] = pSceneManager->CreateTexture("../high/bluediamond.png", 64, 64);

	pTextures[greensquare] = pSceneManager->CreateTexture("../high/greensquare.png", 64, 64);
	pTextures[purplesquare1] = pSceneManager->CreateTexture("../high/purplesquare1.png", 64, 64);
	pTextures[purplesquare2] = pSceneManager->CreateTexture("../high/purplesquare2.png", 64, 64);
	pTextures[indigotriangle] = pSceneManager->CreateTexture("../high/indigotriangle.png", 64, 64);
	pTextures[bluecircle] = pSceneManager->CreateTexture("../high/bluecircle.png", 64, 64);

	pTextures[orangetriangle] = pSceneManager->CreateTexture("../high/orangetriangle.png", 64, 64);
	pTextures[redcircle] = pSceneManager->CreateTexture("../high/redcircle.png", 128, 128);
	pTextures[redclone] = pSceneManager->CreateTexture("../high/B_redclone.png", 64, 64);

	pPlayer = new PlayerEntity(this, Vector2D(pBoundary->BottomRight.x - pBoundary->TopLeft.x,
		pBoundary->BottomRight.y - pBoundary->TopLeft.y) /2);
	pPlayer->AttachTexture(pTextures[whiteplayer]);
	pSceneManager->GetAUseableSceneNode()->AttachSceneEntity(pPlayer);

	pSight = new SightEntity(this, Vector2D(pBoundary->BottomRight.x - pBoundary->TopLeft.x,
		pBoundary->BottomRight.y - pBoundary->TopLeft.y) /2);
	pSight->AttachTexture(pTextures[sight]);
	pSceneManager->GetAUseableSceneNode()->AttachSceneEntity(pSight);

	//
	for(int i = 0; i < 10; i++)
	{
		this->GetAAliveEntity(pinkpinwheel,
			Vector2D((rand() * (pBoundary->BottomRight.x - pBoundary->TopLeft.x)) / RAND_MAX + pBoundary->TopLeft.x,
			(rand() * (pBoundary->BottomRight.y - pBoundary->TopLeft.y)) / RAND_MAX + pBoundary->TopLeft.y),
			Vector2D((rand() * 2.0) / RAND_MAX - 1.0, (rand() * 2.0) / RAND_MAX - 1.0).Normalize());
	}
	for(int i = 0; i < 10; i++)
	{
		this->GetAAliveEntity(bluediamond,
			Vector2D((rand() * (pBoundary->BottomRight.x - pBoundary->TopLeft.x)) / RAND_MAX + pBoundary->TopLeft.x,
			(rand() * (pBoundary->BottomRight.y - pBoundary->TopLeft.y)) / RAND_MAX + pBoundary->TopLeft.y));
	}
	for(int i = 0; i < 10; i++)
	{
		this->GetAAliveEntity(greensquare,
			Vector2D((rand() * (pBoundary->BottomRight.x - pBoundary->TopLeft.x)) / RAND_MAX + pBoundary->TopLeft.x,
			(rand() * (pBoundary->BottomRight.y - pBoundary->TopLeft.y)) / RAND_MAX + pBoundary->TopLeft.y),
			Vector2D((rand() * 2.0) / RAND_MAX - 1.0, (rand() * 2.0) / RAND_MAX - 1.0).Normalize());
	}
	for(int i = 0; i < 10; i++)
	{
		this->GetAAliveEntity(purplesquare1,
			Vector2D((rand() * (pBoundary->BottomRight.x - pBoundary->TopLeft.x)) / RAND_MAX + pBoundary->TopLeft.x,
			(rand() * (pBoundary->BottomRight.y - pBoundary->TopLeft.y)) / RAND_MAX + pBoundary->TopLeft.y),
			Vector2D((rand() * 2.0) / RAND_MAX - 1.0, (rand() * 2.0) / RAND_MAX - 1.0).Normalize());
	}
	/*for(int i = 0; i < 10; i++)
	{
	this->GetAAliveEntity(purplesquare2,
	Vector2D((rand() * (pBoundary->BottomRight.x - pBoundary->TopLeft.x)) / RAND_MAX + pBoundary->TopLeft.x,
	(rand() * (pBoundary->BottomRight.y - pBoundary->TopLeft.y)) / RAND_MAX + pBoundary->TopLeft.y),
	Vector2D((rand() * 2.0) / RAND_MAX - 1.0, (rand() * 2.0) / RAND_MAX - 1.0).Normalize());
	}*/
}

Game::Game(HINSTANCE _hInstance, int nCmdShow)
{
	fireBufferTime = 100;
	pOrigin = new Origin(_hInstance, nCmdShow);
	pSceneManager = pOrigin->GetSceneManager();
	pBoundary = new BoundingBox(0,0,1024,768);
	pCellSpacePartition = new CellSpacePartition<GameEntity*>(1024, 768, 4, 4, 1000);
	this->initScene();
}

Game::~Game(void)
{
	delete pOrigin;
	delete pBoundary;
	delete pCellSpacePartition;
	delete pPlayer;
	delete pSight;
	for(std::vector<GameEntity*>::iterator cursor = pGameEntities.begin(); cursor != pGameEntities.end(); cursor++)
		delete *cursor;
	for(std::map<EntityType, Texture*>::iterator cursor = pTextures.begin(); cursor != pTextures.end(); cursor++)
		delete (*cursor).second;
}

void Game::UpdateAllGameEntities(const float &deltaTime)
{
	//在每个元素Update的时候,可能导致数组容量增加并使迭代器失效,所以必须使用索引值
	//Update过程中新+进数组的元素不需要更新，所以从后往前遍历数组
	for(int cursor = int(pGameEntities.size()) - 1; cursor > -1; cursor--)
	{
		if(pGameEntities[cursor]->isAlive == true)
		{
			Vector2D oldPosition(pGameEntities[cursor]->Pos());
			pGameEntities[cursor]->Update(deltaTime);	//如果是子弹有可能已经击中物体并且被回收、可能会改变数组大小
			if(pGameEntities[cursor]->isAlive == true)		//被回收的子弹不可以Update
				pCellSpacePartition->UpdateEntity(pGameEntities[cursor], oldPosition);					//更新空间划分
		}
	}
}

void Game::RecycleAAliveEntity(GameEntity *pAliveEntity, const EntityType &entityType)
{
	pAliveEntity->pAttachedSceneNode->DetachSceneEntity();
	pCellSpacePartition->DeleteEntity(pAliveEntity);		//删除的必须是位置正确的物体
	pAliveEntity->isAlive = false;
	
 	pSceneManager->GetAUseablePSys(&D3DXVECTOR2(pAliveEntity->GetPosition()));
	switch(entityType)
	{
	case whiteplayer :
		break;
	case yellowshot :
		pDiedBulletEntities.insert((BulletEntity*)pAliveEntity);
		break;
	case sight :
		break;
	case pinkpinwheel :
		pDiedFanEntities.insert((FanEntity*)pAliveEntity);
		break;
	case bluediamond :
		pDiedBluediamondEntities.insert((BluediamondEntity*)pAliveEntity);
		break;
	case greensquare :
		pDiedGreensquareEntities.insert((GreensquareEntity*)pAliveEntity);
		break;
	case indigotriangle :
		pDiedIndigotriangleEntities.insert((IndigotriangleEntity*)pAliveEntity);
		break;
	case bluecircle :
		pDiedBluecircleEntities.insert((BluecircleEntity*)pAliveEntity);
		break;
	case orangetriangle :
		pDiedOrangetriangleEntities.insert((OrangetriangleEntity*)pAliveEntity);
		break;
	case purplesquare1 :
		pDiedPurplesquare1Entities.insert((Purplesquare1Entity*)pAliveEntity);
		for(int i = 0; i < 2; i++)
			this->GetAAliveEntity(purplesquare2, pAliveEntity->Pos(),
			Vector2D((rand() * 2.0) / RAND_MAX - 1.0, (rand() * 2.0) / RAND_MAX - 1.0).Normalize());
		break;
	case purplesquare2 :
		pDiedPurplesquare2Entities.insert((Purplesquare2Entity*)pAliveEntity);
		break;
	case redcircle :
		pDiedRedcircleEntities.insert((RedcircleEntity*)pAliveEntity);
		break;
	case redclone :
		pDiedRedcloneEntities.insert((RedcloneEntity*)pAliveEntity);
		break;

	default :
		assert(false);
		break;
	}

	//测试用
	tempTest();
}

void Game::tempTest()
{
	if(pDiedFanEntities.size() > 5)
	{
		for(int i = 0; i < 5; i++)
		{
			this->GetAAliveEntity(pinkpinwheel,
				Vector2D((rand() * (pBoundary->BottomRight.x - pBoundary->TopLeft.x)) / RAND_MAX + pBoundary->TopLeft.x,
				(rand() * (pBoundary->BottomRight.y - pBoundary->TopLeft.y)) / RAND_MAX + pBoundary->TopLeft.y),
				Vector2D((rand() * 2.0) / RAND_MAX - 1.0, (rand() * 2.0) / RAND_MAX - 1.0).Normalize());
		}
		this->pPlayer->barrelNum++;
		if(this->pPlayer->barrelNum == 6)
			this->pPlayer->barrelNum = 1;
	}
	if(pDiedBluediamondEntities.size() > 5)
	{
		for(int i = 0; i < 5; i++)
		{
			this->GetAAliveEntity(bluediamond,
				Vector2D((rand() * (pBoundary->BottomRight.x - pBoundary->TopLeft.x)) / RAND_MAX + pBoundary->TopLeft.x,
				(rand() * (pBoundary->BottomRight.y - pBoundary->TopLeft.y)) / RAND_MAX + pBoundary->TopLeft.y));
		}
	}
	if(pDiedGreensquareEntities.size() > 5)
	{
		for(int i = 0; i < 5; i++)
		{
			this->GetAAliveEntity(greensquare,
				Vector2D((rand() * (pBoundary->BottomRight.x - pBoundary->TopLeft.x)) / RAND_MAX + pBoundary->TopLeft.x,
				(rand() * (pBoundary->BottomRight.y - pBoundary->TopLeft.y)) / RAND_MAX + pBoundary->TopLeft.y),
				Vector2D((rand() * 2.0) / RAND_MAX - 1.0, (rand() * 2.0) / RAND_MAX - 1.0).Normalize());
		}
	}
	if(pDiedPurplesquare1Entities.size() > 5)
	{
		for(int i = 0; i < 5; i++)
		{
			this->GetAAliveEntity(purplesquare1,
				Vector2D((rand() * (pBoundary->BottomRight.x - pBoundary->TopLeft.x)) / RAND_MAX + pBoundary->TopLeft.x,
				(rand() * (pBoundary->BottomRight.y - pBoundary->TopLeft.y)) / RAND_MAX + pBoundary->TopLeft.y),
				Vector2D((rand() * 2.0) / RAND_MAX - 1.0, (rand() * 2.0) / RAND_MAX - 1.0).Normalize());
		}
	}
}

const BoundingBox&  Game::GetBoundary()
{
	return *(this->pBoundary);
}

void Game::AddGameListener(GameListener *pGameListener)
{
	this->pOrigin->AddWindowsListener(pGameListener);
	pGameListener->pGame = this;
}

void Game::Go()
{
	this->pOrigin->StartRendering();
}

MovingEntity* Game::GetAAliveEntity(const EntityType &entityType, const Vector2D &position, const Vector2D &directionVector)
{
	assert(fabs(1.0 - directionVector.Length()) < 0.1);
	MovingEntity* pMovingEntity = NULL;
	switch(entityType)
	{
	case whiteplayer :
		break;
	case yellowshot :
		if(pDiedBulletEntities.size() > 0)
		{
			pMovingEntity = *(pDiedBulletEntities.begin());
			pDiedBulletEntities.erase(pDiedBulletEntities.begin());
			pMovingEntity->ResetPosition_Direction(D3DXVECTOR2(float(position.x), float(position.y)), directionVector);
			pMovingEntity->resetAngle();						//方向改变,重新设置角度
			pMovingEntity->resetVelocityVector();		//方向改变,重新设置速度向量
		}
		else
		{
			pMovingEntity = new BulletEntity(this, position, directionVector);
			pMovingEntity->AttachTexture(pTextures[yellowshot]);
			pGameEntities.push_back(pMovingEntity);
		}
		break;
	case sight :
		break;
	case pinkpinwheel :
		if(pDiedFanEntities.size() > 0)
		{
			pMovingEntity = *(pDiedFanEntities.begin());
			pDiedFanEntities.erase(pDiedFanEntities.begin());
			pMovingEntity->ResetPosition_Direction(D3DXVECTOR2(float(position.x), float(position.y)), directionVector);
			pMovingEntity->resetVelocityVector();		//方向改变,重新设置速度向量
		}
		else
		{
			pMovingEntity = new FanEntity(this, position, directionVector);
			pMovingEntity->AttachTexture(pTextures[pinkpinwheel]);
			pGameEntities.push_back(pMovingEntity);
		}
		break;
	case bluediamond :
		if(pDiedBluediamondEntities.size() > 0)
		{
			pMovingEntity = *(pDiedBluediamondEntities.begin());
			pDiedBluediamondEntities.erase(pDiedBluediamondEntities.begin());
			pMovingEntity->ResetPosition_Direction(D3DXVECTOR2(float(position.x), float(position.y)));
		}
		else
		{
			pMovingEntity = new BluediamondEntity(this, position);
			pMovingEntity->AttachTexture(pTextures[bluediamond]);
			pGameEntities.push_back(pMovingEntity);
		}
		break;
	case greensquare :
		if(pDiedGreensquareEntities.size() > 0)
		{
			pMovingEntity = *(pDiedGreensquareEntities.begin());
			pDiedGreensquareEntities.erase(pDiedGreensquareEntities.begin());
			pMovingEntity->ResetPosition_Direction(D3DXVECTOR2(float(position.x), float(position.y)), directionVector);
			pMovingEntity->resetAngle();						//方向改变,重新设置角度
		}
		else
		{
			pMovingEntity = new GreensquareEntity(this, position, directionVector);
			pMovingEntity->AttachTexture(pTextures[greensquare]);
			pGameEntities.push_back(pMovingEntity);
		}
		break;
	case indigotriangle :
		break;
	case bluecircle :
		break;
	case orangetriangle :
		break;
	case purplesquare1 :
		if(pDiedPurplesquare1Entities.size() > 0)
		{
			pMovingEntity = *(pDiedPurplesquare1Entities.begin());
			pDiedPurplesquare1Entities.erase(pDiedPurplesquare1Entities.begin());
			pMovingEntity->ResetPosition_Direction(D3DXVECTOR2(float(position.x), float(position.y)), directionVector);
			pMovingEntity->resetAngle();						//方向改变,重新设置角度
		}
		else
		{
			pMovingEntity = new Purplesquare1Entity(this, position, directionVector);
			pMovingEntity->AttachTexture(pTextures[purplesquare1]);
			pGameEntities.push_back(pMovingEntity);
		}
		break;
	case purplesquare2 :
		if(pDiedPurplesquare2Entities.size() > 0)
		{
			pMovingEntity = *(pDiedPurplesquare2Entities.begin());
			pDiedPurplesquare2Entities.erase(pDiedPurplesquare2Entities.begin());
			pMovingEntity->ResetPosition_Direction(D3DXVECTOR2(float(position.x), float(position.y)), directionVector);
			pMovingEntity->resetAngle();						//方向改变,重新设置角度
		}
		else
		{
			pMovingEntity = new Purplesquare2Entity(this, position, directionVector);
			pMovingEntity->AttachTexture(pTextures[purplesquare2]);
			pGameEntities.push_back(pMovingEntity);
		}
		break;
	case redcircle :
		break;
	case redclone :
		break;

	default :
		assert(false);
		break;
	}
	pMovingEntity->isAlive = true;
	pCellSpacePartition->AddEntity(pMovingEntity);
	pSceneManager->GetAUseableSceneNode()->AttachSceneEntity(pMovingEntity);

	return pMovingEntity;
}
