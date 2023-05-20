#pragma once
#include "CarPart.h"
class Accumulator : public CarPart
{
private:
	unsigned capacity;
	int* batteryId;
	size_t sizeOfBatteryId;
public:
	Accumulator();
	Accumulator(const char*, const char*, unsigned, const int*, size_t);
	Accumulator(const Accumulator&);
	Accumulator& operator=(const Accumulator&);
	~Accumulator();

	friend std::ostream& operator<<(std::ostream&, const Accumulator&);
};