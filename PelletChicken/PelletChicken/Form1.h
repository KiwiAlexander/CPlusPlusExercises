/* ---------------------------------------------------
	AlexPhillips
	5/08/2016
	RainbowChicken - Practical 3.1 BIT year 2 Programming 4
   --------------------------------------------------- */ 

#pragma once

#include "Pellet.h"
#include "PelletList.h"

namespace PelletChicken {

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
	private: System::Windows::Forms::Label^  label1;
	protected:
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->ForeColor = System::Drawing::SystemColors::Control;
			this->label1->Location = System::Drawing::Point(13, 13);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(35, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"label1";
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &Form1::timer1_Tick);
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.BackgroundImage")));
			this->pictureBox1->Location = System::Drawing::Point(320, 443);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(62, 55);
			this->pictureBox1->TabIndex = 1;
			this->pictureBox1->TabStop = false;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Black;
			this->ClientSize = System::Drawing::Size(790, 510);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->label1);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::Form1_KeyDown);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		Random^ rGen;
		Graphics^ mainCanvas;
		Graphics^ bufferGraphics;
		Bitmap^ bufferImage;
		Pellet^ pellet;
		PelletList^ pelletlist;
		int count;
		Brush^ backgroundBrush;

	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e)  // Setting up form position, buffergraphics and pellets
	{
		Form1::Left = 0;
		Form1::Top = 0;
		rGen = gcnew Random();
		
		backgroundBrush = gcnew SolidBrush(Color::Black);
		mainCanvas = CreateGraphics();
		bufferImage = gcnew Bitmap(Width, Height);
		bufferGraphics = Graphics::FromImage(bufferImage);


		pelletlist = gcnew PelletList();
		count = 0;
		timer1->Enabled;
	}
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) //running pelletlist methods on each timer tick
	{
		bufferGraphics->FillRectangle(backgroundBrush, 0, 0,Width,Height);
		pelletlist->movePellets();
		pelletlist->drawPellets();
		pelletlist->deleteAllDeadPellets();
		count = pelletlist->countPellets();
		label1->Text = count.ToString();
		mainCanvas->DrawImage(bufferImage, 0, 0);
	}
	private: System::Void Form1_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) //using keypresses to move picturebox and creating a pellet
	{
		if (e->KeyData == Keys::Left)
		{
			pictureBox1->Left -= 10;
		}
		if (e->KeyData == Keys::Right)
		{
			pictureBox1->Left += 10;
		}
		if (e->KeyData == Keys::Space)
		{
			Pellet^ newPellet = gcnew Pellet(pictureBox1->Left + (pictureBox1->Width / 2), pictureBox1->Top - PELLET_DIAMETER, bufferGraphics, rGen);
			pelletlist->addPellet(newPellet);
			count = count + 1;
		}
	}
	};
}
