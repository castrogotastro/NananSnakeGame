#pragma once
class GameBoard
{
public:
	GameBoard(int InWidth, int InHeight, int InScoreToWinLevel, int InCollectiblesToStartLevel);

private:
	int mWidth;
	int mHeight;
	char mIconWall = '#';
	int mScoreToWinLevel;
	int mCollectiblesToStartLevel = 3;

public:
	int GetWidth() const;
	int GetHeight() const;
	char GetWallIcon() const;
	int GetScoreToWinLevel() const;
	int GetCollectiblesToStartLevel() const;
};

