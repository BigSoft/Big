#include "BulletEntity.h"

#include "Game.h"
#include "BigBoundingGeometry.h"

BulletEntity::BulletEntity(Game *pGame, const Vector2D &mPosition, const Vector2D &directionVector, float mBoundary, float mMaxSpeed, EntityType mEntityType)
: MovingEntity(pGame, mPosition, directionVector, mBoundary, mMaxSpeed, mEntityType)
{
}

void BulletEntity::Update(const float& deltaTime)
{
	D3DXVECTOR2 oldPosition(mPosition);

	//�����ӵ�λ��
	this->mPosition.x += float(mVelocityVector.x) * deltaTime;
	this->mPosition.y += float(mVelocityVector.y) * deltaTime;

	this->m_pGame->pCellSpacePartition->CalculateNeighbors(this->Pos(), this->m_Boundary);
	for(GameEntity* pCurNeighbor =  m_pGame->pCellSpacePartition->begin();
		!(m_pGame->pCellSpacePartition->end()); pCurNeighbor = m_pGame->pCellSpacePartition->next())
	{
		//�������ӵ�ײ�ӵ�
		if((pCurNeighbor != this) && (pCurNeighbor->m_EntityType != yellowshot) && (pCurNeighbor->m_Boundary + this->m_Boundary > (pCurNeighbor->Pos() - this->Pos()).Length()))
		{
			m_pGame->RecycleAAliveEntity(pCurNeighbor, pCurNeighbor->m_EntityType);
			this->mPosition = oldPosition;		//���ÿ�Խ�ռ仮�ָ����ʱ�������ҵ���ǰλ�ò�ɾ��
			m_pGame->RecycleAAliveEntity(this, this->m_EntityType);

			return; //��֤һ���ӵ�ֻ���Ի���һ��Ŀ��
		}
	}

	//if(this->isAlive)		//����ӵ��Ƿ����
	//{
	bool _onEdge = false;		//�Ƿ�Խ��
	if(mPosition.y - m_Boundary < this->m_pGame->GetBoundary().TopLeft.y)
		_onEdge = true;
	else if(mPosition.y + m_Boundary > this->m_pGame->GetBoundary().BottomRight.y)
		_onEdge = true;
	else if(mPosition.x - m_Boundary < this->m_pGame->GetBoundary().TopLeft.x)
		_onEdge = true;
	else if(mPosition.x + m_Boundary > this->m_pGame->GetBoundary().BottomRight.x)
		_onEdge = true;

	if(_onEdge == true)
	{
		this->mPosition = oldPosition;		//�Ѿ���Խ�ռ仮�֣������ҵ���ǰλ�ò�ɾ��
		m_pGame->RecycleAAliveEntity(this, this->m_EntityType);
	}
	/*}*/
}
