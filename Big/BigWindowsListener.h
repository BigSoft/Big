#ifndef __BIGWINDOWSLISTENER_H_
#define __BIGWINDOWSLISTENER_H_

#include "Windows.h"

class	 WindowsListener
{
public:
	//
	WindowsListener() { }

	//���������Լ�������ʵ��ĸı�
	virtual void frameRenderingQueued(DWORD deltaTime) { }
};

#endif