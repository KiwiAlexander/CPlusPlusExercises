//ALEX PHILLIPS 18/08/2016
#pragma once

#include "Sprite.h"
#include "SpriteList.h"

namespace ChickenKnight {

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
			this->ClientSize = System::Drawing::Size(1184, 682);
			this->Name = L"Form1";
			this->Text = L"ChickenKnight";
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

		Bitmap^ spriteSheets;
		Sprite^ sprite;
		SpriteList^ chickenSpriteList;


	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e)
	{
		Form1::Top = 0;
		Form1::Left = 0;

		graphics = CreateGraphics();
		backgroundBrush = gcnew SolidBrush(Color::White);
		bufferImage = gcnew Bitmap(Width, Height);
		bufferGraphics = Graphics::FromImage(bufferImage);

		rGen = gcnew Random();

		chickenSpriteList = gcnew SpriteList();
		chickenSpriteList = generateChickenSprite();
		sprite = generateKnightSprite();

		timer1->Enabled = true;
	}
	private: System::Void Form1_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) 
	{
		switch (e->KeyData)
		{
		case Keys::Left:
			sprite->spriteDirection = EDirection::WEST;
			break;
		case Keys::Up:
			sprite->spriteDirection = EDirection::NORTH;
			break;
		case Keys::Down:
			sprite->spriteDirection = EDirection::SOUTH;
			break;
		case Keys::Right:
			sprite->spriteDirection = EDirection::EAST;
			break;
		default:
			sprite->spriteDirection = EDirection::EAST;
			break;
		}
	}
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) 
	{
		bufferGraphics->FillRectangle(backgroundBrush, 0, 0, Width, Height);

		chickenSpriteList->wanderSprites();
		chickenSpriteList->moveSprites();
		chickenSpriteList->updateSprites();
		chickenSpriteList->drawSprites();

		sprite->Move();
		sprite->UpdateFrame();
		sprite->Draw();

		graphics->DrawImage(bufferImage, 0, 0);
	}
	private: Sprite^ generateKnightSprite()
	{
		int framesIntKnightSpriteSheet = 8;
		int directions = 4;

		String^ east = gcnew String("Knight Walk East 8.bmp");
		String^ south = gcnew String("Knight Walk South 8.bmp");
		String^ west = gcnew String("Knight Walk West 8.bmp");
		String^ north = gcnew String("Knight Walk North 8.bmp");

		array<String^>^ knightImages = gcnew array<String^>(directions);

		knightImages[EDirection::EAST] = east;
		knightImages[EDirection::SOUTH] = south;
		knightImages[EDirection::WEST] = west;
		knightImages[EDirection::NORTH] = north;

		return gcnew Sprite(bufferGraphics, knightImages, framesIntKnightSpriteSheet, rGen);
	}
	private: SpriteList^ generateChickenSprite()
	{
		int framesIntChickenSpriteSheet = 8;
		int directions = 4;

		String^ east = gcnew String("Little Chicken Walk East 8.bmp");
		String^ south = gcnew String("Little Chicken Walk South 8.bmp");
		String^ west = gcnew String("Little Chicken Walk West 8.bmp");
		String^ north = gcnew String("Little Chicken Walk North 8.bmp");

		array<String^>^ chickenImages = gcnew array<String^>(directions);

		chickenImages[EDirection::EAST] = east;
		chickenImages[EDirection::SOUTH] = south;
		chickenImages[EDirection::WEST] = west;
		chickenImages[EDirection::NORTH] = north;

		for (int i = 0; i < 10; i++)
		{
			Sprite^ newSprite = gcnew Sprite(bufferGraphics, chickenImages, framesIntChickenSpriteSheet, rGen);
			chickenSpriteList->addSprite(newSprite);
		}

		return chickenSpriteList;
	}
	};
}
