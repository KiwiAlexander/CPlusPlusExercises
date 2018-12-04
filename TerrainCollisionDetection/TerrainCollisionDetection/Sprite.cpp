#include "Sprite.h"

Sprite::Sprite(Graphics^ startCanvas, array<String^>^ startSpriteSheet, int startNFrames, Random^ startRGen, TileMap^ startSpriteTilemap)
{
	spriteSheets = gcnew array<Bitmap^>(MAXDIRECTIONS);
	for (int i = 0; i < MAXDIRECTIONS; i++)
	{
		spriteSheets[i] = gcnew Bitmap(startSpriteSheet[i]);
		Color transcolor = spriteSheets[i]->GetPixel(0, 0);
		spriteSheets[i]->MakeTransparent(transcolor);
	}

	spritesTilemap = startSpriteTilemap;

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

	yPos = rGen->Next(50,620);
	xPos = rGen->Next(50,900);

	collisionBounds = Rectangle(xPos, yPos, frameWidth, frameHeight);

	spriteDirection = EDirection::EAST;
	isAlive = true;
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

void Sprite::UpdateCollisionBox()
{
	collisionBounds = Rectangle(xPos, yPos, frameWidth, frameHeight);
}

bool Sprite::CheckCollisionBox(Sprite^ otherSprite)
{
	collided = true;

	UpdateCollisionBox();
	otherSprite->UpdateCollisionBox();

	if (collisionBounds.Bottom < otherSprite->collisionBounds.Top)
	{
		collided = false;
	}
	if (collisionBounds.Top > otherSprite->collisionBounds.Bottom)
	{
		collided = false;
	}
	if (collisionBounds.Right < otherSprite->collisionBounds.Left)
	{
		collided = false;
	}
	if (collisionBounds.Left > otherSprite->collisionBounds.Right)
	{
		collided = false;
	}
	return collided;
}
bool Sprite::checkCollisionTerrain()
{

	int nextXPos = xPos + xVel * velocityDirections[spriteDirection].X;
	int nextYPos = yPos + yVel * velocityDirections[spriteDirection].Y;

	switch (spriteDirection)
	{
	case(NORTH) :
		nextXPos = xPos + xVel * velocityDirections[spriteDirection].X + (frameWidth / 2);
		nextYPos = yPos + yVel * velocityDirections[spriteDirection].Y;
		break;
	case(EAST) :
		nextXPos = xPos + (xVel * velocityDirections[spriteDirection].X) + frameWidth;
		nextYPos = yPos + (yVel * velocityDirections[spriteDirection].Y) + frameHeight;
		break;
	case(SOUTH) :
		nextXPos = xPos + (xVel * velocityDirections[spriteDirection].X);
		nextYPos = yPos + (yVel * velocityDirections[spriteDirection].Y) + frameHeight;
		break;
	case(WEST) :
		nextXPos = xPos + xVel * velocityDirections[spriteDirection].X;
		nextYPos = yPos + yVel * velocityDirections[spriteDirection].Y;
		break;
	default:
		break;
	}

	int xTile = nextXPos / 32;
	int yTile = nextYPos / 32;

	if (spritesTilemap->TargetWalkable(xTile, yTile) == false)
	{
		return false;
	}
	return true;
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
