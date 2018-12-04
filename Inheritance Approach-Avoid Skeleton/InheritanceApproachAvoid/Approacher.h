#pragma once

#include "SimpleSprite.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

ref class Approacher : public SimpleSprite
{
public:
	Approacher(Graphics^ offScreenCanvas, Bitmap^ redShipBitmap, int shipFrames, Random^ rGen, int shipSpeed, Rectangle backgroundRectangle);
	virtual void orient(SimpleSprite^ target) override;
};