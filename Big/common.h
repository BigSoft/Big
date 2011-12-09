#ifndef __BIGCOMMON_H_
#define __BIGCOMMON_H_

#include "d3dx9.h"

DWORD FtoDw(float f)
{
	return *((DWORD*)&f);
}

float GetRandomFloat(float lowBound, float highBound)
{
	if( lowBound >= highBound ) // bad input
		return lowBound;

	// get random float in [0, 1] interval
	float f = (rand() % 10000) * 0.0001f; 

	// return float in [lowBound, highBound] interval. 
	return (f * (highBound - lowBound)) + lowBound; 
}

void GetRandomVector(
					 D3DXVECTOR2* out,
					 D3DXVECTOR2* min,
					 D3DXVECTOR2* max)
{
	out->x = GetRandomFloat(min->x, max->x);
	out->y = GetRandomFloat(min->y, max->y);
}

#endif