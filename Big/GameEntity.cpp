#include "GameEntity.h"

#include "Big.h"

GameEntity::GameEntity(Game *pGame, const Vector2D &mPosition, const Vector2D &directionVector, float mBoundary, float mMaxSpeed, EntityType mEntityType)
: SceneEntity(0.0f, D3DXVECTOR2(float(mPosition.x), float(mPosition.y))), m_pGame(pGame),
  m_Boundary(mBoundary), m_MaxSpeed(mMaxSpeed),
  m_EntityType(mEntityType)
{
	assert(fabs(1.0 - directionVector.Length()) < 0.1);	//保证方向向量为单位向量
	m_DirectionVector = directionVector;
	resetAngle();

	isAlive = false;		//新实体在没放入场景之前都是死亡状态
}

Vector2D GameEntity::Pos()
{
	return Vector2D(this->mPosition.x, this->mPosition.y);
}

void GameEntity::resetAngle()
{
	float deltaAngle = float(atan(m_DirectionVector.y / m_DirectionVector.x));
	if(m_DirectionVector.x >= 0)
		this->mAngle = PAI * 0.5f + deltaAngle;
	else
		this->mAngle = PAI * 1.5f + deltaAngle;
}
