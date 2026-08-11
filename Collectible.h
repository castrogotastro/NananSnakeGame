#pragma once
#include "AActor.h"
class Collectible : public AActor
{
public:
	Collectible() = delete;
	Collectible(FVector2 InLocation, char InIcon='@');

private:
	bool mHasBeenCollected = false;

public:
	bool GetHasBeenCollected();
	void SetHasBeenCollected(bool InHasBeenCollected);
};

