#include "Person.h"


Person::Person(String^ startName, Sport^ startSportsPlayedOne)
{
	name = startName;
	sportsPlayedOne = startSportsPlayedOne;
}

Person::Person(String^ startName, Sport^ startSportsPlayedOne, Sport^ startSportsPlayedTwo)
{
	name = startName;
	sportsPlayedOne = startSportsPlayedOne;
	sportsPlayedTwo = startSportsPlayedTwo;
}

String^ Person::getName()
{
	return name;
}

void Person::setName(String^ newName)
{
	name = newName;
}

Sport^ Person::getSportOne()
{
	return sportsPlayedOne;
}
Sport^ Person::getSportTwo()
{
	if (sportsPlayedTwo != nullptr)
	{
		return sportsPlayedTwo;
	}
	else
	{
		return nullptr;
	}
}