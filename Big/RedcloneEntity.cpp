#include "RedcloneEntity.h"

RedcloneEntity::RedcloneEntity(Game *pGame, const Vector2D &mPosition, const Vector2D &directionVector, float mBoundary, float mMaxSpeed, EntityType mEntityType)
: MovingEntity(pGame, mPosition, directionVector, mBoundary, mMaxSpeed, mEntityType)
{
}

void RedcloneEntity::Update(const float &deltaTime)
{
}
