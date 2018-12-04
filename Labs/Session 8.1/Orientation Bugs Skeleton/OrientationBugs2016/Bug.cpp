
#include "Bug.h"

Bug::Bug(int startTeam, Pond^ startHomePond, Graphics^ startCanvas, Random^ startRGen, int worldWidth, int worldHeight)
{

	// store input parameters
	team = startTeam; 
	bugCanvas = startCanvas;
	rGen = startRGen;
	homePond = startHomePond;
	territory = Rectangle(0, 0, worldWidth, worldHeight);

	// set up defaults
	bugState = SEARCHING;
	health = rGen->Next(50) + 50;    // Health between 0 and 100%. Determines the intensity of their colour

	litterSize = defaultMaxLitterSize;					// Interesting to allow this to be modified in the UI

	parent = nullptr;	

	// Start with random speed and direction
	speed = rGen->Next(defaultVelocityVariability) + defaultVelocity;
	double orientation = rGen->Next(360) * 0.01745;
	xVel = (int)(Math::Cos(orientation) * speed);
	yVel = (int)(Math::Sin(orientation) * speed);
	
	changeDirectionCount = defaultStepsToDirectionChange;			// go this way for 20 ticks
	spawnCount = defaultStepsToSpawn;								// spawn every 100 ticks
    
	// Arrange the bugs in two teams, one on the left and one on the right. Scattered about a bit

	int offset = (defaultDistanceFromEdge/2) + rGen->Next(defaultDistanceFromEdge);	// Distance in from the edge of the screen
	switch (team)
	{
		case 0:
			teamColor = Color::Red;
			xPos = offset;			// start on left side of screen
		break;
		case 1:
			teamColor = Color::Blue;
			xPos = worldWidth - (2* offset);	// start on right side of screen. Bring in a little extra to adjust for "upperleft corner" draw bias
      break;
	}
	yPos = rGen->Next(worldHeight);

}


void Bug::runBugCycle()
{
	// Deal with state-specific behaviours.
	// Switch on state. Use counts to decide when to change state
	switch (bugState)
	{
	case BABY:
		pointMeAt(parent);					// parent is assigned when the baby is spawned

		maturationCount--;					// Counter for becoming an adult
		if (maturationCount == 0)
		{
			bugState = SEARCHING;
		}
		break;

	case SPAWNING:
		spawn();
		bugState = SEARCHING;
		break;

	case SEARCHING:
		
		// If it's time to change direction, do so
		changeDirectionCount--;				// Counter for changing direction
		if (changeDirectionCount == 0)
		{
			changeDirectionCount = defaultStepsToDirectionChange;
			double orientation = rGen->Next(360) * 0.01745;
			xVel = (int)(Math::Cos(orientation) * speed);
			yVel = (int)(Math::Sin(orientation) * speed);
		}

		// If it's time to change to the spawning state, do so. Will spawn at next cycle
		spawnCount--;						// Counter for spawning
		if (spawnCount == 0)
		{
			spawnCount = defaultStepsToSpawn;
			bugState = SPAWNING;
		}
	} // end switch;
	
	// Regardless of state, everybody moves and everybody draws.
	move();
	draw();
}

 
//=================================================================================
//
//=================================================================================
void Bug::move()
{
	xPos += xVel;			// and move accordingly
	yPos += yVel;			// and move accordingly
	
	boundsCheck();
}
//=================================================================================
//
//=================================================================================
void Bug::boundsCheck()
{
	bool bounced = false;

	if ((xPos < territory.Left) || ((xPos + diameter) > territory.Right))
	{
		xVel *= -1;
		bounced = true;
	}
	if ((yPos < territory.Top) || ((yPos + diameter) > territory.Bottom))
	{
		yVel *= -1;
		bounced = true;
	}

	// If you bounced take a few steps to get away from the wall and avoid bounce toggle
	if (bounced)
	{
		xPos += 3 * xVel;
		yPos += 3 * yVel;
	}

}
//=================================================================================
//
//=================================================================================
void Bug::draw()
{
	//Radius equals range for all bugs

	int colourShade;
	double healthRatio;
	Color drawBodyColour;



	// Babies are always fuschia...
	if (bugState == BABY)
	{
		drawBodyColour = Color::Fuchsia;
		diameter = defaultBabyDiameter;
		nucleus = defaultBabyNucleus;
	}
	else
	{
		//get correct color
		healthRatio = health / 100.0;
		colourShade = 100 + (155 * healthRatio);		// desaturate if health is low

		switch (team)
		{
		case 0:
			drawBodyColour = Color::FromArgb(colourShade, 50, 0);
			break;
		case 1:
			drawBodyColour = Color::FromArgb(0, 50, colourShade);
			break;
		}
		diameter = defaultAdultDiameter;
		nucleus = defaultAdultNucleus;
	}

	// Create brushes
	Brush^ bugBrush = gcnew SolidBrush(drawBodyColour);
	Brush^ nucleusBrush = gcnew SolidBrush(Color::Green);

    //draw basic shape
 	bugCanvas->FillEllipse(bugBrush, xPos, yPos, diameter, diameter);
        
   // draw nucleus
	Point myCentre = Point(xPos + diameter / 2, yPos + diameter / 2);	// approximate center of bug
	bugCanvas->FillEllipse(nucleusBrush, myCentre.X, myCentre.Y, nucleus, nucleus);

}	// end draw

//=================================================================================
//=================================================================================

void Bug::pointMeAt(Bug^ otherBug)
{
	// YOUR CODE HERE
}


//=================================================================================
// CreateBabies: Create new memebers of your team up to litterSize, and adds them
// to your pond
//=================================================================================
 void Bug::spawn()
{
	// Bug will spawn with probability = defaultSpawnProbability/100
	// Interesting extension is to vary litter size and spawn prob and see how the
	// different populations grow.
	int getToSpawn = rGen->Next(100);
	if (getToSpawn < defaultSpawnProbability)
	{
		int nBabies = rGen->Next(defaultMaxLitterSize);
		for (int babyCounter = 0; babyCounter < nBabies; ++babyCounter)
		{

			Bug^ newBabyBug = gcnew Bug(team, homePond, bugCanvas, rGen, territory.Width, territory.Height);

			// everything else stays as default values set in constructor
			newBabyBug->parent = this;		// this instance is the parent
			newBabyBug->pointMeAt(this);	// baby should move toward the parent
			newBabyBug->bugState = BABY;
			newBabyBug->maturationCount = defaultMaturationCount;	// how many timer ticks you stay a baby for

			// place the baby near you...
			newBabyBug->xPos = xPos - rGen->Next(defaultBabyDistance);
			newBabyBug->yPos = yPos - rGen->Next(defaultBabyDistance);
			newBabyBug->litterSize = this->litterSize;  // fecundity is inherited

			// put the baby in the pond
			homePond->addBaby(newBabyBug);

		} // end for litter size
	}
}

