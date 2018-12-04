#pragma once

#include "Person.h"
#include "Sport.h"
#include "Team.h"

namespace Lab131 {

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
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Button^  button1;
	protected:

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
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(13, 13);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 20);
			this->textBox1->TabIndex = 0;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(13, 226);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 1;
			this->button1->Text = L"button1";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		bool teamsFormed;

		Random^ random;

		array<Person^>^ people;

		Person^ Anne;
		Person^ Bob;
		Person^ Carl;
		Person^ David;
		Person^ Ellen;
		Person^ Fred;

		Sport^ cyclist;
		Sport^ runner;
		Sport^ swimmer;

		String^ anne = "Anne";
		String^ bob = "Bob";
		String^ carl = "Carl";
		String^ david = "David";
		String^ ellen = "Ellen";
		String^ fred = "Fred";

		Team^ team;

	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) 
	{
			Form1::Top = 0;
			Form1::Left = 0;

			random = gcnew Random();
			people = gcnew array<Person^>(6);

			people[0] = Anne = gcnew Person(anne, cyclist, swimmer);
			people[1] = Bob = gcnew Person(bob, cyclist, runner);
			people[2] = Carl = gcnew Person(carl, cyclist);
			people[3] = David = gcnew Person(david, swimmer);
			people[4] = Ellen = gcnew Person(ellen, swimmer);
			people[5] = Fred = gcnew Person(fred, runner);

	}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		teamsFormed = false;
		while (teamsFormed != true)
		{

			int randomMemberOne = random->Next(6);
			int randomMemberTwo = random->Next(6);
			int randomMemberThree = random->Next(6);

			if (randomMemberOne != randomMemberTwo 
				&& randomMemberOne != randomMemberThree 
				&& randomMemberTwo != randomMemberThree 
				&& randomMemberTwo != randomMemberOne)
			{
				team = gcnew Team(people[randomMemberOne], people[randomMemberTwo], people[randomMemberThree]);
				if (team->getPositionOne() != team->getPositionTwo() 
					&& team->getPositionOne() != team->getPositionThree() 
					&& team->getPositionTwo() != team->getPositionOne() 
					&& team->getPositionTwo() != team->getPositionThree())
				{
					teamsFormed = true;
					textBox1->Text = "team";
				}
			}
		}
	}
	};
}
