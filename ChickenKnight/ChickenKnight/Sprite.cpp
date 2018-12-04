#include "Sprite.h"

Sprite::Sprite(Graphics^ startCanvas, array<String^>^ startSpriteSheet, int startNFrames, Random^ startRGen)
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

	yPos = rGen->Next(100,520);
	xPos = rGen->Next(100,1000);

	spriteDirection = EDirection::EAST;
}

void Sprite::Draw()
{
	int startY = 0;
	int startX = currentFrame * frameWidth;
	Rectangle pixelsToDraw = Rectangle(startX, startY, frameWidth, frameHeight);

	Bitmap^ currentBitmap = spriteSheets[spriteDirection];

	canvas->DrawImage(currentBitmap, xPos, yPos, pixelsToDraw, GraphicsUnit::Pixel);
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
			if (xPos < 1100)
			{
				spriteDirection = EDirection::EAST;
			}
			break;
		case 1:
			if (yPos < 620)
			{
				spriteDirection = EDirection::SOUTH;
			}
			break;
		case 2:
			if (xPos > 100)
			{
				spriteDirection = EDirection::WEST;
			}
			break;
		case 3:
			if (yPos > 100)
			{
				spriteDirection = EDirection::NORTH;
			}
			break;
		default:
			break;
		}
	}
}
