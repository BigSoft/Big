#include "GreensquareEntity.h"

#include "Vector2D.h"
#include "Game.h"
#include "PlayerEntity.h"
#include "SightEntity.h"
#include "BigBoundingGeometry.h"
#include "EntityFunctionTemplates.h"

GreensquareEntity::GreensquareEntity(Game *pGame, const Vector2D &mPosition, const Vector2D &directionVector, float mBoundary, float mMaxSpeed, EntityType mEntityType)
: MovingEntity(pGame, mPosition, directionVector, mBoundary, mMaxSpeed, mEntityType, -0.002f)
{
	this->resetAngle();
}

void GreensquareEntity::Update(const float &deltaTime)
{
	this->mAngle += m_Angular * deltaTime;
	if(mAngle < 0)
		this->mAngle += PAI * 2.0f;

	Vector2D playerHeading = (m_pGame->pSight->Pos() - m_pGame->pPlayer->Pos()).Normalize();
	this->m_DirectionVector = (this->m_pGame->pPlayer->Pos() - this->Pos()).Normalize();

	double deltaAngle = m_DirectionVector.Dot(playerHeading);
	if(deltaAngle < 0 && (PAI - acos(deltaAngle)) < (PAI /6))
	{
		this->m_DirectionVector = -(playerHeading + m_DirectionVector);
		m_DirectionVector.Normalize();
	}

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
