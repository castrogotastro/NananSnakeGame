#include "GameBoard.h"

GameBoard::GameBoard(int InWidth, int InHeight)
	:mWidth(InWidth), mHeight(InHeight)
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
