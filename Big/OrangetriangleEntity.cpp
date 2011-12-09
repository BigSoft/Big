#include "OrangetriangleEntity.h"

OrangetriangleEntity::OrangetriangleEntity(Game *pGame, const Vector2D &mPosition, const Vector2D &directionVector, float mBoundary, float mMaxSpeed, EntityType mEntityType)
: MovingEntity(pGame, mPosition, directionVector, mBoundary, mMaxSpeed, mEntityType, 0.001f)
{
}

void OrangetriangleEntity::Update(const float &deltaTime)
{
}
