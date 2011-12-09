#pragma once
#include "movingentity.h"

class Purplesquare2Entity :
	public MovingEntity
{
private:
	Vector2D publicCenter;			//��ת����
	float publicRadius;					//��ת�뾶
	float publicAngular;				//��ת���ٶ�
	float publicAngle;					//��ת�Ƕ�

public:

private:

public:
	Purplesquare2Entity(Game* pGame, const Vector2D& centerPosition, const Vector2D& directionVector, float mBoundary = 5.0f, float mMaxSpeed = 0.1f, EntityType mEntityType = purplesquare2);
	virtual void Update(const float& deltaTime);
	virtual void ResetPosition_Direction(const D3DXVECTOR2& newPosition, const Vector2D& newDirection);
};
