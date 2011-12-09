#include "BluediamondEntity.h"

#include "Vector2D.h"
#include "Game.h"
#include "PlayerEntity.h"
#include "BigBoundingGeometry.h"
#include "EntityFunctionTemplates.h"

BluediamondEntity::BluediamondEntity(Game *pGame, const Vector2D &mPosition, const Vector2D &directionVector, float mBoundary, float mMaxSpeed, EntityType mEntityType)
: MovingEntity(pGame, mPosition, directionVector, mBoundary, mMaxSpeed, mEntityType)
{
}

void BluediamondEntity::Update(const float &deltaTime)
{
	this->m_DirectionVector = (this->m_pGame->pPlayer->Pos() - this->Pos()).Normalize();
	this->mVelocityVector = m_DirectionVector * this->m_MaxSpeed;
	this->mPosition.x += float(mVelocityVector.x) * deltaTime;
	this->mPosition.y += float(mVelocityVector.y) * deltaTime;

	EnforceNonPenetrationConstraint((GameEntity*)this, m_pGame->pCellSpacePartition);		//确保几何体之间无重叠
	if(mPosition.y - m_Boundary < this->m_pGame->GetBoundary().TopLeft.y)
		mPosition.y = this->m_pGame->GetBoundary().TopLeft.y + m_Boundary;
	if(mPosition.y + m_Boundary > this->m_pGame->GetBoundary().BottomRight.y)
		mPosition.y = this->m_pGame->GetBoundary().BottomRight.y - m_Boundary;
	if(mPosition.x - m_Boundary < this->m_pGame->GetBoundary().TopLeft.x)
		mPosition.x = this->m_pGame->GetBoundary().TopLeft.x + m_Boundary;
	if(mPosition.x + m_Boundary > this->m_pGame->GetBoundary().BottomRight.x)
		mPosition.x = this->m_pGame->GetBoundary().BottomRight.x - m_Boundary;
}
