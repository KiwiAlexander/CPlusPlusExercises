
#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

ref class Tile
{
public:
	property Bitmap^ TileBitmap;
	property bool isWalkable;
	Tile(Bitmap^ startTileBitmap);
};

