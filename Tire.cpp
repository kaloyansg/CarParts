#include "Tire.h"

Tire::Tire() : CarPart()
{
	width = 155;
	profile = 30;
	diameter = 13;
}

Tire::Tire(const char* manufacturer, const char* description, 
	unsigned width, unsigned profile, unsigned diameter) : CarPart(manufacturer,description)
{
	if (width<155 || width>365)
	{
		throw "Width not valid";
	}
	if (profile <30 || profile>80)
	{
		throw "Profile not valid";
	}
	if (diameter <13 || diameter>21)
	{
		throw "Diameter not valid";
	}

	this->width = width;
	this->profile = profile;
	this->diameter = diameter;
}
