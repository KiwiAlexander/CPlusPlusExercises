#include "SimpleSprite.h"


//==================================================================================
//
//==================================================================================
SimpleSprite::SimpleSprite(Graphics^ startCanvas, Bitmap^ startSpriteSheet, int startNFrames, Random^ startRGen,
	int startSpeed, Rectangle startTerritory)
{
	canvas = startCanvas;
	spriteSheet = startSpriteSheet;
	nFrames = startNFrames;
	rGen = startRGen;
	speed = startSpeed;
	territory = startTerritory;

	frameHeight = spriteSheet->Height;
	frameWidth = (int)spriteSheet->Width / nFrames;

	currentFrame = 0;

	// defaults
	xPos = 0;
	yPos = 0;

	// default movement is 45 degrees at speed
	xVel = speed; 
	yVel = speed;

	Next = nullptr;

} // end SimpleSprite constructor

//==================================================================================
//
//==================================================================================
void SimpleSprite::orient(SimpleSprite^ target)
{
	// Base class does not orient
	// Empty code body. Not abstract, because we want to declare instances of
	// base class
}
//==================================================================================
//
//==================================================================================
bool SimpleSprite::ranIntoWorldEdge()
{
	bool ranIntoEdge = false;

	if (xPos < territory.Left)
		ranIntoEdge = true;

	if ((xPos + frameWidth) > territory.Right)
		ranIntoEdge = true;

	if (yPos < territory.Top)
		ranIntoEdge = true;

	if ((yPos + frameHeight) > territory.Bottom)
		ranIntoEdge = true;
		
	return ranIntoEdge;
}
//==================================================================================
//
//==================================================================================
void SimpleSprite::dealWithEdgeCollision()
{
	// Base class makes simple bounce
	bool hitEdge = ranIntoWorldEdge();
	if (hitEdge)
	{
		xVel *= -1;
		yVel *= -1;
	}
}

//==================================================================================
//
//==================================================================================
double SimpleSprite::computeAngleToTarget(SimpleSprite^ target)
{
	double angle;

	int xDelta = target->getXPos() - xPos;
	int yDelta = target->getYPos() - yPos;

	if ((xDelta != 0) && (yDelta != 0))
	{
		// Check order of args
		// atan2 returns the angle of rotation between two points with vertical distance arg1 and horizontal distance arg2
		angle = Math::Atan2(yDelta, xDelta);	// result is in radians
	}
	else
		angle = 0.0;	// instance and target share an x or y axis location. This works as a heuristic

	return angle;
}


//==================================================================================
//
//==================================================================================
void SimpleSprite::draw()
{
		int currFrameX = currentFrame * frameWidth;
		int currFrameY = 0;							
		Rectangle drawRect = Rectangle(currFrameX, currFrameY, frameWidth, frameHeight);
		canvas->DrawImage(spriteSheet,xPos,yPos,drawRect,GraphicsUnit::Pixel);
} //end draw


//==================================================================================
// Simple stop at edge of world
//==================================================================================
void SimpleSprite::move()
{
	xPos += xVel;
	yPos += yVel;
} // end move

//==================================================================================
//
//==================================================================================
void SimpleSprite::updateFrame()
{
	// increment with loopig
	currentFrame = (currentFrame + 1) % nFrames;
} // end updateFrame


//==================================================================================
// Simple movement variety inherited by all children
//==================================================================================
void SimpleSprite::wander()
{
	// e.g. if WANDER_PROB == 5, you have a 1/5 chance of changing direction
	if (rGen->Next(WANDER_PROB) == 0)
		xVel *= -1;
	if (rGen->Next(WANDER_PROB) == 0)
		yVel *= -1;

	move();
}
