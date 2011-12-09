#pragma once
#include "manipulatingentity.h"

class SightEntity :
	public ManipulatingEntity
{
private:
	float m_Angular;			//旋转角速度

public:

private:

public:
	SightEntity(Game* pGame, const Vector2D& mPosition, const Vector2D& directionVector = Vector2D(0.0, -1.0), float mBoundary = 0.0f, float mMaxSpeed = 0.45f, EntityType mEntityType = sight);
	
	//更新当前对象
	virtual void Update(const float& deltaTime);
};
