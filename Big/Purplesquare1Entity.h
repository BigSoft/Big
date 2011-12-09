#pragma once
#include "movingentity.h"

class Purplesquare1Entity :
	public MovingEntity
{
private:

public:

private:

public:
	Purplesquare1Entity(Game* pGame, const Vector2D& mPosition, const Vector2D& directionVector, float mBoundary = 32.0f, float mMaxSpeed = 0.1f, EntityType mEntityType = purplesquare1);
	virtual void Update(const float& deltaTime);
};
