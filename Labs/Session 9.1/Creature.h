#pragma once
#include "thing.h"

public enum ECreatureState {WANDERING, EATING, ORIENTING};


ref class Creature : public Thing
{
private:
	static const int eatingTime = 10;
	static const int wanderingLimit = 100;
		
	ECreatureState creatureState;
	int sensingRange;
	int eatingTicks;
	int wanderingTime;
	int wanderingTicks;

	int myFoodIndex;

public:
	Creature(Graphics^ startcanvas, Random^ startRandom, int startworldWidth, int startworldHeight,String^ imageFileName);

	// FSM Methods
	void UpdateState(array<Thing^>^ foodInWorld, array<Thing^>^ obstaclesInWorld);
	void PerformAction();

	// Given an array of Thing^ returns the index of the first element that is within the Creature's sensingRange
	// It can use this method to find Food or Obstacle within range (note the input args to UpdateState)
	int FindNearIndex(array<Thing^>^ otherGuys);
};
