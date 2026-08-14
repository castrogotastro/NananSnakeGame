#include "Utilities.h"
#include "AActor.h"
#include "GameBoard.h"
#include "InputManager.h"
#include "Snake.h"
#include <memory>
#include "Renderer.h"
#include "Collectible.h"
#include "RandomNumGenerator.h"
#include "Level.h"
#include "GameMode.h"
#include "PlayerState.h"
#include "MasterHUD.h"

//Master Level
	//container of levels

	//video 3 - SpawningActor
	//container of Actors in level


//GameMode - Rules of the game
	//number of players allow.
	// single player. Death match 
	//Win state
		//winning the level 
		//winning the game
	//lose state

//PlayerState - what holds data for player (things like score)

//open game - Create core class (GameMode, masterlevel, playerState

//menu (pause and wait for input)
	//start the game
	//exit

//Start level - Gameboard, Score, Snake

	//HUD render Score

//Restart menu (pause and wait for input)
	//Press 'r' to Restart the game
	//Press 's' to Start from beginning the game or return to main menu
	//exit


std::vector<std::shared_ptr<Collectible>> SpawnInitialCollectibles(GameMode* InGame, Level* InLevel)
{
	std::vector <std::shared_ptr<Collectible>> collectiblesOnBoard;
	for (int i = 0; i < InLevel->GetCurrentLevelGameBoard()->GetCollectiblesToStartLevel(); i++)
	{
		FVector2 collectibleLocation;
		collectibleLocation.mX = GenerateRandomValueInWidth(InLevel->GetCurrentLevelGameBoard()->GetWidth());
		collectibleLocation.mY = GenerateRandomValueInHeight(InLevel->GetCurrentLevelGameBoard()->GetHeight());

		collectiblesOnBoard.emplace_back(std::make_shared<Collectible>(collectibleLocation, '@'));
	}

	return collectiblesOnBoard;
}


void StartGame(Level* InLevel, GameMode* InGamemode, std::shared_ptr<PlayerState> InPlayerState, std::shared_ptr<MasterHUD> InMasterHUD)
{
	if (InLevel == nullptr)
	{
		InLevel = Level::GetInstance();
	}
	if (InGamemode == nullptr)
	{
		return;
		/*InGamemode = GameMode::GetInstance();*/
	}

	InGamemode->SetGameMatchState(GameMatchStates::MatchStart);
	//Get current level gameboard
	std::shared_ptr<GameBoard> currentGameboard = InLevel->GetCurrentLevelGameBoard();

	//Create InputManager and player
	InputManager inputManager;
	std::shared_ptr<Snake> player = std::make_shared<Snake>(FVector2(5, 22), 'P', '*', *currentGameboard);


	//Pass pointers to gamemode
	InGamemode->InitializeTrackingProperties(player, currentGameboard, InPlayerState);


	std::vector <std::shared_ptr<Collectible>> collectiblesOnBoard = SpawnInitialCollectibles(InGamemode, InLevel);

	

	Renderer renderer(player, currentGameboard);

	LOG_LN("Start Game");

	bool isGameWon = false;
	FVector2 winCondition(5, currentGameboard->GetHeight());

	

	while (InGamemode->GetGameMatchState() == GameMatchStates::MatchStart)
	{
		while (InGamemode->GetLossState() == false && InGamemode->GetWinState() == false)
		{
			if (!player || !currentGameboard)
			{
				return;
			}
			//Take input and move change player position
			inputManager.Update();
			inputManager.MoveCharacterContinuous(*player);

			//Render
			renderer.RenderGame(collectiblesOnBoard);
			InMasterHUD->RenderGameplayHUD();

			//check if player is overlapping with collectible
			for (const std::shared_ptr<Collectible>& collectible : collectiblesOnBoard)
			{
				if (player->GetLocation() == collectible->GetLocation())
				{
					collectible->SetHasBeenCollected(true);
					InPlayerState->ChangeScore(1);
					player->AddToTail();
				}
			}

			
			//Remove collected/overlapped collectible from containter of collectibles (collectiblesOnBoard)
			for (std::vector<std::shared_ptr<Collectible>>::iterator iterator = collectiblesOnBoard.begin();
				iterator != collectiblesOnBoard.end(); )
			{
				if ((*iterator)->GetHasBeenCollected() == true)
				{
					(*iterator).reset();

					FVector2 collectibleLocation;
					collectibleLocation.mX = GenerateRandomValueInWidth(currentGameboard->GetWidth());
					collectibleLocation.mY = GenerateRandomValueInHeight(currentGameboard->GetHeight());

					(*iterator) = std::make_shared<Collectible>(collectibleLocation);
				}
				else
				{
					++iterator;
				}
			}

			//Add collectibles to board. Quantity based on difficulty
			if (InGamemode->GetDiffucty() == Difficultly::Easy)
			{

				for (int numCollectibles = collectiblesOnBoard.size(); numCollectibles < player->GetTailLength(); ++numCollectibles)
				{
					FVector2 collectibleLocation;
					collectibleLocation.mX = GenerateRandomValueInWidth(currentGameboard->GetWidth());
					collectibleLocation.mY = GenerateRandomValueInHeight(currentGameboard->GetHeight());

					collectiblesOnBoard.emplace_back(std::make_shared<Collectible>(collectibleLocation));
				}
			}

			if (InGamemode->GetDiffucty() == Difficultly::Hard)
			{

				for (int numCollectibles = collectiblesOnBoard.size(); numCollectibles < (player->GetTailLength() / 2); ++numCollectibles)
				{
					FVector2 collectibleLocation;
					collectibleLocation.mX = GenerateRandomValueInWidth(currentGameboard->GetWidth());
					collectibleLocation.mY = GenerateRandomValueInHeight(currentGameboard->GetHeight());

					collectiblesOnBoard.emplace_back(std::make_shared<Collectible>(collectibleLocation));
				}
			}
		}

		if (InGamemode->GetLossState() == true)
		{
			InGamemode->SetGameMatchState(GameMatchStates::MenuRestart);
		}
		if (InGamemode->GetWinState() == true)
		{
			if (InLevel->SetLevelToNext() == true)
			{
				InGamemode->SetGameMatchState(GameMatchStates::MenuNextLevel);
			}
			else
			{
				InGamemode->SetGameMatchState(GameMatchStates::MenuWin);
			}
		}
	}


	
		

	

}


