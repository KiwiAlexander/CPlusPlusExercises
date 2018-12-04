#include "TileMap.h"

TileMap::TileMap(TileList^ startTileList, Graphics^ startCanvas)
{
	tileList = startTileList;
	canvas = startCanvas;

	tileWidth = 32;
	tileHeight = 32;

	int drawLocX = 0;
	int drawLocY = 0;

	map = gcnew array<int, 2>(32, 23);
}

void TileMap::SetMapEntry(int col, int row, int tileIndex)
{
	map[col, row] = tileIndex;
}
bool TileMap::TargetWalkable(int xPos, int yPos)
{
	int currTileIndex = map[xPos, yPos];
	if (tileList->GetTileWalkable(currTileIndex) == false)
	{
		return false;
	}
	return true;
}

//int TileMap::GetMapEntry(int col, int row)
//{
//	int currTileIndex = map[col, row];
//	return tileList->GetTileBitmap(currTileIndex);
//}

void TileMap::DrawMap()
{
	for (int c = 0; c < 32; c++)
	{
		for (int r = 0; r < 23; r++)
		{
			drawLocX = c * tileWidth;
			drawLocY = r * tileHeight;

			currentTileIndex = map[c, r];
			currentTileBitmap = tileList->GetTileBitmap(currentTileIndex);

			canvas->DrawImage(currentTileBitmap, drawLocX, drawLocY);
		}
	}
}
void TileMap::LoadMapFromFile(String^ mapFileName)
{
	StreamReader^ sr = File::OpenText(mapFileName);
	String^ currentLine = "";
	array<String^>^ indexHolder = gcnew array<String^>(32);

	int rowCounter = 0;

	while (currentLine = sr->ReadLine())
	{
		indexHolder = currentLine->Split(',');

		for (int i = 0; i < 32; i++)
		{
			SetMapEntry(i, rowCounter, Convert::ToInt32(indexHolder[i]));
		}
		rowCounter++;
	}
}