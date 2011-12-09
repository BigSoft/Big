#pragma once
#include "gameentity.h"

class ManipulatingEntity :
	public GameEntity
{
private:

public:

protected:

private:

public:
	//
	ManipulatingEntity(Game* pGame, const Vector2D& mPosition, const Vector2D& directionVector, float mBoundary, float mMaxSpeed, EntityType mEntityType);
	
	//向上移动
	virtual void MoveUp(const float& deltaTime);

	//向下移动
	virtual void MoveDown(const float& deltaTime);

	//向左移动
	virtual void MoveLeft(const float& deltaTime);

	//向右移动
	virtual void MoveRight(const float& deltaTime);
};
