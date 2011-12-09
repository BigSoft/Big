#include "BigBoundingGeometry.h"

BoundingBox::BoundingBox()
{
}

BoundingBox::BoundingBox(FLOAT TopLeftX, FLOAT TopLeftY, FLOAT BottomRightX, FLOAT BottomRightY)
: TopLeft(TopLeftX, TopLeftY), BottomRight(BottomRightX, BottomRightY)
{
}

bool BoundingBox::isOverlappedWith(const BoundingBox &aim)
{
	if( (TopLeft.x > aim.BottomRight.x) || (TopLeft.y > aim.BottomRight.y) ||
		 (BottomRight.x < aim.TopLeft.x) || (BottomRight.y < aim.TopLeft.y) )
		return false;
	else
		return true;
}