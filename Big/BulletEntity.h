#pragma once
#include "MovingEntity.h"


class BulletEntity :
	public MovingEntity
{
private:

public:

private:

public:
	//
	BulletEntity(Game* pGame, const Vector2D& mPosition, const Vector2D& directionVector, float mBoundary = 10.0f, float mMaxSpeed = 0.5f, EntityType mEntityType = yellowshot);

	//���µ�ǰ�ӵ�
	virtual void Update(const float& deltaTime);
};
