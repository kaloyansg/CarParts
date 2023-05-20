#pragma once
#include "CarPart.h"
class Tire : public CarPart
{
private:
	unsigned width;
	unsigned profile;
	unsigned diameter;

public:
	Tire();
	Tire(const char*, const char*, unsigned, unsigned, unsigned);
};

