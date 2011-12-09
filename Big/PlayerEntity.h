#pragma once
#include "ManipulatingEntity.h"

class PlayerEntity :
	public ManipulatingEntity
{
private:

public:
	int barrelNum;				//枪筒数量

private:

public:
	PlayerEntity(Game* pGame, const Vector2D& mPosition, const Vector2D& directionVector = Vector2D(0.0, -1.0), float mBoundary = 32.0f, float mMaxSpeed = 0.35f, EntityType mEntityType = whiteplayer);
	void Fire();
};
