#include "Avoider.h"

Avoider::Avoider(Graphics^ offScreenCanvas, Bitmap^ yellowShipBitmap, int shipFrames, Random^ rGen, int shipSpeed, Rectangle backgroundRectangle)
	: SimpleSprite(offScreenCanvas, yellowShipBitmap, shipFrames, rGen, shipSpeed, backgroundRectangle)
{
}

void Avoider::orient(SimpleSprite^ target)
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

	yVel *= -1;
	xVel *= -1;

	xPos += xVel;
	yPos += yVel;

}