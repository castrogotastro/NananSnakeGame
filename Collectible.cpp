#include "Collectible.h"

Collectible::Collectible(FVector2 InLocation, char InIcon)
	: AActor(InLocation, InIcon)
{
}

Collectible::Collectible(const Collectible& InCollectibleRightOperand)
	: AActor(InCollectibleRightOperand.GetLocation(), InCollectibleRightOperand.GetIcon()), 
	mHasBeenCollected(InCollectibleRightOperand.mHasBeenCollected)
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
