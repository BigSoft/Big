#include "GameListener.h"

#include "Game.h"
#include "PlayerEntity.h"
#include "SightEntity.h"

GameListener::GameListener(void) : pGame(NULL)
{
	fireDeltaTime = 0;
}

GameListener::~GameListener(void)
{
}

void GameListener::frameRenderingQueued(DWORD deltaTime)
{
	if( ::GetAsyncKeyState('W') & 0x8000f )
		pGame->pPlayer->MoveUp(float(deltaTime));
	if( ::GetAsyncKeyState('S') & 0x8000f )
		pGame->pPlayer->MoveDown(float(deltaTime));
	if( ::GetAsyncKeyState('A') & 0x8000f )
		pGame->pPlayer->MoveLeft(float(deltaTime));
	if( ::GetAsyncKeyState('D') & 0x8000f )
		pGame->pPlayer->MoveRight(float(deltaTime));

	if( ::GetAsyncKeyState(VK_UP) & 0x8000f )
		pGame->pSight->MoveUp(float(deltaTime));
	if( ::GetAsyncKeyState(VK_DOWN) & 0x8000f )
		pGame->pSight->MoveDown(float(deltaTime));
	if( ::GetAsyncKeyState(VK_LEFT) & 0x8000f )
		pGame->pSight->MoveLeft(float(deltaTime));
	if( ::GetAsyncKeyState(VK_RIGHT) & 0x8000f )
		pGame->pSight->MoveRight(float(deltaTime));


	/*if( ::GetAsyncKeyState(VK_SPACE) & 0x8000f )
	{*/
		fireDeltaTime += deltaTime;
		if(fireDeltaTime > pGame->fireBufferTime)
		{
			pGame->pPlayer->Fire();
			fireDeltaTime = 0;
		}
	/*}*/

	pGame->UpdateAllGameEntities(float(deltaTime));

}
