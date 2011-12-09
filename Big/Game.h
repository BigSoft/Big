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
	Origin* pOrigin;																					//负责创建窗口，画画
	BoundingBox* pBoundary;																	//游戏界面大小
	SceneManager* pSceneManager;														//场景管理器
	std::vector<GameEntity*> pGameEntities;											//游戏中的物体
	std::map<EntityType, Texture*> pTextures;										//游戏中的材质
	std::set<BulletEntity*> pDiedBulletEntities;										//被回收的子弹
	std::set<FanEntity*> pDiedFanEntities;												//被回收的风扇几何体
	std::set<BluediamondEntity*> pDiedBluediamondEntities;				//被回收的蓝菱形几何体
	std::set<GreensquareEntity*> pDiedGreensquareEntities;					//被回收的绿方格
	std::set<Purplesquare1Entity*> pDiedPurplesquare1Entities;			//被回收的大粉方格
	std::set<Purplesquare2Entity*> pDiedPurplesquare2Entities;			//被回收的小粉方格
	std::set<IndigotriangleEntity*> pDiedIndigotriangleEntities;			//被回收的交叉三角形
	std::set<BluecircleEntity*> pDiedBluecircleEntities;						//被回收的蓝色圆形
	std::set<OrangetriangleEntity*> pDiedOrangetriangleEntities;		//被回收的橙色三角形
	std::set<RedcircleEntity*> pDiedRedcircleEntities;							//被回收的黑洞
	std::set<RedcloneEntity*> pDiedRedcloneEntities;							//被回收的大磁铁
	
public:
	CellSpacePartition<GameEntity*>* pCellSpacePartition;			//空间划分
	PlayerEntity* pPlayer;																//玩家飞船
	SightEntity* pSight;																	//瞄准星
	int fireBufferTime;																		//子弹发射缓冲时间

private:
	void initScene();

public:
	//
	Game(HINSTANCE _hInstance, int nCmdShow);

	//
	~Game(void);

	//移动场景中活着的子弹和几何体
	void UpdateAllGameEntities(const float& deltaTime);

	//获得游戏界面边界
	const BoundingBox& GetBoundary();

	//添加游戏监听者
	void AddGameListener(GameListener* pGameListener);

	//游戏运行
	void Go();

	//回收被击中或其他原因被消灭的场景实体
	void RecycleAAliveEntity(GameEntity* pAliveEntity, const EntityType& entityType);

	//获得一个可用的几何体
	MovingEntity* GetAAliveEntity(const EntityType& entityType, const Vector2D& position, const Vector2D& directionVector = Vector2D(0.0, -1.0));

	//--------------------------------测试用,发布时删掉
	void tempTest();
};
