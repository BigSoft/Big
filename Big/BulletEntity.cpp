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

	//更新子弹位置
	this->mPosition.x += float(mVelocityVector.x) * deltaTime;
	this->mPosition.y += float(mVelocityVector.y) * deltaTime;

	this->m_pGame->pCellSpacePartition->CalculateNeighbors(this->Pos(), this->m_Boundary);
	for(GameEntity* pCurNeighbor =  m_pGame->pCellSpacePartition->begin();
		!(m_pGame->pCellSpacePartition->end()); pCurNeighbor = m_pGame->pCellSpacePartition->next())
	{
		//不允许子弹撞子弹
		if((pCurNeighbor != this) && (pCurNeighbor->m_EntityType != yellowshot) && (pCurNeighbor->m_Boundary + this->m_Boundary > (pCurNeighbor->Pos() - this->Pos()).Length()))
		{
			m_pGame->RecycleAAliveEntity(pCurNeighbor, pCurNeighbor->m_EntityType);
			this->mPosition = oldPosition;		//正好跨越空间划分格击中时，必须找到以前位置并删除
			m_pGame->RecycleAAliveEntity(this, this->m_EntityType);

			return; //保证一个子弹只可以击中一个目标
		}
	}

	//if(this->isAlive)		//检测子弹是否可用
	//{
	bool _onEdge = false;		//是否越界
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
		this->mPosition = oldPosition;		//已经跨越空间划分，必须找到以前位置并删除
		m_pGame->RecycleAAliveEntity(this, this->m_EntityType);
	}
	/*}*/
}
