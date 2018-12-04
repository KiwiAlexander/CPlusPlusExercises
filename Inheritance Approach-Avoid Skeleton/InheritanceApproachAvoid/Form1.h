#pragma once

#include "SimpleSprite.h"
#include "SpriteList.h"
#include "Approacher.h"
#include "Avoider.h"


namespace InheritanceApproachAvoid {

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
	private: System::Windows::Forms::Button^  btnJump;

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
			this->btnJump = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &Form1::timer1_Tick);
			// 
			// btnJump
			// 
			this->btnJump->Location = System::Drawing::Point(26, 30);
			this->btnJump->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->btnJump->Name = L"btnJump";
			this->btnJump->Size = System::Drawing::Size(188, 34);
			this->btnJump->TabIndex = 0;
			this->btnJump->Text = L"Blobbo Jump";
			this->btnJump->UseVisualStyleBackColor = true;
			this->btnJump->Click += gcnew System::EventHandler(this, &Form1::btnJump_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(10, 24);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(2378, 1045);
			this->Controls->Add(this->btnJump);
			this->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->Name = L"Form1";
			this->Text = L"Inheritance";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->ResumeLayout(false);

		}
#pragma endregion


		///////////////////////////////////////////////////////////////////////////////////////////////
		// Form class data members (pseudo-globals)
		///////////////////////////////////////////////////////////////////////////////////////////////
		Rectangle backgroundRectangle;
		Brush^ backgroundBrush;
		Graphics^ mainCanvas;
		Bitmap^ offScreenBuffer;
		Graphics^ offScreenCanvas;
		Random^ rGen;
		SpriteList^ shipList;
		SimpleSprite^ blobbo;
		Rectangle blobboTerritory;

		///////////////////////////////////////////////////////////////////////////////////////////////
		// Syntactic alternative for defining system parameter constants.
		///////////////////////////////////////////////////////////////////////////////////////////////

		const int blobboSpeed = 4;
		const int shipSpeed = 3;
		const int shipCount = 20;

///////////////////////////////////////////////////////////////////////////////////////////////
// All initialisation takes place in the Form_Load
///////////////////////////////////////////////////////////////////////////////////////////////
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e)
	{
		Left = 0;
		Top = 0;
		Width = 1920;
		Height = 1080;

		// Create common elements
		offScreenBuffer = gcnew Bitmap(Width, Height);
		offScreenCanvas = Graphics::FromImage(offScreenBuffer);
		mainCanvas = CreateGraphics();
		backgroundRectangle = Rectangle(0, 0, Width, Height);
		backgroundBrush = gcnew SolidBrush(Color::Black);
		rGen = gcnew Random();

		// Create blobbo
		Bitmap^ blobboBitmap = gcnew Bitmap("images/Blobbo.bmp");
		blobboBitmap->MakeTransparent(blobboBitmap->GetPixel(0, 0));

		// Keep Blobbo away from the edges. Illustrates the approach-avoid better
		// He starts in edgeBuffer from the left and top, and end edgeBuffer from the right and bottom.
		// Thus the territory width is screenWidth - 2*edgeBuffer. That is, you lose edgeBuffer at both sides.
		// Similarly for territory height
		int blobboEdgeBuffer = 100;
		blobboTerritory = Rectangle(blobboEdgeBuffer, blobboEdgeBuffer, Width - (2* blobboEdgeBuffer), Height - (2 * blobboEdgeBuffer));
		blobbo = gcnew SimpleSprite(offScreenCanvas, blobboBitmap, 8, rGen, blobboSpeed, blobboTerritory);

		//Make sure blobbo starts in his territory
		int blobboStartX = blobboTerritory.Left + rGen->Next(blobboTerritory.Width);
		int blobboStartY = blobboTerritory.Top + rGen->Next(blobboTerritory.Height);
		blobbo->setXPos(blobboStartX);
		blobbo->setYPos(blobboStartY);

		// Create and populate the linked list of ships.
		shipList = gcnew SpriteList();
		// Creates and adds mixture of approachers and avoiders. Returns list. See method code below.
		shipList = makeShips(shipCount);	


	} // end Form_Load

