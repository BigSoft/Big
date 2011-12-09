#include "Purplesquare2Entity.h"

#include "Vector2D.h"
#include "Game.h"
#include "PlayerEntity.h"
#include "BigBoundingGeometry.h"
#include "EntityFunctionTemplates.h"

Purplesquare2Entity::Purplesquare2Entity(Game *pGame, const Vector2D &centerPosition, const Vector2D &directionVector, float mBoundary, float mMaxSpeed, EntityType mEntityType)
: MovingEntity(pGame, Vector2D(0, 0), directionVector, mBoundary, mMaxSpeed, mEntityType, -0.002f), publicCenter(centerPosition)
{
	this->resetAngle();
	publicRadius = 32.0f;
	publicAngular = 0.01f;
	publicAngle =float((rand() * 2.0 * PAI) / RAND_MAX);
	this->mPosition.x = float(publicCenter.x) + cos(publicAngle) * publicRadius;
	this->mPosition.y = float(publicCenter.y) + sin(publicAngle) * publicRadius;
}

void Purplesquare2Entity::Update(const float &deltaTime)
{
	//自转角度
	this->mAngle += m_Angular * deltaTime;
	if(mAngle < 0)
		this->mAngle += PAI * 2.0f;
	//公转角度
	this->publicAngle += publicAngular * deltaTime;
	this->publicAngle = float((int(this->publicAngle * 100000) % int(2 * PAI * 100000)) / 100000.0);

	//公转中心
	this->m_DirectionVector = (this->m_pGame->pPlayer->Pos() - publicCenter).Normalize();
	this->mVelocityVector = m_DirectionVector * this->m_MaxSpeed;
	this->publicCenter.x += float(mVelocityVector.x) * deltaTime;
	this->publicCenter.y += float(mVelocityVector.y) * deltaTime;
	
	this->mPosition.x = float(publicCenter.x) + cos(publicAngle) * publicRadius;
	this->mPosition.y = float(publicCenter.y) + sin(publicAngle) * publicRadius;

	EnforceNonPenetrationConstraint((GameEntity*)this, m_pGame->pCellSpacePartition);		//确保几何体之间无重叠
	if(publicCenter.y - publicRadius < this->m_pGame->GetBoundary().TopLeft.y)
		publicCenter.y = this->m_pGame->GetBoundary().TopLeft.y + publicRadius;
	if(publicCenter.y + publicRadius > this->m_pGame->GetBoundary().BottomRight.y)
		publicCenter.y = this->m_pGame->GetBoundary().BottomRight.y - publicRadius;
	if(publicCenter.x - publicRadius < this->m_pGame->GetBoundary().TopLeft.x)
		publicCenter.x = this->m_pGame->GetBoundary().TopLeft.x + publicRadius;
	if(publicCenter.x + publicRadius > this->m_pGame->GetBoundary().BottomRight.x)
		publicCenter.x = this->m_pGame->GetBoundary().BottomRight.x - publicRadius;
}

void Purplesquare2Entity::ResetPosition_Direction(const D3DXVECTOR2 &newPosition, const Vector2D &newDirection)
{
	assert(fabs(1.0 - newDirection.Length()) < 0.1);
	this->publicCenter.x = newPosition.x;
	this->publicCenter.y = newPosition.y;
	this->mPosition.x = float(publicCenter.x) + cos(publicAngle) * publicRadius;
	this->mPosition.y = float(publicCenter.y) + sin(publicAngle) * publicRadius;
	this->m_DirectionVector = newDirection;
}
