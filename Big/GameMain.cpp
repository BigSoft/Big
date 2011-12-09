#include "Game.h"
#include "GameListener.h"


int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
	Game* pGame = new Game(hInstance, nCmdShow);
	GameListener* pListener = new GameListener();
	pGame->AddGameListener(pListener);
	pGame->Go();

	delete pGame;
	delete pListener;
	return 0;
}