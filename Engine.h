#pragma once
#include "CarPart.h"
class Engine : public CarPart
{
private:
	unsigned horsePower;
public:
	Engine();
	Engine(const char*, const char*, unsigned);
};