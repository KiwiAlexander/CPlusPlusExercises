#include "Sprite.h"

Sprite::Sprite(Graphics^ startCanvas, Bitmap^ startSpriteSheet, int startNFrames, Random^ startRGen)
{
	canvas = startCanvas;
	SetSpriteSheet(startSpriteSheet, startNFrames);
	rGen = startRGen;
	Next = nullptr;

	xVel = rGen->Next(1,5);
	yVel = rGen->Next(1,5);

	yPos = rGen->Next(500);
	xPos = rGen->Next(500);

}
Sprite::Sprite(Graphics^ startCanvas, Bitmap^ startSpriteSheet, int startNFrames, Random^ startRGen, int startXPos, int startYPos, int startXVel, int startYVel)
{
	canvas = startCanvas;
	SetSpriteSheet(startSpriteSheet, startNFrames);
	rGen = startRGen;
	xPos = startXPos;
	yPos = startYPos;
	xVel = startXVel;
	yVel = startYVel;
	Next = nullptr;
	brush = gcnew SolidBrush(Color::WhiteSmoke);

}
void Sprite::Draw()
{
	int startY = 0;
	int startX = currentFrame * frameWidth;
	Rectangle pixelsToDraw = Rectangle(startX, startY, frameWidth, frameHeight);
	canvas->DrawImage(spriteSheet, xPos, yPos, pixelsToDraw, GraphicsUnit::Pixel);
}
void Sprite::Erase()
{
	Rectangle erase = Rectangle(xPos, yPos, frameWidth, frameHeight);
	canvas->FillRectangle(brush, erase);
}
void Sprite::Move()
{
	xPos += xVel;
	yPos += yVel;
}
void Sprite::UpdateFrame()
{
	currentFrame = (currentFrame + 1) % nFrames;
}
void Sprite::SetSpriteSheet(Bitmap^ newSpriteSheet, int newNFrames)
{
	spriteSheet = newSpriteSheet;
	nFrames = newNFrames;

	frameWidth = spriteSheet->Width / nFrames;
	frameHeight = spriteSheet->Height;
}
void Sprite::Wander()
{
	int randMove = rGen->Next(5);
	int randWay = rGen->Next(2);

	if (randMove == 0)
	{
		if (randWay == 0)
		{
			xVel *= -1;
		}
		else
		{
			yVel *= -1;
		}
	}
}
