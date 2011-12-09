#pragma once
#include "MovingEntity.h"

class FanEntity :
	public MovingEntity
{
private:

public:

private:

public:
	FanEntity(Game* pGame, const Vector2D& mPosition, const Vector2D& directionVector, float mBoundary = 32.0f, float mMaxSpeed = 0.065f, EntityType mEntityType = pinkpinwheel);
	virtual void Update(const float& deltaTime);
};
