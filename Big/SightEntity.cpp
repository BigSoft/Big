#include "SightEntity.h"

SightEntity::SightEntity(Game *pGame, const Vector2D &mPosition, const Vector2D &directionVector, float mBoundary, float mMaxSpeed, EntityType mEntityType)
: ManipulatingEntity(pGame, mPosition, directionVector, mBoundary, mMaxSpeed, mEntityType)
{
	m_Angular = 0.002f;
}

void SightEntity::Update(const float &deltaTime)
{
}
