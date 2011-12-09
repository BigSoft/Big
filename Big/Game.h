#pragma once

#include "windows.h"
#include <vector>
#include <map>
#include <set>

#include "Big.h"
#include "CellSpacePartition.h"

class BoundingBox;
class GameListener;

enum EntityType;
class GameEntity;
class PlayerEntity;
class SightEntity;

class MovingEntity;
class BulletEntity;
class FanEntity;
class BluediamondEntity;
class GreensquareEntity;
class Purplesquare1Entity;
class Purplesquare2Entity;
class IndigotriangleEntity;
class BluecircleEntity;
class OrangetriangleEntity;
class RedcircleEntity;
class RedcloneEntity;

class Game
{
private:
	Origin* pOrigin;																					//���𴴽����ڣ�����
	BoundingBox* pBoundary;																	//��Ϸ�����С
	SceneManager* pSceneManager;														//����������
	std::vector<GameEntity*> pGameEntities;											//��Ϸ�е�����
	std::map<EntityType, Texture*> pTextures;										//��Ϸ�еĲ���
	std::set<BulletEntity*> pDiedBulletEntities;										//�����յ��ӵ�
	std::set<FanEntity*> pDiedFanEntities;												//�����յķ��ȼ�����
	std::set<BluediamondEntity*> pDiedBluediamondEntities;				//�����յ������μ�����
	std::set<GreensquareEntity*> pDiedGreensquareEntities;					//�����յ��̷���
	std::set<Purplesquare1Entity*> pDiedPurplesquare1Entities;			//�����յĴ�۷���
	std::set<Purplesquare2Entity*> pDiedPurplesquare2Entities;			//�����յ�С�۷���
	std::set<IndigotriangleEntity*> pDiedIndigotriangleEntities;			//�����յĽ���������
	std::set<BluecircleEntity*> pDiedBluecircleEntities;						//�����յ���ɫԲ��
	std::set<OrangetriangleEntity*> pDiedOrangetriangleEntities;		//�����յĳ�ɫ������
	std::set<RedcircleEntity*> pDiedRedcircleEntities;							//�����յĺڶ�
	std::set<RedcloneEntity*> pDiedRedcloneEntities;							//�����յĴ����
	
public:
	CellSpacePartition<GameEntity*>* pCellSpacePartition;			//�ռ仮��
	PlayerEntity* pPlayer;																//��ҷɴ�
	SightEntity* pSight;																	//��׼��
	int fireBufferTime;																		//�ӵ����仺��ʱ��

private:
	void initScene();

public:
	//
	Game(HINSTANCE _hInstance, int nCmdShow);

	//
	~Game(void);

	//�ƶ������л��ŵ��ӵ��ͼ�����
	void UpdateAllGameEntities(const float& deltaTime);

	//�����Ϸ����߽�
	const BoundingBox& GetBoundary();

	//�����Ϸ������
	void AddGameListener(GameListener* pGameListener);

	//��Ϸ����
	void Go();

	//���ձ����л�����ԭ������ĳ���ʵ��
	void RecycleAAliveEntity(GameEntity* pAliveEntity, const EntityType& entityType);

	//���һ�����õļ�����
	MovingEntity* GetAAliveEntity(const EntityType& entityType, const Vector2D& position, const Vector2D& directionVector = Vector2D(0.0, -1.0));

	//--------------------------------������,����ʱɾ��
	void tempTest();
};
