#include "Approacher.h"


Approacher::Approacher(Graphics^ offScreenCanvas, Bitmap^ redShipBitmap, int shipFrames, Random^ rGen, int shipSpeed, Rectangle backgroundRectangle)
	: SimpleSprite(offScreenCanvas, redShipBitmap, shipFrames, rGen, shipSpeed, backgroundRectangle)
{
}

void Approacher::orient(SimpleSprite^ target)
{
	double angle;
	int xDelta = target->getXPos() - xPos;
	int yDelta = target->getYPos() - yPos;

	if ((xDelta != 0) && (yDelta != 0))
	{
		angle = Math::Atan2(yDelta, xDelta);
	}

	xVel = Math::Cos(angle) * speed;
	yVel = Math::Sin(angle) * speed;

	xPos += xVel;
	yPos += yVel;

}
