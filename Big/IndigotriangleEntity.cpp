#include "IndigotriangleEntity.h"

IndigotriangleEntity::IndigotriangleEntity(Game *pGame, const Vector2D &mPosition, const Vector2D &directionVector, float mBoundary, float mMaxSpeed, EntityType mEntityType)
: MovingEntity(pGame, mPosition, directionVector, mBoundary, mMaxSpeed, mEntityType, 0.003f)
{
}

void IndigotriangleEntity::Update(const float &deltaTime)
{
}
