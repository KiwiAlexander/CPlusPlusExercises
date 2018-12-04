#include "Gnome.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

Gnome::Gnome(Graphics^ startCanvas, int startXPos, int startYPos)
{
	canvas = startCanvas;
	xPos = startXPos;
	yPos = startYPos;
	isAHamster = false;
	gnomeImage = Image::FromFile("gnome.jpg");
}
void Gnome::draw()
{

}

void Gnome::erase()
{

}

bool Gnome::pointInGnome(int x, int y)
{

}

void Gnome::changeImage(String^ newImageFile)
{

}


