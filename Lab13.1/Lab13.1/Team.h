#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

#include "Sport.h"
#include "Person.h"

ref class Team
{
private:

	Person^ positionOne;
	Person^ positionTwo;
	Person^ positionThree;

public:
	Team(Person^ startCyclist, Person^ startRunner, Person^ startSwimmer);

	Sport^ getPositionOne();
	Sport^ getPositionTwo();
	Sport^ getPositionThree();
};

