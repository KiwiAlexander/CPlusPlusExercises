#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

ref class Sprite
{
private:
	Graphics^ canvas;
	Bitmap^ spriteSheet;
	Random^ rGen;
	SolidBrush^ brush;
	int nFrames;
	int currentFrame;
	int xPos;
	int yPos;
	int frameWidth;
	int frameHeight;
	int xVel;
	int yVel;

public:
	Sprite(Graphics^ startCanvas, Bitmap^ startSpriteSheet, int startNFrames, Random^ startRGen);
	Sprite(Graphics^ startCanvas, Bitmap^ startSpriteSheet, int startNFrames, Random^ startRGen, int XPos, int YPos, int XVel, int YVel);
	void Draw();
	void Erase();
	void Move();
	void UpdateFrame();
	void SetSpriteSheet(Bitmap^ newSpriteSheet, int newNFrames);
	void Wander();
	Sprite^ Next;
};

