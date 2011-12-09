#ifndef __BIGWINDOWSLISTENER_H_
#define __BIGWINDOWSLISTENER_H_

#include "Windows.h"

class	 WindowsListener
{
public:
	//
	WindowsListener() { }

	//监听按键以及场景中实体的改变
	virtual void frameRenderingQueued(DWORD deltaTime) { }
};

#endif