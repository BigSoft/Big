#pragma once
#include "movingentity.h"

class OrangetriangleEntity :
	public MovingEntity
{
private:

public:

private:

public:
	OrangetriangleEntity(Game* pGame, const Vector2D& mPosition, const Vector2D& directionVector, float mBoundary = 16.0f, float mMaxSpeed = 0.1f, EntityType mEntityType = orangetriangle);
	virtual void Update(const float& deltaTime);
};
