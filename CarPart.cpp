#include "CarPart.h"

unsigned CarPart::idRef = 0;

CarPart::CarPart()
{
	char* temp = nullptr;
	char* temp2 = nullptr;
	try
	{
		temp = new char[strlen("DefaultManufacturer") + 1];
		temp2 = new char[strlen("DefaultDescription") + 1];
	}
	catch (const std::bad_alloc error)
	{ 
		if(temp)
		delete[] temp;

		throw error;
	}

	idRef++;
	id = idRef;
	strcpy(temp, "DefaultManufacturer");
	manufacturer = temp;
	strcpy(temp2, "DefaultDescription");
	description = temp2;
}

CarPart::CarPart(const char* manufacturer, const char* description)
{
	char* tempMan = new char[strlen(manufacturer) + 1];
	char* tempDesc = new (std::nothrow) char[strlen(description) + 1];

	if (!tempDesc)
	{
		delete[] tempMan;
		std::bad_alloc exeption;
		throw exeption;
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
	char* tempMan = new char[strlen(other.manufacturer) + 1];
	char* tempDesc = new (std::nothrow) char[strlen(other.description) + 1];
	if (!tempDesc)
	{
		delete[]tempMan;
		std::bad_alloc exeption;
		throw exeption;
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

	char* tempMan = new char[strlen(other.manufacturer) + 1];
	char* tempDesc = new (std::nothrow) char[strlen(other.description) + 1];
	if (!tempDesc)
	{
		delete[] tempMan;
		std::bad_alloc exeption;
		throw exeption;
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
