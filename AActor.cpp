#include "AActor.h"

AActor::AActor(FVector2 InLocation, char InIcon)
    : mLocation(InLocation), mIcon(InIcon)
{
}

AActor::AActor(const AActor& InAActor)
    : mLocation(InAActor.mLocation), mIcon(InAActor.mIcon)
{
}

AActor::~AActor()
{
}

FVector2 AActor::GetLocation()
{
    return mLocation;
}

void AActor::SetLocation(FVector2 InLocation)
{
    mLocation = InLocation;
}

void AActor::SetLocationX(int InX)
{
    mLocation.mX = InX;
}

void AActor::SetLocationY(int InY)
{
    mLocation.mY = InY;
}

char AActor::GetIcon()
{
    return mIcon;
}

void AActor::Move(int InChangeX, int InChangeY)
{
    mLocation.mX += InChangeX;
    mLocation.mY += InChangeY;
}
