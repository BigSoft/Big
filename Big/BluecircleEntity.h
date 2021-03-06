#pragma once
#include "movingentity.h"

class BluecircleEntity :
	public MovingEntity
{
private:

public:

private:

public:
	BluecircleEntity(Game* pGame, const Vector2D& mPosition, const Vector2D& directionVector, float mBoundary = 10.0f, float mMaxSpeed = 0.4f, EntityType mEntityType = bluecircle);
	virtual void Update(const float& deltaTime);
};
