#include "Pond.h"

Pond::Pond(int starBugCount, Graphics^ starPondCanvas, Random^ startRGen, int worldWidth, int worldHeight)
{
	bugCount = starBugCount;
	pondCanvas = starPondCanvas;
	rGen = startRGen;

	bugList = gcnew List<Bug^>();
	babyList = gcnew List<Bug^>();

	// Make only the starting number of bugs
	for (int i=0; i<bugCount; i++)						
	{
		// First argument assigns bug to one of two teams, determining bug colour and placement
		Bug^ newBug = gcnew Bug(rGen->Next(2), this, pondCanvas, rGen, worldWidth, worldHeight);
		bugList->Add(newBug);
		
			//bugArray[i]->setRange(rGen->Next(20) + 10);		// Start with a variety of sizes
	}
}

//==========================================================================================
//==========================================================================================
void Pond::addBaby(Bug^ baby)
{
	babyList->Add(baby);
}
//==========================================================================================
//==========================================================================================
void Pond::resetPondParameters(int starBugCount, int rStrength, int rLitter, int bStrength, int bLitter)
{
	//TODO
}
//==========================================================================================
//==========================================================================================
void Pond::drawPond()
{
	for each (Bug^ currentBug in bugList)
	{
		currentBug->draw();
	}
}
//==========================================================================================
//==========================================================================================
void Pond::cyclePond()
{
	// Prepare list to hold nay babies born this cycle
	babyList = gcnew List<Bug^>();

	// move, draw, update state of each bug. To add babies, the Bug
	// will call our addBaby method, so all babies will be store in babyList
	for each (Bug^ currentBug in bugList)
	{
		currentBug->runBugCycle();
	}

	// Now transfer the babies to the main pond list
	for each(Bug^ baby in babyList)
	{
		bugList->Add(baby);
	}
}
//==========================================================================================
//==========================================================================================
int Pond::getTeamCount(int t)
{
	int teamCount = 0;
	for each (Bug^ currentBug in bugList)
	{
		if (currentBug->team == t)
			teamCount++;
	}
	return teamCount;
}