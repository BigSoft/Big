#ifndef GAME_ENTITY_FUNCTION_TEMPLATES
#define GAME_ENTITY_FUNCTION_TEMPLATES

#include "Vector2D.h"
#include "GameEntity.h"

//------------------- EnforceNonPenetrationConstraint ---------------------
//
//  Given a pointer to an entity and a std container of pointers to nearby
//  entities, this function checks to see if there is an overlap between
//  entities. If there is, then the entities are moved away from each
//  other
//------------------------------------------------------------------------
template <class T, class conT>
void EnforceNonPenetrationConstraint(const T&    entity, 
									 const conT& pCellSpacePartition)
{
	if(entity->m_EntityType == yellowshot)		//忽略子弹
		return;
	//iterate through all entities checking for any overlap of bounding radii
	pCellSpacePartition->CalculateNeighbors(entity->Pos(), entity->m_Boundary);
	for(T pCurNeighbor =  pCellSpacePartition->begin(); !(pCellSpacePartition->end());
		pCurNeighbor = pCellSpacePartition->next())
	{
		//make sure we don't check against the individual
		if ( pCurNeighbor->m_EntityType == yellowshot || pCurNeighbor == entity )
			continue;

		//calculate the distance between the positions of the entities
		Vector2D ToEntity = entity->Pos() - pCurNeighbor->Pos();

		double DistFromEachOther = ToEntity.Length();

		//if this distance is smaller than the sum of their radii then this
		//entity must be moved away in the direction parallel to the
		//ToEntity vector   
		double AmountOfOverLap = pCurNeighbor->m_Boundary + entity->m_Boundary -
			DistFromEachOther;

		//assert(DistFromEachOther != 0);	//0向量会出问题，不做计算
		if (AmountOfOverLap > 0 && DistFromEachOther != 0)
		{
			//move the entity a distance away equivalent to the amount of overlap.
			entity->SetPosition(entity->Pos() + (ToEntity/DistFromEachOther) *
				AmountOfOverLap);
		}
	}//next entity
}

#endif