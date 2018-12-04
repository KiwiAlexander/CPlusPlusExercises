#pragma once

#include "Gnome.h"

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

ref class GnomeFamily
{
private:
	Random^ rGen;
	Graphics^ canvas;
	int nGnomes;
	array<Gnome^>^ gnomeArray;
public:
	GnomeFamily(Random^ startRandom, Graphics^ startCanvas, int startNGnomes);

	void drawAllGnomes();
	void drawOneGnome(int gnomeIndex);
	void eraseAllGnomes();
	void eraseOneGnome(int gnomeIndex);

	bool hitGnome(int gnomeIndex, int x, int y);
	void changeGnomeImage(int gnomeIndex, String^ newImageFileName);
	void setToHamster(int gnomeIndex);
	bool isAHamster(int gnomeIndex){ return gnomeArray[gnomeIndex]->getIsAHamster(); }
	void resetAllGnomes();
};

