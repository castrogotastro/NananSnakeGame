#pragma once
class GameBoard
{
public:
	GameBoard(int InWidth, int InHeight, int InScoreToWinLevel);

private:
	int mWidth;
	int mHeight;
	char mIconWall = '#';
	int mScoreToWinLevel;

public:
	int GetWidth() const;
	int GetHeight() const;
	char GetWallIcon() const;
	int GetScoreToWinLevel() const;
};

