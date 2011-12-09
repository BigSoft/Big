#include "MovingEntity.h"

MovingEntity::MovingEntity(Game *pGame, const Vector2D &mPosition, const Vector2D &directionVector, float mBoundary, float mMaxSpeed, EntityType mEntityType, float mAngular)
: GameEntity(pGame, mPosition, directionVector, mBoundary, mMaxSpeed, mEntityType)
{
	this->resetVelocityVector();		//设置速度向量
	this->m_Angular = mAngular;	//旋转角度
}

void MovingEntity::resetVelocityVector()
{
	assert(fabs(1.0 - this->m_DirectionVector.Length()) < 0.1);
	this->mVelocityVector.x = m_DirectionVector.x * this->m_MaxSpeed;
	mVelocityVector.y = m_DirectionVector.y * m_MaxSpeed;
}

void MovingEntity::ResetPosition_Direction(const D3DXVECTOR2 &newPosition, const Vector2D &newDirection)
{
	assert(fabs(1.0 - newDirection.Length()) < 0.1);
	this->mPosition = newPosition;
	this->m_DirectionVector = newDirection;
}
