#include "Sport.h"


Sport::Sport(String^ startSport)
{
	sport = startSport;
}

String^ Sport::getSport()
{
	return sport;
}

void Sport::setName(String^ newSport)
{
	sport = newSport;
}
