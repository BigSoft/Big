#include "ManipulatingEntity.h"

#include "Game.h"
#include "BigBoundingGeometry.h"

ManipulatingEntity::ManipulatingEntity(Game *pGame, const Vector2D &mPosition, const Vector2D &directionVector, float mBoundary, float mMaxSpeed, EntityType mEntityType)
: GameEntity(pGame, mPosition, directionVector, mBoundary, mMaxSpeed, mEntityType)
{
}

void ManipulatingEntity::MoveUp(const float &deltaTime)
{
	this->mAngle = 0.0f;
	this->mPosition += D3DXVECTOR2(0.0f, -this->m_MaxSpeed * deltaTime);
	if(mPosition.y - m_Boundary < this->m_pGame->GetBoundary().TopLeft.y)
		mPosition.y = this->m_pGame->GetBoundary().TopLeft.y + m_Boundary;
}

void ManipulatingEntity::MoveDown(const float &deltaTime)
{
	this->mAngle = PAI;
	this->mPosition += D3DXVECTOR2(0.0f, m_MaxSpeed * deltaTime);
	if(mPosition.y + m_Boundary > this->m_pGame->GetBoundary().BottomRight.y)
		mPosition.y = this->m_pGame->GetBoundary().BottomRight.y - m_Boundary;
}

void ManipulatingEntity::MoveLeft(const float &deltaTime)
{
	this->mAngle = PAI * 1.5f;
	this->mPosition += D3DXVECTOR2(-m_MaxSpeed * deltaTime, 0.0f);
	if(mPosition.x - m_Boundary < this->m_pGame->GetBoundary().TopLeft.x)
		mPosition.x = this->m_pGame->GetBoundary().TopLeft.x + m_Boundary;
}

void ManipulatingEntity::MoveRight(const float &deltaTime)
{
	this->mAngle = PAI * 0.5f;
	this->mPosition += D3DXVECTOR2(m_MaxSpeed * deltaTime, 0.0f);
	if(mPosition.x + m_Boundary > this->m_pGame->GetBoundary().BottomRight.x)
		mPosition.x = this->m_pGame->GetBoundary().BottomRight.x - m_Boundary;
}
