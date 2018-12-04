#include "Sprite.h"
#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

ref class SpriteList
{
private:
	Sprite^ head;
	Sprite^ tail;
public:
	SpriteList(void);
	void addSprite(Sprite^ newSprite);
	void deleteOneSprite(Sprite^ SpriteToDelete);
	void deleteAllDeadSprites();
	void moveSprites();
	void drawSprites();
	void wanderSprites();
	void updateSprites();
	int countSprites();
	Sprite^ checkCollectionSprites(Sprite^ otherSprite);
};

