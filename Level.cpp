#include "Level.h"
#include "GameBoard.h"


Level* Level::sInstance = nullptr;

Level::Level()
{
}

Level* Level::GetInstance()
{
	if (sInstance == nullptr)
	{
		sInstance = new Level();
	}
	return sInstance;
}

void Level::AddLevelGameboard(int InLevelKey, int InWidth, int InHeight, int InScoreToWin)
{
	if (mLevelGameboards.contains(InLevelKey) == false)
	{
		//						key				value
		mLevelGameboards.emplace(InLevelKey, std::make_shared<GameBoard>(InWidth, InHeight, InScoreToWin));
	}
	
}

std::shared_ptr<GameBoard> Level::GetCurrentLevelGameBoard()
{
	if (mLevelGameboards.contains(mCurrentLevel) == true)
	{
		return mLevelGameboards[mCurrentLevel];
	}

	mLevelGameboards.emplace(mCurrentLevel, std::make_shared<GameBoard>(mDefaultLevelWidth, mDefaultLevelHeight, mDefaultLevelWinScore));

	return mLevelGameboards.at(mCurrentLevel);

	
}

bool Level::SetCurrentGameboardLevel(int InCurrentLevel)
{
	if (mLevelGameboards.contains(InCurrentLevel))
	{
		mCurrentLevel = InCurrentLevel;
		return true;
	}
	return false;
}

int Level::GetCurrentLevel()
{
	return mCurrentLevel;
}

bool Level::SetLevelToNext()
{
	int nextLevel = mCurrentLevel + 1;
	if (mLevelGameboards.contains(nextLevel))
	{
		mCurrentLevel = nextLevel;
		return true;
	}
	return false;
}
