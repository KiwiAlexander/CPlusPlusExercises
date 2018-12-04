#pragma once

#include "Tile.h"
#include "TileList.h"
#include "TileMap.h"
#include "Sprite.h"
#include "SpriteList.h"

namespace TerrainCollisionDetection {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Timer^  timer1;

	protected:
	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &Form1::timer1_Tick);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1008, 730);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::Form1_KeyDown);
			this->ResumeLayout(false);

		}
#pragma endregion

		Graphics^ graphics;
		Graphics^ bufferGraphics;
		Bitmap^ bufferImage;
		Brush^ backgroundBrush;
		Bitmap^ pixelBackgroundImage;
		Random^ rGen;

		Tile^ cobblestoneTile;
		Tile^ dryGrassTile;
		Tile^ flowerTile;

		Bitmap^ cobblestoneTileBitmap;
		Bitmap^ dryGrassTileBitmap;
		Bitmap^ flowerTileBitmap;

		TileList^ tilelistOne;
		TileMap^ tilemapOne;

		Bitmap^ spriteSheets;
		Sprite^ knightSprite;
		SpriteList^ chickenSpriteList;
		Bitmap^ bloodspat;

	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) 
	{
		Form1::Top = 0;
		Form1::Left = 0;

		rGen = gcnew Random();

		graphics = CreateGraphics();
		bufferImage = gcnew Bitmap(Width, Height);
		backgroundBrush = gcnew SolidBrush(Color::White);
		bufferGraphics = Graphics::FromImage(bufferImage);
		bloodspat = gcnew Bitmap("data/blood.png");
		Color transcolor = bloodspat->GetPixel(0, 0);
		bloodspat->MakeTransparent(transcolor);

		tilelistOne = gcnew TileList();
		tilemapOne = gcnew TileMap(tilelistOne, bufferGraphics);

		cobblestoneTileBitmap = gcnew Bitmap("data/Cobblestones Tile 32.bmp");
		dryGrassTileBitmap = gcnew Bitmap("data/Dry Grass Tile 32.bmp");
		flowerTileBitmap = gcnew Bitmap("data/Flower Tile 32.bmp");

		cobblestoneTile = gcnew Tile(cobblestoneTileBitmap);
		dryGrassTile = gcnew Tile(dryGrassTileBitmap);
		flowerTile = gcnew Tile(flowerTileBitmap);

		tilelistOne->SetTileArrayEntry(0, cobblestoneTile);
		tilelistOne->SetTileArrayEntry(1, dryGrassTile);
		tilelistOne->SetTileArrayEntry(2, flowerTile);

		tilelistOne->SetTileWalkable(2, false);
		tilelistOne->SetTileWalkable(1, true);
		tilelistOne->SetTileWalkable(0, true);

		tilemapOne->LoadMapFromFile("data/mazeMap_30_20.csv");

		chickenSpriteList = gcnew SpriteList();
		chickenSpriteList = generateChickenSprite();
		knightSprite = generateKnightSprite();

		timer1->Enabled = true;
	}
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) 
	{
		bufferGraphics->FillRectangle(backgroundBrush, 0, 0, Width, Height);

		tilemapOne->DrawMap();

		chickenSpriteList->wanderSprites();
		chickenSpriteList->moveSprites();
		chickenSpriteList->updateSprites();
		chickenSpriteList->drawSprites();
		Sprite^ deadSprite = chickenSpriteList->checkCollectionSprites(knightSprite);
		if (deadSprite != nullptr)
		{
			deadSprite->isAlive = false;
			bufferGraphics->DrawImage(bloodspat, deadSprite->collisionBounds);
		}

		if (knightSprite->checkCollisionTerrain() == true)
		{
			knightSprite->Move();
		}
		//knightSprite->Move();
		knightSprite->UpdateFrame();
		knightSprite->Draw();

		chickenSpriteList->deleteAllDeadSprites();

		graphics->DrawImage(bufferImage, 0, 0);
	}
	private: System::Void Form1_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) 
	{
		switch (e->KeyData)
		{
		case Keys::Left:
			knightSprite->spriteDirection = EDirection::WEST;
			break;
		case Keys::Up:
			knightSprite->spriteDirection = EDirection::NORTH;
			break;
		case Keys::Down:
			knightSprite->spriteDirection = EDirection::SOUTH;
			break;
		case Keys::Right:
			knightSprite->spriteDirection = EDirection::EAST;
			break;
		default:
			knightSprite->spriteDirection = EDirection::EAST;
			break;
		}
	}
	private: Sprite^ generateKnightSprite()
	{
		int framesIntKnightSpriteSheet = 8;
		int directions = 4;

		String^ east = gcnew String("data/Knight Walk East 8.bmp");
		String^ south = gcnew String("data/Knight Walk South 8.bmp");
		String^ west = gcnew String("data/Knight Walk West 8.bmp");
		String^ north = gcnew String("data/Knight Walk North 8.bmp");

		array<String^>^ knightImages = gcnew array<String^>(directions);

		knightImages[EDirection::EAST] = east;
		knightImages[EDirection::SOUTH] = south;
		knightImages[EDirection::WEST] = west;
		knightImages[EDirection::NORTH] = north;

		return gcnew Sprite(bufferGraphics, knightImages, framesIntKnightSpriteSheet, rGen, tilemapOne);
	}
	private: SpriteList^ generateChickenSprite()
	{
		int framesIntChickenSpriteSheet = 8;
		int directions = 4;

		String^ east = gcnew String("data/Little Chicken Walk East 8.bmp");
		String^ south = gcnew String("data/Little Chicken Walk South 8.bmp");
		String^ west = gcnew String("data/Little Chicken Walk West 8.bmp");
		String^ north = gcnew String("data/Little Chicken Walk North 8.bmp");

		array<String^>^ chickenImages = gcnew array<String^>(directions);

		chickenImages[EDirection::EAST] = east;
		chickenImages[EDirection::SOUTH] = south;
		chickenImages[EDirection::WEST] = west;
		chickenImages[EDirection::NORTH] = north;

		for (int i = 0; i < 10; i++)
		{
			Sprite^ newSprite = gcnew Sprite(bufferGraphics, chickenImages, framesIntChickenSpriteSheet, rGen, tilemapOne);
			chickenSpriteList->addSprite(newSprite);
		}

		return chickenSpriteList;
	}
};
}
