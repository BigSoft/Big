#include "FanEntity.h"

#include "Vector2D.h"
#include "BigBoundingGeometry.h"
#include "Game.h"
#include "EntityFunctionTemplates.h"

FanEntity::FanEntity(Game *pGame, const Vector2D &mPosition, const Vector2D &directionVector, float mBoundary, float mMaxSpeed, EntityType mEntityType)
: MovingEntity(pGame, mPosition, directionVector, mBoundary, mMaxSpeed, mEntityType)
{
	this->m_Angular = 0.005f;
}

void FanEntity::Update(const float &deltaTime)
{
	this->mAngle += m_Angular * deltaTime;
	this->mAngle = float((int(this->mAngle * 100000) % int(2 * PAI * 100000)) / 100000.0);

	this->mPosition.x += float(this->mVelocityVector.x) * deltaTime;
	this->mPosition.y += float(mVelocityVector.y) * deltaTime;
	
	EnforceNonPenetrationConstraint((GameEntity*)this, m_pGame->pCellSpacePartition);		//确保几何体之间无重叠
	if(mPosition.y - m_Boundary < this->m_pGame->GetBoundary().TopLeft.y)
	{
		mPosition.y = this->m_pGame->GetBoundary().TopLeft.y + m_Boundary;
		mVelocityVector.y = -mVelocityVector.y;
	}
	if(mPosition.y + m_Boundary > this->m_pGame->GetBoundary().BottomRight.y)
	{
		mPosition.y = this->m_pGame->GetBoundary().BottomRight.y - m_Boundary;
		mVelocityVector.y = -mVelocityVector.y;
	}
	if(mPosition.x - m_Boundary < this->m_pGame->GetBoundary().TopLeft.x)
	{
		mPosition.x = this->m_pGame->GetBoundary().TopLeft.x + m_Boundary;
		mVelocityVector.x = -mVelocityVector.x;
	}
	if(mPosition.x + m_Boundary > this->m_pGame->GetBoundary().BottomRight.x)
	{
		mPosition.x = this->m_pGame->GetBoundary().BottomRight.x - m_Boundary;
		mVelocityVector.x = -mVelocityVector.x;
	}

}
