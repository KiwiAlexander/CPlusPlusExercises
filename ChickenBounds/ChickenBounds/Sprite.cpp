#include "Sprite.h"

Sprite::Sprite(Graphics^ startCanvas, array<String^>^ startSpriteSheet, int startNFrames, Random^ startRGen, Rectangle startRectangle)
{
	spriteSheets = gcnew array<Bitmap^>(MAXDIRECTIONS);
	for (int i = 0; i < MAXDIRECTIONS; i++)
	{
		spriteSheets[i] = gcnew Bitmap(startSpriteSheet[i]);
		Color transcolor = spriteSheets[i]->GetPixel(0, 0);
		spriteSheets[i]->MakeTransparent(transcolor);
	}

	nFrames = startNFrames;

	frameWidth = (int)spriteSheets[0]->Width / nFrames;
	frameHeight = spriteSheets[0]->Height;

	velocityDirections = gcnew array<Point>(MAXDIRECTIONS);
	velocityDirections[0] = Point(1, 0); //EAST
	velocityDirections[1] = Point(0, 1); //SOUTH
	velocityDirections[2] = Point(-1, 0); //WEST
	velocityDirections[3] = Point(0, -1); //NORTH

	canvas = startCanvas;
	rGen = startRGen;
	Next = nullptr;
	currentFrame = 0;

	xVel = STARTVEL;
	yVel = STARTVEL;

	yPos = rGen->Next(100,620);
	xPos = rGen->Next(100,980);

	spriteDirection = EDirection::EAST;

	startRectangle = Rectangle((xPos - 10), (yPos - 10), rGen->Next(100,250), rGen->Next(100,250));
	boundRectangle = startRectangle;
	pen = gcnew Pen(Color::Black);

	boundAction = 0;
	isAlive = true;
}

void Sprite::Draw()
{
	int startY = 0;
	int startX = currentFrame * frameWidth;
	Rectangle pixelsToDraw = Rectangle(startX, startY, frameWidth, frameHeight);

	Bitmap^ currentBitmap = spriteSheets[spriteDirection];

	canvas->DrawImage(currentBitmap, xPos, yPos, pixelsToDraw, GraphicsUnit::Pixel);
	canvas->DrawRectangle(pen, boundRectangle);
}
void Sprite::Erase()
{
	Rectangle erase = Rectangle(xPos, yPos, frameWidth, frameHeight);
	canvas->FillRectangle(brush, erase);
}
void Sprite::Move()
{
	xPos += xVel * velocityDirections[spriteDirection].X;
	yPos += yVel * velocityDirections[spriteDirection].Y;
}
void Sprite::CheckBounds()
{
	if ((xPos < boundRectangle.Left) || ((xPos + frameWidth) > boundRectangle.Right) || (yPos < boundRectangle.Top) || (yPos + frameHeight) > boundRectangle.Bottom)
	{
		switch (boundAction)
		{
		case BOUNCE:
			if (xPos < boundRectangle.Left)
			{
				spriteDirection = EDirection::EAST;
			}
			else if ((xPos + frameWidth) > boundRectangle.Right)
			{
				spriteDirection = EDirection::WEST;
			}
			else if (yPos < boundRectangle.Top)
			{
				spriteDirection = EDirection::SOUTH;
			}
			else
			{
				spriteDirection = EDirection::NORTH;
			}
			break;
		case WRAP:
			if (xPos < boundRectangle.Left)
			{
				xPos = boundRectangle.Right - (frameWidth + xVel);
			}
			else if ((xPos + frameWidth) > boundRectangle.Right)
			{
				xPos = boundRectangle.Left + xVel;
			}
			else if (yPos < boundRectangle.Top)
			{
				yPos = boundRectangle.Bottom - (frameHeight + yVel);
			}
			else if ((yPos + frameHeight) > boundRectangle.Bottom)
			{
				yPos = boundRectangle.Top - yVel;
			}
			break;
		case DIE:
			isAlive = false;
			break;
		case STOP:
			xVel = 0;
			yVel = 0;
			break;
		default:
			break;
		}
	}
}
void Sprite::UpdateFrame()
{
	currentFrame = (currentFrame + 1) % nFrames;
}
void Sprite::SetSpriteSheet(array<Bitmap^>^ newSpriteSheet, int newNFrames)
{
	spriteSheets = newSpriteSheet;
	nFrames = newNFrames;

	frameWidth = (int)spriteSheets[0]->Width / nFrames;
	frameHeight = spriteSheets[0]->Height;
}
void Sprite::Wander()
{
	int randMove = rGen->Next(CHANCEMOVE);

	if (randMove == 0)
	{
		int randDirection = rGen->Next(MAXDIRECTIONS);
		switch (randDirection)
		{
		case 0:
				spriteDirection = EDirection::EAST;
			break;
		case 1:
				spriteDirection = EDirection::SOUTH;
			break;
		case 2:
				spriteDirection = EDirection::WEST;
			break;
		case 3:
				spriteDirection = EDirection::NORTH;
			break;
		default:
			break;
		}
	}
}
int Sprite::GetBoundAction()
{
	return boundAction;
}
void Sprite::SetBoundAction(int newBoundAction)
{
	boundAction = newBoundAction;
}

//bool Sprite::GetIsAlive()
//{
//	return isAlive;
//}
//void Sprite::SetIsAlive(bool newAliveState)
//{
//	isAlive = newAliveState;
//}
