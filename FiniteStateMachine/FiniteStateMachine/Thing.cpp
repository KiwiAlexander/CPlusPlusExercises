#include "Thing.h"
// USING SLACK CODE GIVEN CREDIT :  PHADEN

Thing::Thing()
{
}

Thing::Thing(Graphics^ startcanvas, Random^ startRandom, int startworldWidth, int startworldHeight, String^ imageFileName)
{
	canvas = startcanvas;
	rGen = startRandom;
	worldWidth = startworldWidth;
	worldHeight = startworldHeight;

	thingImage = gcnew Bitmap(imageFileName);
	thingImage->MakeTransparent(thingImage->GetPixel(0, 0));
	radius = thingImage->Width / 2;

	// some defaults...
	speed = rGen->Next(5) + 1;
	isAlive = true;

	PointMeAt(rGen->Next(worldWidth), rGen->Next(worldHeight));

}

void Thing::Move()
{
	location.X += direction.X;
	location.Y += direction.Y;

	if ((location.X < 0) || (location.Y < 0) || (location.X > worldWidth) || (location.Y > worldHeight))
		ChangeRandomdirection();
}

void Thing::ChangeRandomdirection()
{
	int newX = rGen->Next(worldWidth);
	int newY = rGen->Next(worldHeight);
	PointMeAt(newX, newY);
}

void Thing::Draw()
{
	if (isAlive)
	{
		canvas->DrawImage(thingImage, Rectangle(location.X, location.Y, radius * 2, radius * 2));
	}
}

void Thing::PointMeAt(int newX, int newY)
{
	// Compute deltas to target point
	double deltaX = newX - location.X;
	double deltaY = newY - location.Y;

	// Use Atan2 to get the angle to the target point
	double angle = Math::Atan2(deltaX, deltaY);

	// Use the angle and my speed to work out the X and Y velocities
	double vectorX = Math::Sin(angle) * speed;
	double vectorY = Math::Cos(angle) * speed;

	// Store them for the next move
	direction.X = Convert::ToInt16(vectorX);
	direction.Y = Convert::ToInt16(vectorY);
}

double Thing::ComputeDistance(Thing^ otherGuy)
{
	// Pythagorean distance computation
	int centreX = location.X + (radius / 2);
	int centreY = location.Y + (radius / 2);

	int otherX = otherGuy->location.X + (otherGuy->radius / 2);
	int otherY = otherGuy->location.Y + (otherGuy->radius / 2);

	double deltaX = centreX - otherX;
	double deltaY = centreY - otherY;

	double xSq = deltaX * deltaX;
	double ySq = deltaY * deltaY;

	double distance = Math::Sqrt(xSq + ySq);

	return distance;
}
