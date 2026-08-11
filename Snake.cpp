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
}




