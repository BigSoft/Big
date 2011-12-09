#ifndef __BIGWINDOWSUTILITY_H_
#define __BIGWINDOWSUTILITY_H_

#include "windows.h"

class	 WindowsListener;
class Origin;

BOOL MyRegisterClass(HINSTANCE hInstance);

BOOL InitInstance(HWND& hWnd, HINSTANCE hInstance, int nCmdShow, int x, int y, int nWidth, int nHeight);

WPARAM EnterMsgLoop(WindowsListener* pBigWinListener, Origin* pBigOrigin);

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
//INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);

#endif