#pragma once
#include "movingentity.h"

class RedcircleEntity :
	public MovingEntity
{
private:

public:

private:

public:
	RedcircleEntity(Game* pGame, const Vector2D& mPosition, const Vector2D& directionVector, float mBoundary = 64.0f, float mMaxSpeed = 0.1f, EntityType mEntityType = redcircle);
	virtual void Update(const float& deltaTime);
};
