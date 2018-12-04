#include "Creature.h"


Creature::Creature(Graphics^ startcanvas, Random^ startRandom, int startworldWidth, int startworldHight, String^ imageFileName)
	: Thing(startcanvas, startRandom, startworldWidth, startworldHight,imageFileName)
{
	creatureState = WANDERING;
	wanderingTicks = 0;
	wanderingTime = 0;

	sensingRange = 25;
	myFoodIndex = 0;
}

void Creature::UpdateState(array<Thing^>^ foodInWorld, array<Thing^>^ obstaclesInWorld)
{
	switch (creatureState)
	{
	case WANDERING:
		int nearFood = FindNearIndex(foodInWorld);
		int nearObstacle = FindNearIndex(obstaclesInWorld);
		if (nearFood != -1)
		{
			eatingTicks = 0;
			creatureState = EATING;
		}
		else if (nearObstacle != -1)
		{
			creatureState = ORIENTING;
		}
		break;
	case EATING:
		eatingTicks++;
		if (foodInWorld[index]->SetIsAlive(false));
		{
			if (radius < 64)
			{
				radius += 2;
				sensingRange = radius * 2;
			}
			wanderingTicks = 0;
			creatureState = WANDERING;
		}
		break;
	case ORIENTING:
		break;
	default:
		break;
	}
}

void Creature::PerformAction()
{
	switch (creatureState)
	{
	case WANDERING:
		Move();
		wanderingTicks++;
		if (wanderingTicks > wanderingTime)
		{
			wanderingTicks = 0;
			ChangeRandomdirection();
		}
		break;
	case EATING:
		eatingTicks++;
		break;
	case ORIENTING:
		location.X -= direction.X;
		location.Y -= direction.Y;
		break;
	default:
		break;
	}
}

int Creature::FindNearIndex(array<Thing^>^ otherGuys)
{
	return 0;
}