int main()
{
	//Create Core Class
	GameMode* gameMode = GameMode::GetInstace();
	std::shared_ptr<PlayerState> playerState = std::make_shared<PlayerState>();
	Level* masterLevel = Level::GetInstance();

	//Create Gameboards (individual levels)
	masterLevel->AddLevelGameboard(1, 20, 25, 2, 3);
	masterLevel->AddLevelGameboard(2, 10, 20, 2, 5);
	masterLevel->AddLevelGameboard(3, 15, 15, 2, 7);


	//Create HUD
	std::shared_ptr<MasterHUD> masterHud = std::make_shared<MasterHUD>(playerState);

	//Set default starting values
	gameMode->SetGameMatchState(GameMatchStates::MenuMain);
	gameMode->SetDiffucty(Difficultly::Easy);
	bool shouldPlayFromStart = true;

	if (gameMode)
	{
		while (gameMode->GetGameMatchState() != GameMatchStates::MatchEnd)
		{
			switch (gameMode->GetGameMatchState())
			{
				case GameMatchStates::MenuMain:
				{
					masterHud->LoadMainMenu(gameMode);
					shouldPlayFromStart = true;
					break;
				}
				case GameMatchStates::BeginMatch:
				{
					if (shouldPlayFromStart == true)
					{
						masterLevel->SetCurrentGameboardLevel(1);
					}
					shouldPlayFromStart = false;
					gameMode->ResetStates();
					playerState->SetScore(0);
					StartGame(masterLevel, gameMode, playerState, masterHud);
					break;
				}
				case GameMatchStates::MenuNextLevel:
				{
					masterHud->LoadNextLevelMenu(gameMode);
					break;
				}
				case GameMatchStates::MenuRestart:
				{
					masterHud->LoadRestartMenu(gameMode);
					break;
				}
				case GameMatchStates::RestartMatch:
				{
					gameMode->ResetStates();
					playerState->SetScore(0);
					StartGame(masterLevel, gameMode, playerState, masterHud);
					break;
				}
				case GameMatchStates::MenuWin:
				{
					masterHud->LoadWinMenu(gameMode);
					shouldPlayFromStart = true;
					break;
				}
				case GameMatchStates::MenuGameOver:
				{
					masterHud->LoadExitMenu(gameMode);
					break;
				}

				default:
					break;
			}
		}
	}

}