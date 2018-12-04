#pragma once

namespace Practical12Components {

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
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::ListBox^  listBox1;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::Button^  button6;
	private: System::Windows::Forms::PictureBox^  pictureBox2;
	private: System::Windows::Forms::Button^  button7;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::ComponentModel::IContainer^  components;
	protected:

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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(13, 13);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"button1";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(94, 46);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 20);
			this->textBox1->TabIndex = 1;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(13, 43);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 2;
			this->button2->Text = L"button2";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(13, 73);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 23);
			this->button3->TabIndex = 3;
			this->button3->Text = L"button3";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->Location = System::Drawing::Point(94, 73);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(120, 95);
			this->listBox1->TabIndex = 4;
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(13, 171);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(75, 23);
			this->button4->TabIndex = 5;
			this->button4->Text = L"button4";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Form1::button4_Click);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(13, 201);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(75, 23);
			this->button5->TabIndex = 6;
			this->button5->Text = L"button5";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &Form1::button5_Click);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(94, 201);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(100, 20);
			this->textBox2->TabIndex = 7;
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::SystemColors::HotTrack;
			this->pictureBox1->Location = System::Drawing::Point(200, 201);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(100, 50);
			this->pictureBox1->TabIndex = 8;
			this->pictureBox1->TabStop = false;
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(13, 258);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(75, 23);
			this->button6->TabIndex = 9;
			this->button6->Text = L"button6";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &Form1::button6_Click);
			// 
			// pictureBox2
			// 
			this->pictureBox2->Location = System::Drawing::Point(95, 258);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(125, 123);
			this->pictureBox2->TabIndex = 10;
			this->pictureBox2->TabStop = false;
			// 
			// button7
			// 
			this->button7->Location = System::Drawing::Point(13, 404);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(75, 23);
			this->button7->TabIndex = 11;
			this->button7->Text = L"button7";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &Form1::button7_Click);
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &Form1::timer1_Tick);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(484, 462);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->listBox1);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button1);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		int listcount;
		int boxmove;
		int dragon;
		int x, y, size;
		int color;
		Random^ rGen;

		private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e)
		{
			listcount = 1;
			dragon = 1;
			color = 1;
			rGen = gcnew Random();
		}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		if (button1->Left + button1->Width >= Width)
		{
			button1->Text = "TooBig!";
		}
		else
		{
			button1->Width = button1->Width + 5;
		}
	}
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		button2->Text = textBox1->Text;
	}

	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		listBox1->Items->Add("This is line" + listcount);
		listcount++;
	}
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) 
{
	if (button4->Text == "On")
	{
		button4->Text = "Off";
	}
	else
	{
		button4->Text = "On";
	}
}
private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) 
{
	boxmove = Convert::ToInt16(textBox2->Text);
	for (int i = 0; i < boxmove; i++)
	{
		pictureBox1->Left = pictureBox1->Left + boxmove;
		System::Threading::Thread::Sleep(100);
	}
}
private: System::Void button6_Click(System::Object^  sender, System::EventArgs^  e) 
{
	while (dragon <= 8)
	{
		pictureBox2->Image = Image::FromFile("Dragon" + Convert::ToString(dragon) + ".bmp");
		dragon++;
		Application::DoEvents();
		System::Threading::Thread::Sleep(100);
	}
	dragon = 1;
}
private: System::Void button7_Click(System::Object^  sender, System::EventArgs^  e) 
{
	timer1->Enabled = true;
}
private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) 
{
	Graphics^ mainCanvas = CreateGraphics();
	Brush^ blackbrush = gcnew SolidBrush(Color::Black);
	Brush^ greenbrush = gcnew SolidBrush(Color::Green);
	Brush^ bluebrush = gcnew SolidBrush(Color::Blue);
	Brush^ redbrush = gcnew SolidBrush(Color::Red);
	Brush^ yellowbrush = gcnew SolidBrush(Color::Yellow);

	x = rGen->Next(500);
	y = rGen->Next(500);
	size = rGen->Next(100);

	switch (color)
	{
	case 1:
		mainCanvas->FillEllipse(greenbrush, x, y, size, size);
		break;
	case 2:
		mainCanvas->FillEllipse(bluebrush, x, y, size, size);
		break;
	case 3:
		mainCanvas->FillEllipse(redbrush, x, y, size, size);
		break;
	case 4:
		mainCanvas->FillEllipse(yellowbrush, x, y, size, size);
		break;
	default:
		break;
	}
	if (color < 4)
	{
		color++;
	}
	else
	{
		color = 1;
	}

}
};
}