///////////////////////////////////////////////////////////////////////////////////////////////
// At each timer tick, the background is repainted black.
//
// Then the shipList's cycleSprites(Sprite^ target) method is called. The cycle
// consists of the following calls to each node in the list: 1) orient to target 2) move 
// 3) check for boundary collision and respond if needed 4) update frame and 5) draw. 
// Blobbo is passed in as the target argument.
//
// Blobbo's animation cycle is also run by direct commands to the Blobbo SimpleSprite instance.
//
// Finally, the offscreen buffer bitmap is blitted to the Form's canvas.
///////////////////////////////////////////////////////////////////////////////////////////////
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e)
	{
		offScreenCanvas->FillRectangle(backgroundBrush, backgroundRectangle);

		// cycleSprites accepts a target for those sprite classes who orient (base case is empty code body)
		shipList->cycleSprites(blobbo);

		blobbo->wander();
		if (blobbo->ranIntoWorldEdge())
			blobbo->dealWithEdgeCollision();
		blobbo->updateFrame();
		blobbo->draw();

		mainCanvas->DrawImage(offScreenBuffer, 0, 0);
	}

///////////////////////////////////////////////////////////////////////////////////////////////
// Randomly moves Blobbo, and recreates the list of ships.
///////////////////////////////////////////////////////////////////////////////////////////////

	private: System::Void btnJump_Click(System::Object^  sender, System::EventArgs^  e)
	{
		//Make sure blobbo starts in his territory. 
		int blobboStartX = blobboTerritory.Left + rGen->Next(blobboTerritory.Width);
		int blobboStartY = blobboTerritory.Top + rGen->Next(blobboTerritory.Height);
		blobbo->setXPos(blobboStartX);
		blobbo->setYPos(blobboStartY);

		shipList = makeShips(shipCount);
	}

///////////////////////////////////////////////////////////////////////////////////////////////
// Creates and returns a SpriteList^ filled with a randomly determined mixture of Avoider and
// Approacher instances. 
///////////////////////////////////////////////////////////////////////////////////////////////

	private: SpriteList^ makeShips(int nShipsToMake)
	{
		SpriteList^ returnShipList = gcnew SpriteList();

		SimpleSprite^ newShip;
		int shipFrames = 40;
		// Create ship images
		Bitmap^ redShipBitmap = gcnew Bitmap("images/redShip.bmp");
		redShipBitmap->MakeTransparent(redShipBitmap->GetPixel(0, 0));
		Bitmap^ yellowShipBitmap = gcnew Bitmap("images/yellowShip.bmp");

		// For each ship, determine stochastically whether it is an Avoider or an Approacher
		// Since the list holds the parent class type, it can hold any child instance.
		for (int s = 0; s < nShipsToMake; s++)
		{
			int shipColour = rGen->Next(2);	// if 1, make an avoider (yellow) if 0 make an approacher (red)
			if (shipColour == 1)
			{
				newShip = gcnew Avoider(offScreenCanvas, yellowShipBitmap, shipFrames, rGen, shipSpeed, backgroundRectangle);	// 40 frames
			}
			else
			{
				newShip = gcnew Approacher(offScreenCanvas, redShipBitmap, shipFrames, rGen, shipSpeed, backgroundRectangle);
			}

			// Scatter ships about
			newShip->setXPos(rGen->Next(100, Width - 100));
			newShip->setYPos(rGen->Next(100, Height - 100));

			// Get the animations out of phase for a more realistic look
			newShip->setCurrentFrame(rGen->Next(shipFrames));

			// Add this ship to the list
			returnShipList->addSprite(newShip);
		} // end for nShipsToMake

		return returnShipList;
	} // end makeShips

};
}
