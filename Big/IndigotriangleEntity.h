#pragma once
#include "movingentity.h"

class IndigotriangleEntity :
	public MovingEntity
{
private:

public:

private:

public:
	IndigotriangleEntity(Game* pGame, const Vector2D& mPosition, const Vector2D& directionVector, float mBoundary = 10.0f, float mMaxSpeed = 0.4f, EntityType mEntityType = indigotriangle);
	virtual void Update(const float& deltaTime);
};
