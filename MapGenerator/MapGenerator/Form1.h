#pragma once

#include "Tile.h"
#include "TileList.h"
#include "TileMap.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

namespace MapGenerator {

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
	private: System::Windows::Forms::Button^  button1;
	protected:
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Panel^  panel1;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(13, 13);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(135, 47);
			this->button1->TabIndex = 0;
			this->button1->Text = L"button1";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(154, 13);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(135, 47);
			this->button2->TabIndex = 1;
			this->button2->Text = L"button2";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// panel1
			// 
			this->panel1->Location = System::Drawing::Point(13, 67);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(960, 640);
			this->panel1->TabIndex = 2;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(993, 719);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->ResumeLayout(false);

		}
#pragma endregion

		Graphics^ graphics;
		Graphics^ bufferGraphics;
		Bitmap^ bufferImage;
		Random^ rGen;

		Tile^ cobblestoneTile;
		Tile^ dryGrassTile;
		Tile^ flowerTile;

		Bitmap^ cobblestoneTileBitmap;
		Bitmap^ dryGrassTileBitmap;
		Bitmap^ flowerTileBitmap;

		TileList^ tilelistOne;
		TileMap^ tilemapOne;

	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e)
	{
		Form1::Top = 0;
		Form1::Left = 0;

		graphics = panel1->CreateGraphics();
		bufferImage = gcnew Bitmap(panel1->Width, panel1->Height);
		bufferGraphics = Graphics::FromImage(bufferImage);

		tilelistOne = gcnew TileList();
		tilemapOne = gcnew TileMap(tilelistOne, graphics);

		cobblestoneTileBitmap = gcnew Bitmap("Cobblestones Tile 32.bmp");
		dryGrassTileBitmap = gcnew Bitmap("Dry Grass Tile 32.bmp");
		flowerTileBitmap = gcnew Bitmap("Flower Tile 32.bmp");

		cobblestoneTile = gcnew Tile(cobblestoneTileBitmap);
		dryGrassTile = gcnew Tile(dryGrassTileBitmap);
		flowerTile = gcnew Tile(flowerTileBitmap);

		tilelistOne->SetTileArrayEntry(0, cobblestoneTile);
		tilelistOne->SetTileArrayEntry(1, dryGrassTile);
		tilelistOne->SetTileArrayEntry(2, flowerTile);

		rGen = gcnew Random();
	}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		for (int x = 0; x < 30; x++)
		{
			for (int y = 0; y < 20; y++)
			{
				tilemapOne->SetMapEntry(x, y, rGen->Next(3));
			}
		}
		tilemapOne->DrawMap();
	}
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		tilemapOne->LoadMapFromFile("mazeMap_30_20.csv");
		tilemapOne->DrawMap();
	}
	};
}
