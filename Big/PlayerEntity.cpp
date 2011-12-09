#include "PlayerEntity.h"

#include "SightEntity.h"
#include "Vector2D.h"
#include "Game.h"

PlayerEntity::PlayerEntity(Game *pGame, const Vector2D &mPosition, const Vector2D &directionVector, float mBoundary, float mMaxSpeed, EntityType mEntityType)
: ManipulatingEntity(pGame, mPosition, directionVector, mBoundary, mMaxSpeed, mEntityType)
{
	barrelNum = 1;
}

void PlayerEntity::Fire()
{
	Vector2D directionVelocity = m_pGame->pSight->Pos() - this->Pos();

	if(directionVelocity.Length() == 0)		//�ɴ���׼���ص�ʲôҲ����
		return;

	//((barrelNum -1)/2)*((10*PAI)/180)
	double BulletAngle = ((barrelNum  - 1) * PAI) / 36.0;
	directionVelocity.Normalize();		//��������Ϊ��λ����
	for(int i = 0; i < barrelNum; i++)
	{
		m_pGame->GetAAliveEntity(yellowshot, this->Pos(), Vector2D(directionVelocity.x * cos(BulletAngle) + directionVelocity.y * sin(BulletAngle),
			directionVelocity.y * cos(BulletAngle) - directionVelocity.x * sin(BulletAngle)));
		BulletAngle -= PAI / 18.0;		//��ȥ10�ȶ�Ӧ�Ĺ¶���С
	}
}

