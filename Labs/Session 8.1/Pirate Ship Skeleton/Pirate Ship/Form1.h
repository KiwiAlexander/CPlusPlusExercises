#pragma once


namespace PirateShip {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
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
	private: System::Windows::Forms::PictureBox^  pbxPirateShip;
	protected: 

	private: System::Windows::Forms::TrackBar^  tbAim;

	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TrackBar^  tbPower;

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->pbxPirateShip = (gcnew System::Windows::Forms::PictureBox());
			this->tbAim = (gcnew System::Windows::Forms::TrackBar());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->tbPower = (gcnew System::Windows::Forms::TrackBar());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbxPirateShip))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->tbAim))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->tbPower))->BeginInit();
			this->SuspendLayout();
			// 
			// pbxPirateShip
			// 
			this->pbxPirateShip->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pbxPirateShip.Image")));
			this->pbxPirateShip->Location = System::Drawing::Point(671, 452);
			this->pbxPirateShip->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->pbxPirateShip->Name = L"pbxPirateShip";
			this->pbxPirateShip->Size = System::Drawing::Size(99, 99);
			this->pbxPirateShip->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pbxPirateShip->TabIndex = 0;
			this->pbxPirateShip->TabStop = false;
			// 
			// tbAim
			// 
			this->tbAim->Location = System::Drawing::Point(466, 10);
			this->tbAim->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->tbAim->Maximum = 180;
			this->tbAim->Name = L"tbAim";
			this->tbAim->Size = System::Drawing::Size(154, 50);
			this->tbAim->TabIndex = 1;
			this->tbAim->Scroll += gcnew System::EventHandler(this, &Form1::trackBar1_Scroll);
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &Form1::timer1_Tick);
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(9, 10);
			this->button1->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(71, 32);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Fire!!!";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(418, 15);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(36, 20);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Aim";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(406, 59);
			this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(62, 20);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Powder";
			// 
			// tbPower
			// 
			this->tbPower->Location = System::Drawing::Point(466, 61);
			this->tbPower->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->tbPower->Maximum = 100;
			this->tbPower->Name = L"tbPower";
			this->tbPower->Size = System::Drawing::Size(154, 50);
			this->tbPower->TabIndex = 5;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(792, 562);
			this->Controls->Add(this->tbPower);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->tbAim);
			this->Controls->Add(this->pbxPirateShip);
			this->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->Name = L"Form1";
			this->Text = L"Arrrgh, Matey";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::Form1_Paint);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbxPirateShip))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->tbAim))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->tbPower))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


		
		Graphics^ mainCanvas;
		Pen^ mainPen;
		Brush^ mainBrush;
		int cannonX;
		int cannonY;
		int cannonLength;
		int cannonWidth;
		int startCannonBallX;
		int startCannonBallY;
		int cannonBallDiameter;

		int cannonBallX;
		int cannonBallY;
		int velocityX;
		int velocityY;
		int gravity;

	 //==========================================================================================
	 //Form Events
	 //===========================================================================================

	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) 
			 {
				 // Initialisation code
				 Left = 0;
				 Top = 0;
				 Width = 800;
				 Height = 600;

				 mainCanvas = CreateGraphics();
				 mainPen = gcnew Pen(Color::Black);
				 mainPen->Width = 2;
				 mainBrush = gcnew SolidBrush(Color::Red);

				 cannonX = 125;
				 cannonY = 500;
				 cannonLength = 80;
				 cannonWidth = 20;
				 cannonBallDiameter = 20;
				 startCannonBallX = cannonX  - (cannonBallDiameter/2);
				 startCannonBallY = cannonY - (cannonBallDiameter/2);

				 cannonBallX = startCannonBallX;
				 cannonBallY = startCannonBallY ;

			 }

	private: System::Void Form1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) 
			 {
				 //Cannon animation

				 // Read from the aiming trackbar
				int rotationAngle = Convert::ToInt16(tbAim->Value);
				
				// Draw the cannonball at its current position
				mainCanvas->FillEllipse(mainBrush, cannonBallX, cannonBallY, cannonBallDiameter,cannonBallDiameter);
				
				// Draw the cannon at the specified orientation
				makeRectangle(cannonLength, cannonWidth, -rotationAngle, Point(cannonX, cannonY));
			
			 }

	private: System::Void trackBar1_Scroll(System::Object^  sender, System::EventArgs^  e) 
		 {
			 Refresh();
		 }
				 

	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) 
		 {
			 // Update the cannonball's position
			 // ADD CODE HERE

			 // Implement gravity
			 // ADD CODE HERE

			 // Redraw the screen by raising the Pain event. 
			 Refresh();	

			// Check for collisions or falling off the screen, and handle accordingly. Use the collided() 
			// method defined below, if you wish
			// ADD CODE HERE

		 }
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 // reset the cannonBall to its starting position
			cannonBallX = startCannonBallX;
			cannonBallY = startCannonBallY;

			// Read the power from the trackbar tbPower and convert to an int
			// ADD CODE HERE

			// Read the degree of rotation from trackbar tbAim and convert to an int
			// ADD CODE HERE
		

			// Use the power and orientation to compute the starting velocities for the cannonball
			// ADD CODE HERE

			// Set a sensible value for gravity
			gravity = 2;
			 
			// Turn on the timer.
			timer1->Enabled = true;
		 }

