#pragma once
#include "bigwindowslistener.h"

class Game;

class GameListener :
	public WindowsListener
{
private:
	int fireDeltaTime;	//������һ���ӵ������ʱ��

public:
	Game* pGame;		//����������Ϸ

private:

public:
	//
	GameListener(void);

	//
	~GameListener(void);

	//ÿ��Whileѭ�������ã������³����е���������
	virtual void frameRenderingQueued(DWORD deltaTime);
};
