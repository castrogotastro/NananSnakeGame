#include "RandomNumGenerator.h"
#include <random>

int GenerateRandomValueInWidth(int InWidth)
{
	int leftStart = 1;
	int rightEnd = InWidth - 1;

	return GenerateRandomValue(leftStart, rightEnd);
}

int GenerateRandomValueInHeight(int InHeight)
{
	int topStart = 1;
	int bottomEnd = InHeight - 1;

	return GenerateRandomValue(topStart, bottomEnd);
}

int GenerateRandomValue(int InMin, int InMax)
{
	std::random_device seedNumber;
	std::mt19937  GeneratedRandomNumber(seedNumber());
	std::uniform_int_distribution<> randomNumberRange(InMin, InMax);

	int randomValue = randomNumberRange(GeneratedRandomNumber);

	return randomValue;
}
