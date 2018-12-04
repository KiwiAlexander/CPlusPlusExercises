#include "Pellet.h"

Pellet::Pellet(int startXPos, int startYPos, Graphics^ startCanvas, Random^ startRGen)
{
	xPos = startXPos;
	yPos = startYPos;
	canvas = startCanvas;
	rGen = startRGen;
	randomColour = rGen->Next(4);
	randomSpeed = rGen->Next(5, 20);
	isAlive = true;

	switch (randomColour)
	{
	case 0:
		brush = gcnew SolidBrush(Color::Green);
		break;
	case 1:
		brush = gcnew SolidBrush(Color::Yellow);
		break;
	case 2:
		brush = gcnew SolidBrush(Color::Red);
		break;
	case 3:
		brush = gcnew SolidBrush(Color::Blue);
		break;
	default:
		brush = gcnew SolidBrush(Color::White);
	}
}
void Pellet::draw() // using graphics to draw a pellet with values set in constructor
{
	canvas->FillEllipse(brush, xPos, yPos, PELLET_DIAMETER, PELLET_DIAMETER);
}
void Pellet::move() // moves the pellet up the screen Y axis a random ammount then cheeks it hasn't moved off screen
{
	yPos = yPos - randomSpeed;
	if (yPos <= 0)
	{
		isAlive = false;
	} 
}