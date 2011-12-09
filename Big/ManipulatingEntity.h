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
	
	//�����ƶ�
	virtual void MoveUp(const float& deltaTime);

	//�����ƶ�
	virtual void MoveDown(const float& deltaTime);

	//�����ƶ�
	virtual void MoveLeft(const float& deltaTime);

	//�����ƶ�
	virtual void MoveRight(const float& deltaTime);
};
