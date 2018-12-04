#include "Team.h"


Team::Team(Person^ startCyclist, Person^ startRunner, Person^ startSwimmer)
{
	positionOne = startCyclist;
	positionTwo = startRunner;
	positionThree = startSwimmer;
}

Sport^ Team::getPositionOne()
{
	return positionOne->getSportOne();
}
Sport^ Team::getPositionTwo()
{
	return positionTwo->getSportOne();
}
Sport^ Team::getPositionThree()
{
	return positionThree->getSportOne();
}