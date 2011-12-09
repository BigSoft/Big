#pragma once
#include "gameentity.h"


class MovingEntity :
	public GameEntity
{
private:

public:

protected:
	Vector2D mVelocityVector;		//�ٶ�����
	float m_Angular;			//��ת���ٶ�

private:

public:
	//
	MovingEntity(Game* pGame, const Vector2D& mPosition, const Vector2D& directionVector, float mBoundary, float mMaxSpeed, EntityType mEntityType, float mAngular = 0.0f);

	//��������λ�úͷ���(�����ٶ�)
	virtual void ResetPosition_Direction(const D3DXVECTOR2& newPosition, const Vector2D& newDirection = Vector2D(0.0, -1.0));

	//���µ�ǰ�ӵ�
	virtual void Update(const float& deltaTime) { }

	//�����ӵ����������ӵ��ٶ�
	void resetVelocityVector();
};
