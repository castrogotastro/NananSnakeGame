#include "FVector2.h"

FVector2::FVector2(int InX, int InY) :
	mX(InX), mY(InY)
{
}

FVector2::FVector2(const FVector2& InFVector2)
	:mX(InFVector2.mX), mY(InFVector2.mY)
{
}
