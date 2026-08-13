#pragma once
#include <map>
#include <memory>

//vector - index base 
	//index		value 
	// 
	// size 4
	// 0		valueAtIndex0  //level4
	// 1		valueAtInde1   //leve2
	// 2		valueAtIndex2
	// 3		valueAtIndex3
//map - key value pairs
	//key		value

class AActor;
class GameBoard;

class Level
{
//Singleton patter
	//1. Private construction - so construction only can occur from within the clas
	Level();

	//2. private static pointer to instance of this class. Declaration only within class definition. Definition in cpp.
	static Level* sInstance;

public:
	//3. public function that return the instance. Function is static, so it's call via the class, not via an instance.
	static Level* GetInstance();

	//4. Delete the copy constuctor and delete the copy assigment operator
	Level(const Level& InLevelToCopy) = delete;
	Level& operator=(const Level& InLevelToCopy) = delete;

private:
	int mDefaultLevelWidth = 40;
	int mDefaultLevelHeight = 15;
	int mDefaultLevelWinScore = 3;
	int mCurrentLevel = 1;

	std::map<int, std::shared_ptr<GameBoard>> mLevelGameboards;

public:
	void AddLevelGameboard(int InLevelKey, int InWidth, int InHeight, int InScoreToWin);

	std::shared_ptr<GameBoard> GetCurrentLevelGameBoard();

	bool SetCurrentGameboardLevel(int InCurrentLevel);
	int GetCurrentLevel();
	bool SetLevelToNext();
};

