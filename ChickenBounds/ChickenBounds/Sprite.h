#pragma once

#define MAXDIRECTIONS 4
#define STARTVEL 5
#define CHANCEMOVE 5

#define BOUNCE 0
#define WRAP 1
#define DIE 2
#define STOP 3

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

public enum EDirection
{
	EAST, SOUTH, WEST, NORTH
};

ref class Sprite
{
private:

	Graphics^ canvas;
	array<Bitmap^>^ spriteSheets;
	Random^ rGen;
	SolidBrush^ brush;
	Pen^ pen;
	array<Point>^velocityDirections;
	Rectangle boundRectangle;

	int nFrames;
	int currentFrame;
	int xPos;
	int yPos;
	int frameWidth;
	int frameHeight;
	int xVel;
	int yVel;
	int boundAction;

public:

	EDirection spriteDirection;
	property bool isAlive;

	Sprite(Graphics^ startCanvas, array<String^>^ startSpriteSheet, int startNFrames, Random^ startRGen, Rectangle startRectangle);

	void Draw();
	void Erase();
	void Move();
	void CheckBounds();
	void UpdateFrame();
	void SetSpriteSheet(array<Bitmap^>^ newSpriteSheet, int newNFrames);
	void Wander();

	int GetBoundAction();
	void SetBoundAction(int newBoundAction);

	Sprite^ Next;
};

