#pragma once

#include "Pond.h"

namespace OrientationBugs2016 {

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
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &Form1::timer1_Tick);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1006, 721);
			this->Name = L"Form1";
			this->Text = L"Orientation Baby Bugs";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->Shown += gcnew System::EventHandler(this, &Form1::Form1_Shown);
			this->ResumeLayout(false);

		}
#pragma endregion

		Pond^ mainPond;
		Graphics^ mainCanvas;
		Graphics^ offScreenCanvas;
		Bitmap^ offScreenBuffer;
		Random^ rGen;
		Brush^ backgroundBrush;
		Rectangle canvasRectangle;

	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) 
	{
		mainCanvas = CreateGraphics();
		offScreenBuffer = gcnew Bitmap(Width, Height);
		offScreenCanvas = Graphics::FromImage(offScreenBuffer);
		rGen = gcnew Random();
		backgroundBrush = gcnew SolidBrush(Color::Black);
		canvasRectangle = Rectangle(0, 0, Width, Height);
		mainPond = gcnew Pond(10, offScreenCanvas, rGen, Width, Height);
	}
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) 
	{
		offScreenCanvas->FillRectangle(backgroundBrush, canvasRectangle);

		// move, draw and update state of all bugs in pond
		mainPond->cyclePond();

		mainCanvas->DrawImage(offScreenBuffer, 0, 0);
	}
	private: System::Void Form1_Shown(System::Object^  sender, System::EventArgs^  e) 
	{
		mainCanvas->FillRectangle(backgroundBrush, canvasRectangle);
	}
	};
}
