#pragma once
class GameBoard
{
public:
	GameBoard(int InWidth, int InHeight);

private:
	int mWidth;
	int mHeight;
	char mIconWall = '#';

public:
	int GetWidth() const;
	int GetHeight() const;
	char GetWallIcon() const;
};

