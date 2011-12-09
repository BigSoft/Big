#ifndef __BIGBOUNDINGGEOMETRY_H_
#define __BIGBOUNDINGGEOMETRY_H_

#include "d3dx9math.h"

class BoundingBox
{
private:

public:
	D3DXVECTOR2 TopLeft;
	D3DXVECTOR2 BottomRight;

private:

public:
	//
	BoundingBox();
	BoundingBox(float TopLeftX, float TopLeftY, float BottomRightX, float BottomRightY);

	//
	bool isOverlappedWith(const BoundingBox& aim);
};

#endif