//==========================================================================================
// Checks to see if the area of the cannonBall shape overlaps the area of the ship image	 
//===========================================================================================
bool collided()
{
	int shipLeft = pbxPirateShip->Left;
	int shipTop = pbxPirateShip->Top;
	int shipWidth = pbxPirateShip->Width;
	int shipHeight = pbxPirateShip->Height;
	Rectangle cannonBallRectangle = Rectangle(cannonBallX, cannonBallY, cannonBallDiameter, cannonBallDiameter);

	bool collided = false;

	for (int x = shipLeft; x <= shipLeft + shipWidth; x++)
		for (int y = shipTop; y <= shipTop + shipHeight; y++)
		{
			if (isInRectangle(Point(x,y), cannonBallRectangle))
			{
				collided = true;
				break;
			}
		}
	return collided;
}

//==========================================================================================
// isInRectangle(point,rectangle)	 
//===========================================================================================
bool isInRectangle(Point p, Rectangle r)
{
	bool isIn;

	if ((p.X >= r.Left) && (p.X <= r.Right) && (p.Y >= r.Top) && (p.Y <= r.Bottom))
		isIn = true;
	else
		isIn = false;

	return isIn;
}
//==========================================================================================
// Trig Utiliies
//===========================================================================================

	void rotatePoint(Point^ inputPoint, int angle)
	 {
		 Point^ tempPoint = gcnew Point();

		double radiansAngle = angle * 0.01745;

		tempPoint->X = (int)inputPoint->X * Math::Cos(radiansAngle) - inputPoint->Y * Math::Sin(radiansAngle);
		tempPoint->Y = (int)inputPoint->X * Math::Sin(radiansAngle) + inputPoint->Y * Math::Cos(radiansAngle);

		inputPoint->X = tempPoint->X;
		inputPoint->Y = tempPoint->Y;
	 }


	 void translatePoint(Point^ inputPoint, int xDelta, int yDelta)
	 {
		 inputPoint->X += xDelta;
		 inputPoint->Y += yDelta;
	 }

	 void makeRectangle(int length, int depth, int rotationAngle, Point centrePoint)
	 {
		 array<Point>^ rectanglePoints = gcnew array<Point>(4);
		 int halfDepth = (int)depth/2;
		 Point^ tempPoint = gcnew Point();

		 // Rotate around center of left edge (end of cannon)
		 // make upperLeft corner

		 tempPoint->X = 0;
		 tempPoint->Y = -halfDepth;
		 rotatePoint(tempPoint, rotationAngle);
		 translatePoint(tempPoint, centrePoint.X, centrePoint.Y);
		 rectanglePoints[0].X = tempPoint->X;
		 rectanglePoints[0].Y = tempPoint->Y;

		 // make upperRight corner
		 tempPoint->X = length;
		 tempPoint->Y = -halfDepth;
		 rotatePoint(tempPoint, rotationAngle);
		 translatePoint(tempPoint, centrePoint.X, centrePoint.Y);
		 rectanglePoints[1].X = tempPoint->X;
		 rectanglePoints[1].Y = tempPoint->Y;
		 
		 // make lowerRight corner
		 tempPoint->X = length;
		 tempPoint->Y = halfDepth;
		 rotatePoint(tempPoint, rotationAngle);
		 translatePoint(tempPoint, centrePoint.X, centrePoint.Y);
		 rectanglePoints[2].X = tempPoint->X;
		 rectanglePoints[2].Y = tempPoint->Y;

		 // make lowerLeft corner
		 tempPoint->X = 0;
		 tempPoint->Y = halfDepth;
		 rotatePoint(tempPoint, rotationAngle);
		 translatePoint(tempPoint, centrePoint.X, centrePoint.Y);
		 rectanglePoints[3].X = tempPoint->X;
		 rectanglePoints[3].Y = tempPoint->Y;

		 //draw the rectangle
		 mainCanvas->DrawPolygon(mainPen, rectanglePoints);

	 }



};
}

