#include "MasterHUD.h"
#include "GameMode.h"

MasterHUD::MasterHUD(const std::shared_ptr<PlayerState>& InPlayerStateShared)
{
	mGameplay = std::make_shared<HUDGameplay>(InPlayerStateShared);
}

void MasterHUD::LoadMainMenu(GameMode* InGameMode)
{
	if (InGameMode)
	{
		char userInput = mMainMenu->GetUserInput();

		switch (userInput)
		{
			case 's':
			{
				InGameMode->SetGameMatchState(GameMatchStates::BeginMatch);
				break;
			}
			case 'e':
			{
				InGameMode->SetGameMatchState(GameMatchStates::MenuGameOver);
				break;
			}
			default:
				InGameMode->SetGameMatchState(GameMatchStates::MenuGameOver);
		}

	}
}

void MasterHUD::LoadNextLevelMenu(GameMode* InGameMode)
{
	if (InGameMode)
	{
		mNextLevelMenu->RenderHUD();
		InGameMode->SetGameMatchState(GameMatchStates::BeginMatch);
	}
}

void MasterHUD::LoadWinMenu(GameMode* InGameMode)
{
	if (InGameMode)
	{
		char userInput = mWinMenu->GetUserInput();

		switch (userInput)
		{
			case 'p':
			{
				InGameMode->SetGameMatchState(GameMatchStates::BeginMatch);
				break;
			}
			case 'e':
			{
				InGameMode->SetGameMatchState(GameMatchStates::MenuGameOver);
				break;
			}
			default:
				InGameMode->SetGameMatchState(GameMatchStates::MenuGameOver);
		}

	}
}

void MasterHUD::LoadExitMenu(GameMode* InGameMode)
{
	if (InGameMode)
	{
		mExitMenu->RenderHUD();
		InGameMode->SetGameMatchState(GameMatchStates::MatchEnd);
	}
}

void MasterHUD::LoadRestartMenu(GameMode* InGameMode)
{
	if (InGameMode)
	{
		char userInput = mRestartMenu->GetUserInput();

		switch (userInput)
		{
			case 'r':
			{
				InGameMode->SetGameMatchState(GameMatchStates::RestartMatch);
				break;
			}
			case 'm':
			{
				InGameMode->SetGameMatchState(GameMatchStates::MenuMain);
				break;
			}

			case 'e':
			{
				InGameMode->SetGameMatchState(GameMatchStates::MenuGameOver);
				break;
			}
			default:
				InGameMode->SetGameMatchState(GameMatchStates::MenuGameOver);
		}

	}
}

void MasterHUD::RenderGameplayHUD()
{
	mGameplay->RenderHUD();
}
