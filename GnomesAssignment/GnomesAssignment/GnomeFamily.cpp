#include "GnomeFamily.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


GnomeFamily::GnomeFamily(Random^ startRandom, Graphics^ startCanvas, int startNGnomes)
{
	rGen = startRandom;
	canvas = startCanvas;
	nGnomes = startNGnomes;
	gnomeArray = gcnew array<Gnome^>(nGnomes);

	for (int g = 0; g < nGnomes; g++)
	{
		int newX = rGen->Next(10, 750);
		int newY = rGen->Next(10, 550);
		gnomeArray[g] = gcnew Gnome(canvas, newX, newY);
	}
}

void GnomeFamily::drawAllGnomes()
{

}
void GnomeFamily::drawOneGnome(int gnomeIndex)
{

}
void GnomeFamily::eraseAllGnomes()
{

}
void GnomeFamily::eraseOneGnome(int gnomeIndex)
{

}
bool GnomeFamily::hitGnome(int gnomeIndex, int x, int y)
{

}
void GnomeFamily::changeGnomeImage(int gnomeIndex, String^ newImageFileName)
{

}
void GnomeFamily::setToHamster(int gnomeIndex)
{

}
void GnomeFamily::resetAllGnomes()
{

}
