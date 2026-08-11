#pragma once
#include "AActor.h"
#include <vector>

class GameBoard;

class Snake : public AActor
{
public:
	Snake(FVector2 InLocation, char InIconHead, char InIconTail, const GameBoard& InGameBoard);

private:

	char mTailIcon;

public:
	std::vector<FVector2> mTailLocations;
};

