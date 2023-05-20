#pragma once
#include <iostream>
#pragma warning (disable:4996)
class CarPart
{
private:
	static unsigned idRef;
	unsigned id;
	char* manufacturer;
	char* description;

public:
	CarPart();
	CarPart(const char*, const char*);
	CarPart(const CarPart&);
	CarPart& operator=(const CarPart&);
	~CarPart();

	unsigned getId() const
	{
		return id;
	}
	const char* getManufacturer() const
	{
		return manufacturer;
	}
	const char* getDescription() const
	{
		return description;
	}

	void freeCarPartMemory();

	void print() const;
};

