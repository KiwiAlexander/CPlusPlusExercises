#pragma once

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

ref class Gnome
{

private:
	Graphics^ canvas;
	Image^ gnomeImage;
	bool isAHamster;
	int xPos;
	int yPos;

public:
	Gnome(Graphics^ startCanvas, int startXPos, int startYPos);
	void draw();
	void erase();
	bool pointInGnome(int x, int y);
	void changeImage(String^ newImageFile);

	bool getIsAHamster() { return isAHamster; }
	void setIsAHamster(bool i) { isAHamster = i; }
};

