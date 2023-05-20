#include "CarPart.h"

unsigned CarPart::idRef = 0;

CarPart::CarPart()
{
	char* tempMan = nullptr;
	char* tempDesc = nullptr;
	try
	{
		tempMan = new char[strlen("DefaultManufacturer") + 1];
		tempDesc = new char[strlen("DefaultDescription") + 1];
	}
	catch (const std::bad_alloc& error)
	{ 
		if(tempMan)
		delete[] tempMan;

		throw error;
	}

	idRef++;
	id = idRef;
	strcpy(tempMan, "DefaultManufacturer");
	manufacturer = tempMan;
	strcpy(tempDesc, "DefaultDescription");
	description = tempDesc;
}

CarPart::CarPart(const char* manufacturer, const char* description)
{
	char* tempMan = nullptr;
	char* tempDesc = nullptr;
	try
	{
		tempMan = new char[strlen(manufacturer) + 1];
		tempDesc = new char[strlen(description) + 1];

	}
	catch (const std::bad_alloc& error)
	{
		if (tempMan)
			delete[] tempMan;

		throw error;
	}

	idRef++;
	id = idRef;

	strcpy(tempMan, manufacturer);
	this->manufacturer = tempMan;
	strcpy(tempDesc, description);
	this->description = tempDesc;
}

CarPart::CarPart(const CarPart& other)
{
	char* tempMan = nullptr;
	char* tempDesc = nullptr;
	try
	{
		tempMan = new char[strlen(other.manufacturer) + 1];
		tempDesc = new char[strlen(other.description) + 1];
	}
	catch (const std::bad_alloc& error)
	{
		if(tempMan)
		delete[]tempMan;

		throw error;
	}
	idRef++;
	id = idRef;
	strcpy(tempMan, other.manufacturer);
	this->manufacturer = tempMan;
	strcpy(tempDesc, other.description);
	this->description = tempDesc;
}

CarPart& CarPart::operator=(const CarPart& other)
{
	if (this == &other) return *this;

	char* tempMan = nullptr;
	char* tempDesc = nullptr;
	try
	{
		tempMan= new char[strlen(other.manufacturer) + 1];
		tempDesc = new char[strlen(other.description) + 1];
	}
	catch (const std::bad_alloc& error)
	{
		if (tempMan) delete[] tempMan;
		throw error;
	}

	idRef++;
	id = idRef;

	strcpy(tempMan, other.manufacturer);
	delete[] this->manufacturer;
	this->manufacturer = tempMan;

	strcpy(tempDesc, other.description);
	delete[] this->description;
	this->description = tempDesc;


	return *this;
}

CarPart::~CarPart()
{
	delete[] manufacturer;
	delete[] description;
}

void CarPart::freeCarPartMemory()
{
	delete[] manufacturer;
	delete[] description;
}

void CarPart::print() const
{
	std::cout << id << " " << manufacturer << " " << description << std::endl;
}
