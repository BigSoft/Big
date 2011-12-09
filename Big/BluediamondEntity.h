#pragma once
#include "movingentity.h"

class BluediamondEntity :
	public MovingEntity
{
private:

public:

private:

public:
	BluediamondEntity(Game* pGame, const Vector2D& mPosition, const Vector2D& directionVector = Vector2D(0.0, -1.0), float mBoundary = 32.0f, float mMaxSpeed = 0.1f, EntityType mEntityType = bluediamond);
	virtual void Update(const float& deltaTime);
};
