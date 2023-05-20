#include "Accumulator.h"

Accumulator::Accumulator() : CarPart()
{
	int* temp = nullptr;
	try 
	{
		temp = new int[1];
	}
	catch(const std::bad_alloc error)
	{
		freeCarPartMemory();
		throw error;
	}
	temp[0] = 0;
	batteryId = temp;
	capacity = 0;
	sizeOfBatteryId = 1;
}

Accumulator::Accumulator(const char* manufactorer, const char* description,
	unsigned capacity, const int* batteryId, size_t sizeOfBatteryId) : CarPart(manufactorer, description)
{
	int* temp = nullptr;
	try
	{
		temp = new int[sizeOfBatteryId];
	}
	catch (const std::bad_alloc error)
	{
		freeCarPartMemory();
		throw error;
	}
	for (size_t i = 0; i < sizeOfBatteryId; i++)
	{
		temp[i] = batteryId[i];
	}
	this->batteryId = temp;
	this->capacity = capacity;
	this->sizeOfBatteryId = sizeOfBatteryId;
}

Accumulator::Accumulator(const Accumulator& other) : CarPart(other)
{
	int* temp = nullptr;
	try 
	{
		temp = new int[other.sizeOfBatteryId];
	}
	catch (const std::bad_alloc error)
	{
		freeCarPartMemory();
		throw error;
	}

	for (size_t i = 0; i < other.sizeOfBatteryId; i++)
	{
		temp[i] = other.batteryId[i];
	}
	this->batteryId = temp;
	this->capacity = other.capacity;
	this->sizeOfBatteryId = other.sizeOfBatteryId;
}

Accumulator& Accumulator::operator=(const Accumulator& other)
{
	int* temp = nullptr;
	temp = new int[other.sizeOfBatteryId];

	CarPart::operator=(other);	
	//if an exeption in CarPart::operator= is thrown, cannot come back to delete[] temp

	for (size_t i = 0; i < other.sizeOfBatteryId; i++)
	{
		temp[i] = other.batteryId[i];
	}
	delete[] this->batteryId;
	this->batteryId = temp;
	this->capacity = other.capacity;
	this->sizeOfBatteryId = other.sizeOfBatteryId;
	
	return *this;
}

Accumulator::~Accumulator()
{
	delete[] batteryId;
}

std::ostream& operator<<(std::ostream& os, const Accumulator& a)
{
	os << a.getId() << " - " << a.getManufacturer() << ", <" << a.getDescription() << "> capacity:"
		<< a.capacity << ", battery ID: ";
	for (size_t i = 0; i < a.sizeOfBatteryId; i++)
	{
		os << a.batteryId[i];
	}
	return os;
}
