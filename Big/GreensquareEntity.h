#pragma once
#include "movingentity.h"

class GreensquareEntity :
	public MovingEntity
{
private:

public:

private:

public:
	GreensquareEntity(Game* pGame, const Vector2D& mPosition, const Vector2D& directionVector, float mBoundary = 32.0f, float mMaxSpeed = 0.1f, EntityType mEntityType = greensquare);
	virtual void Update(const float& deltaTime);
};
