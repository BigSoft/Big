#pragma once
#include "movingentity.h"

class RedcloneEntity :
	public MovingEntity
{
private:

public:

private:

public:
	RedcloneEntity(Game* pGame, const Vector2D& mPosition, const Vector2D& directionVector, float mBoundary = 32.0f, float mMaxSpeed = 0.5f, EntityType mEntityType = redclone);
	virtual void Update(const float& deltaTime);
};
