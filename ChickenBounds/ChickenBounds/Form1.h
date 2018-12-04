#pragma once

#include "Sprite.h"
#include "SpriteList.h"

namespace ChickenBounds {

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
	private: System::Windows::Forms::GroupBox^  groupBox1;
	protected:
	private: System::Windows::Forms::RadioButton^  radioButton4;
	private: System::Windows::Forms::RadioButton^  radioButton3;
	private: System::Windows::Forms::RadioButton^  radioButton2;
	private: System::Windows::Forms::RadioButton^  radioButton1;
	private: System::Windows::Forms::Timer^  timer1;
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
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->radioButton4 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton3 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->radioButton4);
			this->groupBox1->Controls->Add(this->radioButton3);
			this->groupBox1->Controls->Add(this->radioButton2);
			this->groupBox1->Controls->Add(this->radioButton1);
			this->groupBox1->Location = System::Drawing::Point(13, 13);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(102, 117);
			this->groupBox1->TabIndex = 0;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"groupBox1";
			// 
			// radioButton4
			// 
			this->radioButton4->AutoSize = true;
			this->radioButton4->Location = System::Drawing::Point(7, 92);
			this->radioButton4->Name = L"radioButton4";
			this->radioButton4->Size = System::Drawing::Size(54, 17);
			this->radioButton4->TabIndex = 3;
			this->radioButton4->TabStop = true;
			this->radioButton4->Text = L"STOP";
			this->radioButton4->UseVisualStyleBackColor = true;
			this->radioButton4->CheckedChanged += gcnew System::EventHandler(this, &Form1::radioButton4_CheckedChanged);
			// 
			// radioButton3
			// 
			this->radioButton3->AutoSize = true;
			this->radioButton3->Location = System::Drawing::Point(7, 68);
			this->radioButton3->Name = L"radioButton3";
			this->radioButton3->Size = System::Drawing::Size(43, 17);
			this->radioButton3->TabIndex = 2;
			this->radioButton3->TabStop = true;
			this->radioButton3->Text = L"DIE";
			this->radioButton3->UseVisualStyleBackColor = true;
			this->radioButton3->CheckedChanged += gcnew System::EventHandler(this, &Form1::radioButton3_CheckedChanged);
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->Location = System::Drawing::Point(7, 44);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(58, 17);
			this->radioButton2->TabIndex = 1;
			this->radioButton2->TabStop = true;
			this->radioButton2->Text = L"WRAP";
			this->radioButton2->UseVisualStyleBackColor = true;
			this->radioButton2->CheckedChanged += gcnew System::EventHandler(this, &Form1::radioButton2_CheckedChanged);
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->Location = System::Drawing::Point(7, 20);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(70, 17);
			this->radioButton1->TabIndex = 0;
			this->radioButton1->TabStop = true;
			this->radioButton1->Text = L"BOUNCE";
			this->radioButton1->UseVisualStyleBackColor = true;
			this->radioButton1->CheckedChanged += gcnew System::EventHandler(this, &Form1::radioButton1_CheckedChanged);
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &Form1::timer1_Tick);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1064, 681);
			this->Controls->Add(this->groupBox1);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
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

		Rectangle boundRectangle;

		private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) 
		{
			Form1::Top = 0;
			Form1::Left = 0;

			graphics = CreateGraphics();
			backgroundBrush = gcnew SolidBrush(Color::White);
			bufferImage = gcnew Bitmap(Width, Height);
			bufferGraphics = Graphics::FromImage(bufferImage);

			rGen = gcnew Random();
			boundRectangle = Rectangle(0, 0, Width, Height);

			chickenSpriteList = gcnew SpriteList();
			chickenSpriteList = generateChickenSprite();

			timer1->Enabled = true;
		}
		private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e)
		{
			bufferGraphics->FillRectangle(backgroundBrush, 0, 0, Width, Height);

			chickenSpriteList->wanderSprites();
			chickenSpriteList->checkBounds();
			chickenSpriteList->moveSprites();
			chickenSpriteList->updateSprites();
			chickenSpriteList->drawSprites();
			chickenSpriteList->deleteAllDeadSprites();

			graphics->DrawImage(bufferImage, 0, 0);
		}

		private: System::Void radioButton1_CheckedChanged(System::Object^  sender, System::EventArgs^  e) 
		{
			chickenSpriteList->updateBounds(0);
		}
		private: System::Void radioButton2_CheckedChanged(System::Object^  sender, System::EventArgs^  e) 
		{
			chickenSpriteList->updateBounds(1);
		}
		private: System::Void radioButton3_CheckedChanged(System::Object^  sender, System::EventArgs^  e) 
		{
			chickenSpriteList->updateBounds(2);
		}
		private: System::Void radioButton4_CheckedChanged(System::Object^  sender, System::EventArgs^  e) 
		{
			chickenSpriteList->updateBounds(3);
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

			for (int i = 0; i < 5; i++)
			{
				Sprite^ newSprite = gcnew Sprite(bufferGraphics, chickenImages, framesIntChickenSpriteSheet, rGen, boundRectangle);
				chickenSpriteList->addSprite(newSprite);
			}

			return chickenSpriteList;
		}
};
}
