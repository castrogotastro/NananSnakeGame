#pragma once

#include <memory>
#include <string>

class Snake;
class GameBoard;
class PlayerState;

//Main Menu
	//Start game
	//Exit Game



//Game Start (level 1, 2, 3)

	//Win level
	//Win the game
	//Loose the level

//Restart menu

enum class GameMatchStates
{
	MenuMain,
	BeginMatch,
	RestartMatch,
	MatchStart,
	MatchEnd,
	MenuRestart,
	MenuWin,
	MenuNextLevel,
	MenuGameOver,
};

class GameMode
{
	//properties - Singleton
	static GameMode* sInstance;

	//Properties for tracking win and loose state
	std::weak_ptr<Snake> mSnakeWeak;
	std::weak_ptr<GameBoard> mGameboardWeak;
	std::weak_ptr<PlayerState> mPlayerStateWeak;
	bool mHasPlayerWon = false;
	bool mHasPlayerLost = false;

	//Properties for tracking game match state (where player is in game)
	GameMatchStates mGameMatchState = GameMatchStates::MenuMain;

private:
	//constructors & assigment operators
	GameMode();
	GameMode(const GameMode& InGameModeRightOperand) = delete;
	GameMode& operator=(const GameMode& InGameModeRightOperand) = delete;


public:
	static GameMode* GetInstace();

	void InitializeTrackingProperties(
		const std::shared_ptr<Snake>& InSnakeShared,
		const std::shared_ptr<GameBoard>& InGameBoardShared,
		const std::shared_ptr<PlayerState>& InPlayerStateShared);

	//Getters and Setters
	const GameMatchStates& GetGameMatchState() const;
	void SetGameMatchState(GameMatchStates InGameMatchState);

	bool GetWinState();
	bool GetLossState();
	void ResetStates();

	//Update Win and Loose states 
		// WIN - when score equals the value needed to win a level
		//Loose - when the player location equals the boarder
				//TODO also when the player location equals the tail
				//also if player head location equals a bomb or a bullet.
	void UpdateWinState();
	void UpdateLooseState();
};

