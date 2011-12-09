#include "Purplesquare1Entity.h"

#include "Vector2D.h"
#include "Game.h"
#include "PlayerEntity.h"
#include "BigBoundingGeometry.h"
#include "EntityFunctionTemplates.h"

Purplesquare1Entity::Purplesquare1Entity(Game *pGame, const Vector2D &mPosition, const Vector2D &directionVector, float mBoundary, float mMaxSpeed, EntityType mEntityType)
: MovingEntity(pGame, mPosition, directionVector, mBoundary, mMaxSpeed, mEntityType, 0.002f)
{
	this->resetAngle();
}

void Purplesquare1Entity::Update(const float &deltaTime)
{
	this->mAngle += m_Angular * deltaTime;
	this->mAngle = float((int(this->mAngle * 100000) % int(2 * PAI * 100000)) / 100000.0);

	this->m_DirectionVector = (this->m_pGame->pPlayer->Pos() - this->Pos()).Normalize();
	this->mVelocityVector = m_DirectionVector * this->m_MaxSpeed;
	this->mPosition.x += float(mVelocityVector.x) * deltaTime;
	this->mPosition.y += float(mVelocityVector.y) * deltaTime;

	EnforceNonPenetrationConstraint((GameEntity*)this, m_pGame->pCellSpacePartition);		//ȷ��������֮�����ص�
	if(mPosition.y - m_Boundary < this->m_pGame->GetBoundary().TopLeft.y)
		mPosition.y = this->m_pGame->GetBoundary().TopLeft.y + m_Boundary;
	if(mPosition.y + m_Boundary > this->m_pGame->GetBoundary().BottomRight.y)
		mPosition.y = this->m_pGame->GetBoundary().BottomRight.y - m_Boundary;
	if(mPosition.x - m_Boundary < this->m_pGame->GetBoundary().TopLeft.x)
		mPosition.x = this->m_pGame->GetBoundary().TopLeft.x + m_Boundary;
	if(mPosition.x + m_Boundary > this->m_pGame->GetBoundary().BottomRight.x)
		mPosition.x = this->m_pGame->GetBoundary().BottomRight.x - m_Boundary;
}
