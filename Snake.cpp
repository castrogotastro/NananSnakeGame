#include "Snake.h"
#include "GameBoard.h"

Snake::Snake(FVector2 InLocation, char InIconHead, char InIconTail, const GameBoard& InGameboard)
	: AActor(InLocation, InIconHead), mTailIcon(InIconTail)
{
	if (InLocation.mX <= 0 || InLocation.mX >= InGameboard.GetWidth())
	{
		SetLocationX(InGameboard.GetWidth() / 2);
	}

	if (InLocation.mY <= 0 || InLocation.mY >= InGameboard.GetHeight())
	{
		SetLocationY(InGameboard.GetHeight() / 2);
	}
	AddToTail();
	AddToTail();
	AddToTail();
}

char Snake::GetIconTail()
{
	return mTailIcon;
}

void Snake::AddToTail()
{
	FVector2 tailLocation;
	if (mTailLocations.empty() == true) //if vector is empty, use head as start location
	{
		tailLocation = FVector2(GetLocation().mX - 1, GetLocation().mY);
	}
	else
	{
		tailLocation = mTailLocations.back();
		tailLocation.mX -= 1;
	}
	mTailLocations.emplace_back(tailLocation);
}

int Snake::GetTailLength()
{
	return mTailLocations.size();
}

void Snake::MoveTail(FVector2& InOldHeadLocation)
{
	FVector2 nextLocation = InOldHeadLocation;

	FVector2 previousLocation;
	for (int i = 0; i < GetTailLength(); i++)
	{
		//save previousLocation
		previousLocation = mTailLocations[i];

		//Update location
		mTailLocations[i] = nextLocation;

		//change next location
		nextLocation = previousLocation;
	}
}



//AActor			X		Y		back		vector size			Vector indexes
// HEAD				5		6		
//tail index 0		4		6		n/a			empty				n/a
//tail index 1		3		6		index 0		1					{0}
//tail index 2		2		6		index 1		2					{0,1}
//tail index 3		1		6		index 2		3					{0,1, 2}




