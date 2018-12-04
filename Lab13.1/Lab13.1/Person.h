#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

#include "Sport.h"

ref class Person
{
private:
	
	String^ name;
	Sport^ sportsPlayedOne;
	Sport^ sportsPlayedTwo;

public:
	Person(String^ name, Sport^ startSportsPlayedOne);
	Person(String^ name, Sport^ startSportsPlayedOne, Sport^ startSportsPlayedTwo);

	String^ getName();
	void setName(String^ newName);

	Sport^ getSportOne();
	Sport^ getSportTwo();
};

