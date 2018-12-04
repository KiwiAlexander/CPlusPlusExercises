#pragma once

#include "SimpleSprite.h"


	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

ref class SpriteList
{
private:
    SimpleSprite^ head;
	SimpleSprite^ tail;

public:
	SpriteList(void);

	void addSprite(SimpleSprite^ newSprite);
	void cycleSprites(SimpleSprite^ target); // runs a full update, move and draw cycle
};




 
