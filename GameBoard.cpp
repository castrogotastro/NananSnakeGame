#include "GameBoard.h"

GameBoard::GameBoard(int InWidth, int InHeight, int InScoreToWinLevel)
	:mWidth(InWidth), mHeight(InHeight), mScoreToWinLevel(InScoreToWinLevel)
{
}

int GameBoard::GetWidth() const
{
	return mWidth;
}

int GameBoard::GetHeight() const
{
	return mHeight;
}

char GameBoard::GetWallIcon() const
{
	return mIconWall;
}

char GameBoard::GetScoreToWinLevel() const
{
	return mScoreToWinLevel;
}
