#pragma once

#include "Pond.h" // circular depdency. See forward declaration
ref class Pond;

// Orientation practical version. Only two states. No FSM

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


//==================================================================================
#define SEARCHING  0		// Default state. Wanders around semi-randomly
#define SPAWNING   1		// Bug reproducing
#define BABY       2		// Juvenile bug. Follows parent

ref class Bug
{
	public:

	property int bugState;		// Current
	property int xPos;			// X position
	property int yPos;			// Y position
	property int xVel;			// Horizontal velocity
	property int yVel;			// Vertical velocity
	property int speed;			// hypotenuse
	property int team;			// Bug's team
	property int diameter;		// How big is the bug
	property int nucleus;		// How big is the bug's brain
	property Rectangle territory;	// In simplest version, bugs have the whole canvas to move
	
	property int health;		// Current health. May not be used in this practical
	property int litterSize;	// Simluation parameter. Applies to all members of the same team

	property Bug^ parent;		// Baby bugs orient to their parent
	property Pond^ homePond;

	property int changeDirectionCount;			// Counter for changing direction
	property int spawnCount;						// Counter for spawning
	property int maturationCount;					// Counter for becoming an adult
	

	property Color teamColor;	// Color to draw bug
	property Graphics^ bugCanvas;
	property Random^ rGen;
	
	// Assorted simulation parameters
	const int defaultMaxLitterSize = 5;
	const int defaultVelocity = 5;
	const int defaultVelocityVariability = 5;
	const int defaultStepsToDirectionChange = 20;
	const int defaultDistanceFromEdge = 200;
	const int defaultStepsToSpawn = 50;
	const int defaultBabyDiameter = 10;
	const int defaultAdultDiameter = 20;
	const int defaultBabyNucleus = 2;
	const int defaultAdultNucleus = 5;
	const int defaultBabyDistance = 3;
	const int defaultMaturationCount = 100;
	const int defaultSpawnProbability = 10;

public:
	 Bug(int startTeam, Pond^ startHomePond, Graphics^ startCanvas, Random^ startRGen, int worldWidth, int worldHeight);

	 void runBugCycle();

     void draw();

     void pointMeAt(Bug^ otherBug);		// Adjusts xVel and yVel to orient toward otherBug
     void spawn();				// Adds new bugs if there is space in the pond
	 void move();
	 void boundsCheck();		// Everybody bounces

};
