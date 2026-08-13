#include "GameMode.h"
#include "PlayerState.h"
#include "GameBoard.h"
#include "Snake.h"

GameMode* GameMode::sInstance = nullptr;

GameMode::GameMode()
{
}

GameMode* GameMode::GetInstace()
{
	if (sInstance == nullptr)
	{
		sInstance = new GameMode();
	}
	return sInstance;
}

void GameMode::InitializeTrackingProperties(
	const std::shared_ptr<Snake>& InSnakeShared, 
	const std::shared_ptr<GameBoard>& InGameBoardShared, 
	const std::shared_ptr<PlayerState>& InPlayerStateShared)
{
	mSnakeWeak = InSnakeShared;
	mGameboardWeak = InGameBoardShared;
	mPlayerStateWeak = InPlayerStateShared;
}

const GameMatchStates& GameMode::GetGameMatchState() const
{
	return mGameMatchState;
}

void GameMode::SetGameMatchState(GameMatchStates InGameMatchState)
{
	mGameMatchState = InGameMatchState;
}

bool GameMode::GetWinState()
{
	return mHasPlayerWon;
}

bool GameMode::GetLossState()
{
	return mHasPlayerLost;
}

void GameMode::ResetStates()
{
	mHasPlayerLost = false;
	mHasPlayerWon = false;
}

void GameMode::UpdateWinState()
{
	if (std::shared_ptr<PlayerState> playerStateShared = mPlayerStateWeak.lock())
	{
		if (std::shared_ptr<GameBoard> gameBoardShared = mGameboardWeak.lock())
		{
			if (playerStateShared->GetScore() >= gameBoardShared->GetScoreToWinLevel())
			{
				mHasPlayerWon = true;
			}
		}
	}
}

void GameMode::UpdateLooseState()
{
	if (std::shared_ptr<Snake> snakeShared = mSnakeWeak.lock())
	{
		if (std::shared_ptr<GameBoard> gameBoardShared = mGameboardWeak.lock())
		{
			if (snakeShared->GetLocation().mX == 0
				|| snakeShared->GetLocation().mX == gameBoardShared->GetWidth()
				|| snakeShared->GetLocation().mY == 0
				|| snakeShared->GetLocation().mY == gameBoardShared->GetHeight())
			{
				mHasPlayerLost = true;
			}
		}
	}
}
