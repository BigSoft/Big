#include "BigWindowsUtility.h"

#include "resource.h"
#include "BigWindowsListener.h"
#include "BigOrigin.h"

#define MAX_LOADSTRING 100
TCHAR szTitle[MAX_LOADSTRING] = "Big";					// The title bar text
TCHAR szWindowClass[MAX_LOADSTRING] = "BigExample";			// the main window class name

BOOL MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style			= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= WndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= hInstance;
	wcex.hIcon			= LoadIcon(hInstance, MAKEINTRESOURCE(IDI_BIG));
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName	= NULL;
	wcex.lpszClassName	= szWindowClass;
	wcex.hIconSm		= LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	if( !RegisterClassEx(&wcex) ) 
	{
		MessageBox(0, "RegisterClassEx() - FAILED", 0, 0);
		return FALSE;
	}
	else
		return TRUE;
}

BOOL InitInstance(HWND& hWnd, HINSTANCE hInstance, int nCmdShow, int x, int y, int nWidth, int nHeight)
{
	hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
		x, y, nWidth, nHeight, NULL, NULL, hInstance, NULL);

	if (!hWnd)
	{
		MessageBox(0, "CreateWindow() - FAILED", 0, 0);
		return FALSE;
	}

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	return TRUE;
}

WPARAM EnterMsgLoop(WindowsListener* pBigWinListener, Origin* pBigOrigin)
{
	static DWORD lastTime = timeGetTime();
	DWORD currTime = 0;

	MSG msg;
	ZeroMemory(&msg, sizeof(MSG));

	while(msg.message != WM_QUIT)
	{
		if(PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			pBigOrigin->RenderOneFrame();

			currTime  = timeGetTime();
			pBigWinListener->frameRenderingQueued(currTime - lastTime);
			pBigOrigin->UpdateParticals(currTime - lastTime);
			lastTime = currTime;
		}
	}
	return msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;

	switch (message)
	{
	case WM_COMMAND:
		wmId    = LOWORD(wParam);
		wmEvent = HIWORD(wParam);
		// Parse the menu selections:
		/*switch (wmId)
		{
		case IDM_ABOUT:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		default:*/
			return DefWindowProc(hWnd, message, wParam, lParam);
		/*}*/
		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		// TODO: Add any drawing code here...
		EndPaint(hWnd, &ps);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

// Message handler for about box.
//INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
//{
//	UNREFERENCED_PARAMETER(lParam);
//	switch (message)
//	{
//	case WM_INITDIALOG:
//		return (INT_PTR)TRUE;
//
//	case WM_COMMAND:
//		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
//		{
//			EndDialog(hDlg, LOWORD(wParam));
//			return (INT_PTR)TRUE;
//		}
//		break;
//	}
//	return (INT_PTR)FALSE;
//}