#include "GameBoard.h"

GameBoard::GameBoard(int InWidth, int InHeight, int InScoreToWinLevel, int InCollectiblesToStartLevel)
	:mWidth(InWidth), mHeight(InHeight), mScoreToWinLevel(InScoreToWinLevel), mCollectiblesToStartLevel(InCollectiblesToStartLevel)
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

int GameBoard::GetScoreToWinLevel() const
{
	return mScoreToWinLevel;
}

int GameBoard::GetCollectiblesToStartLevel() const
{
	return mCollectiblesToStartLevel;
}
