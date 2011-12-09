#pragma once
#include "bigsceneentity.h"
#include "Vector2D.h"

class Game;
struct Vector2D;

enum EntityType { whiteplayer, yellowshot, sight,
									pinkpinwheel, bluediamond, greensquare,
										indigotriangle, bluecircle, orangetriangle,
											purplesquare1, purplesquare2, redcircle, redclone};

class GameEntity :
	public SceneEntity
{
private:

public:
	bool isAlive;									//是否活着
	float m_Boundary;							//圆形边界检测半径
	EntityType m_EntityType;				//实体类型

protected:
	Game* m_pGame;							//当前游戏
	Vector2D m_DirectionVector;		//方向向量,单位向量
	float m_MaxSpeed;							//最大速度值

private:

public:
	//
	GameEntity(Game* pGame, const Vector2D& mPosition, const Vector2D& directionVector, float mBoundary, float mMaxSpeed, EntityType mEntityType);

	//当前位置
	Vector2D Pos();

	//更新当前对象
	virtual void Update(const float& deltaTime) { }

	//根据方向设置角度
	void resetAngle();

protected:
};
