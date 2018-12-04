// ALEX PHILLIPS - 12/08/2016 - PRO 4 - BLOBBSPRITEMOVEMENT 

#pragma once

#include "Sprite.h"
#include "SpriteList.h"

namespace Sprite41Prac {

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
	private: System::Windows::Forms::Button^  button1;

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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &Form1::timer1_Tick);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(517, 427);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"button1";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::WhiteSmoke;
			this->ClientSize = System::Drawing::Size(604, 462);
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
		Brush^ backgroundBrush;
		Bitmap^ pixelBackgroundImage;

		Random^ rGen;

		Bitmap^ spriteSheet;
		Sprite^ sprite;
		SpriteList^ spriteList;

		int count;

	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e)
	{
		count = 0;

		graphics = CreateGraphics();
		spriteSheet = gcnew Bitmap("BlobboMulti.bmp");
		Color trancolor = spriteSheet->GetPixel(0, 0);
		spriteSheet->MakeTransparent(trancolor);

		backgroundBrush = gcnew SolidBrush(Color::White);
		pixelBackgroundImage = gcnew Bitmap("backgroundimage.png");
		bufferImage = gcnew Bitmap(Width, Height);
		bufferGraphics = Graphics::FromImage(bufferImage);

		rGen = gcnew Random();
		rGen->Next(100);

		spriteList = gcnew SpriteList();

		for (int i = 0; i < 10; i++)
		{
			count++;
			Sprite^ newSprite = gcnew Sprite(bufferGraphics, spriteSheet, 8, rGen);
			spriteList->addSprite(newSprite);
		}
	}
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) 
	{
		//bufferGraphics->FillRectangle(backgroundBrush, 0, 0, Width, Height);
		bufferGraphics->DrawImage(pixelBackgroundImage, 0, 0, Width, Height);

		spriteList->moveSprites();
		spriteList->drawSprites();
		spriteList->wanderSprites();
		spriteList->updateSprites();

		graphics->DrawImage(bufferImage, 0, 0);

		/*sprite->Erase();
		sprite->UpdateFrame();
		sprite->Move();
		sprite->Wander();
		sprite->Draw();
		label1->Text = count.ToString();*/
	}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		timer1->Enabled = true;
	}
	private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
	}
};
}
