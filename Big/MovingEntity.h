#pragma once
#include "gameentity.h"


class MovingEntity :
	public GameEntity
{
private:

public:

protected:
	Vector2D mVelocityVector;		//速度向量
	float m_Angular;			//旋转角速度

private:

public:
	//
	MovingEntity(Game* pGame, const Vector2D& mPosition, const Vector2D& directionVector, float mBoundary, float mMaxSpeed, EntityType mEntityType, float mAngular = 0.0f);

	//重新设置位置和方向(包括速度)
	virtual void ResetPosition_Direction(const D3DXVECTOR2& newPosition, const Vector2D& newDirection = Vector2D(0.0, -1.0));

	//更新当前子弹
	virtual void Update(const float& deltaTime) { }

	//根据子弹方向设置子弹速度
	void resetVelocityVector();
};
