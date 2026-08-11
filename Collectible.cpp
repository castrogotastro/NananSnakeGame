#include "Collectible.h"

Collectible::Collectible(FVector2 InLocation, char InIcon)
	: AActor(InLocation, InIcon)
{
}

bool Collectible::GetHasBeenCollected()
{
	return mHasBeenCollected;
}

void Collectible::SetHasBeenCollected(bool InHasBeenCollected)
{
	mHasBeenCollected = InHasBeenCollected;
}
