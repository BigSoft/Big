#pragma once
#include "bigwindowslistener.h"

class Game;

class GameListener :
	public WindowsListener
{
private:
	int fireDeltaTime;	//距离上一次子弹打出的时间

public:
	Game* pGame;		//被监听的游戏

private:

public:
	//
	GameListener(void);

	//
	~GameListener(void);

	//每次While循环被调用，来更新场景中的所有物体
	virtual void frameRenderingQueued(DWORD deltaTime);
};
