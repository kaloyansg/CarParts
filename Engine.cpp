#include "Engine.h"

Engine::Engine() : CarPart()
{
	horsePower = 0;
}

Engine::Engine(const char* manufactorer, const char* description, unsigned horsepower) : CarPart(manufactorer,description)
{
	this->horsePower = horsepower;
}
