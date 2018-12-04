#pragma once

#define MAXDIRECTIONS 4
#define STARTVEL 5
#define CHANCEMOVE 5

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
	array<Point>^velocityDirections;

	int nFrames;
	int currentFrame;
	int xPos;
	int yPos;
	int frameWidth;
	int frameHeight;
	int xVel;
	int yVel;
	bool collided;

public:

	EDirection spriteDirection;
	property bool isAlive;
	property Rectangle collisionBounds;

	Sprite(Graphics^ startCanvas, array<String^>^ startSpriteSheet, int startNFrames, Random^ startRGen);

	void Draw();
	void Erase();
	void Move();
	void UpdateFrame();
	void SetSpriteSheet(array<Bitmap^>^ newSpriteSheet, int newNFrames);
	void Wander();
	bool CheckCollisionBox(Sprite^ checkSprite);
	void UpdateCollisionBox();

	Sprite^ Next;
};

