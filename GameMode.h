#pragma once

#include <memory>

class Snake;
class GameBoard;

class GameMode
{
	//properties
	static GameMode* sInstance;
	std::weak_ptr<Snake> mSnakePlayerWeak;
	std::weak_ptr<GameBoard> mGameboardWeak;


private:
	//constructors & assigment operators
	GameMode();
	GameMode(const GameMode& InGameModeRightOperand) = delete;
	GameMode& operator=(const GameMode& InGameModeRightOperand) = delete;


public:
	static GameMode* GetInstace();


};

