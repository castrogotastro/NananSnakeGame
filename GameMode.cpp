#include "GameMode.h"

GameMode* GameMode::sInstance = nullptr;

GameMode::GameMode()
{
}

GameMode* GameMode::GetInstace()
{
	if (sInstance == nullptr)
	{
		sInstance = new GameMode();
	}
	return sInstance;
}
