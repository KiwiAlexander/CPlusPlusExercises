#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

ref class Sport
{
private:

	String^ sport;

public:
	Sport(String^ sport);

	String^ getSport();
	void setName(String^ newSport);
};

