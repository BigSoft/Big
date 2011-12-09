#pragma once
#include "bigsceneentity.h"
#include "Vector2D.h"

class Game;
struct Vector2D;

enum EntityType { whiteplayer, yellowshot, sight,
									pinkpinwheel, bluediamond, greensquare,
										indigotriangle, bluecircle, orangetriangle,
											purplesquare1, purplesquare2, redcircle, redclone};

class GameEntity :
	public SceneEntity
{
private:

public:
	bool isAlive;									//�Ƿ����
	float m_Boundary;							//Բ�α߽���뾶
	EntityType m_EntityType;				//ʵ������

protected:
	Game* m_pGame;							//��ǰ��Ϸ
	Vector2D m_DirectionVector;		//��������,��λ����
	float m_MaxSpeed;							//����ٶ�ֵ

private:

public:
	//
	GameEntity(Game* pGame, const Vector2D& mPosition, const Vector2D& directionVector, float mBoundary, float mMaxSpeed, EntityType mEntityType);

	//��ǰλ��
	Vector2D Pos();

	//���µ�ǰ����
	virtual void Update(const float& deltaTime) { }

	//���ݷ������ýǶ�
	void resetAngle();

protected:
};
