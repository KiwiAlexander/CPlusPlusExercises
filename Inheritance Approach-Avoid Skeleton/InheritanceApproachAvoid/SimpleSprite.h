#pragma once


#define WANDER_PROB 50


	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


ref class SimpleSprite
{
protected:
	Graphics^ canvas;
	Bitmap^ spriteSheet;
	Random^ rGen;
	int nFrames;
	int currentFrame;
	int xPos;
	int yPos;
	int frameWidth;
	int frameHeight;
	int xVel;
	int yVel;
	int speed;				// used to compute xVel and yVel
	Rectangle territory;	// for bounds checking

public:
	SimpleSprite^ Next;

public:
	SimpleSprite(Graphics^ startCanvas, Bitmap^ startSpriteSheet, int startNFrames, Random^ startRGen, 
		int startSpeed, Rectangle startTerritory);

	double computeAngleToTarget(SimpleSprite^ target);
	bool ranIntoWorldEdge();

	void draw();
	void move();
	void wander();
	void updateFrame();

	virtual void orient(SimpleSprite^ target);
	virtual void dealWithEdgeCollision();


	void setNFrames(int f)			{nFrames = f;}
	void setCurrentFrame(int c)		{currentFrame = c;}
	void setXPos(int x)				{xPos = x;}
	void setYPos(int y)				{yPos = y;}
	void setXVel(int xv)			{xVel = xv;}
	void setYVel(int yv)			{yVel = yv;}

	int getNFrames()			{return nFrames;}
	int getCurrentFrame()		{return currentFrame;}
	int getXPos()				{return xPos;}
	int getYPos()				{return yPos;}
	int getXVel()				{return xVel;}
	int getYVel()				{return yVel;}
	int getFrameWidth()			{return frameWidth;}
	int getFrameHeight()		{return frameHeight;}

};
