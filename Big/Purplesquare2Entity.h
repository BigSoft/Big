#pragma once
#include "movingentity.h"

class Purplesquare2Entity :
	public MovingEntity
{
private:
	Vector2D publicCenter;			//公转中心
	float publicRadius;					//公转半径
	float publicAngular;				//公转角速度
	float publicAngle;					//公转角度

public:

private:

public:
	Purplesquare2Entity(Game* pGame, const Vector2D& centerPosition, const Vector2D& directionVector, float mBoundary = 5.0f, float mMaxSpeed = 0.1f, EntityType mEntityType = purplesquare2);
	virtual void Update(const float& deltaTime);
	virtual void ResetPosition_Direction(const D3DXVECTOR2& newPosition, const Vector2D& newDirection);
};
