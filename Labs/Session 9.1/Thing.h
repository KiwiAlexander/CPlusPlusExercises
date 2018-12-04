#pragma once

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

ref class Thing
{

	// When inheriting use get/set methods, not Properties. The Property syntax gets too complicated...
protected:
	 Point location;
	 bool isAlive;
	 int radius;
	 Point direction;
	 int speed;
	 Graphics^ canvas;
	 int r;	// Some Thing instances may need a colour to draw themselves
	 int g;
	 int b;
	 Random^ rGen;
	 int worldWidth;
	 int worldHeight;
	 Bitmap^ thingImage;

public:
	Thing();
	Thing(Graphics^ startcanvas, Random^ startRandom, int startWorldWidth, int startWorldHeight, String^ imageFileName);

	void Move();
	void ChangeRandomdirection();
	virtual void Draw();
	void PointMeAt(int newX, int newY);
	double ComputeDistance(Thing^ otherGuy);

	bool GetIsAlive()					{ return isAlive; }

	void SetIsAlive(bool a)				{ isAlive = a; }
	void Setlocation(Point newlocation)	{ location = newlocation; }
};
