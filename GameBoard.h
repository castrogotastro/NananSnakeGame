#pragma once
class GameBoard
{
public:
	GameBoard(int InWidth, int InHeight);

	int mWidth;
	int mHeight;
	char mIconWall = '#';
};

