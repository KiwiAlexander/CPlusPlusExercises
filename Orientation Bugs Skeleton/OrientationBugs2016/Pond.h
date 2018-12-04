#pragma once

#include "Bug.h" // circular depdency. See forward declaration
ref class Bug;

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic;		// contains the .NET list class
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;



ref class Pond
{

private:
	List<Bug^>^ bugList;	//.NET generic linked list
	List<Bug^>^ babyList;	// Can't modify a list inside a foreach loop, so must gather up all the babies during
							// cyclePond and then add them to the main list
	int bugCount;

	Graphics^ pondCanvas;
	Random^ rGen;


public:
	Pond(int starBugCount, Graphics^ starPondCanvas, Random^ startRGen, int worldWidth, int worldHeight);


	void addBaby(Bug^ bugBaby);
	void drawPond();
	void cyclePond();
	int getTeamCount(int t);

	void resetPondParameters(int starBugCount, int rStrength, int rLitter, int bStrength, int bLitter);

};