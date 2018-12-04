#include "TileList.h"


TileList::TileList()
{
	tileArray = gcnew array<Tile^>(100);
}

Bitmap^ TileList::GetTileBitmap(int tileIndex)
{
	Tile^ selectedTile = tileArray[tileIndex];
	return selectedTile->TileBitmap;
}

void TileList::SetTileArrayEntry(int tileIndex, Tile^ tileToEnter)
{
	tileArray[tileIndex] = tileToEnter;
}
void TileList::SetTileWalkable(int tileIndex, bool walkable)
{
	tileArray[tileIndex]->isWalkable = walkable;
}
bool TileList::GetTileWalkable(int tileIndex)
{
	return tileArray[tileIndex]->isWalkable;
}