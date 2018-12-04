#pragma once
#include "Tile.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

ref class TileList
{
private:
	array<Tile^>^ tileArray;
public:
	TileList();
	Bitmap^ GetTileBitmap(int tileIndex);
	void SetTileArrayEntry(int tileIndex, Tile^ tileToEnter);
	void SetTileWalkable(int tileIndex, bool walkable);
	bool GetTileWalkable(int tileIndex);
};

