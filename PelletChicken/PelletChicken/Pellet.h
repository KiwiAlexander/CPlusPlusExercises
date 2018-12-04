#pragma once

#define PELLET_DIAMETER 10
#define PELLET_SPEED 10

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

ref class Pellet
{
private:
	int xPos;
	int yPos;
	int diameter;
	int xVel;
	int yVel;
	int randomColour;
	int randomSpeed;
	Color pelletColour;
	Graphics^ canvas;
	Brush^ brush;
	Random^ rGen;
public:
	Pellet^ Next;
	property bool isAlive;
public:
	Pellet(int startXPos, int startYPos, Graphics^ startCanvas, Random^ startRGen);

	void draw();
	void move();

	int getYPos() { return yPos; }
};

