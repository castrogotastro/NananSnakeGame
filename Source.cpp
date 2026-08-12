#include "Utilities.h"
#include "AActor.h"
#include "GameBoard.h"
#include "InputManager.h"
#include "Snake.h"
#include <memory>
#include "Renderer.h"
#include "Collectible.h"
#include "RandomNumGenerator.h"

int main()
{
	int testPush = 1;
	bool isGameOver = false;
	InputManager inputManager;
	std::shared_ptr<GameBoard> gameBoard = std::make_shared<GameBoard>(30,20);

	std::shared_ptr<Snake> player = std::make_shared<Snake>(FVector2(5, 22), 'P', '*', *gameBoard);

	int numCollectiblesToStart = 4;

	std::vector <std::shared_ptr<Collectible>> collectiblesOnBoard;

	for (int i = 0; i < numCollectiblesToStart; i++)
	{
		FVector2 collectibleLocation;
		collectibleLocation.mX = GenerateRandomValueInWidth(gameBoard->GetWidth());
		collectibleLocation.mY = GenerateRandomValueInHeight(gameBoard->GetHeight());

		collectiblesOnBoard.emplace_back(std::make_shared<Collectible>(collectibleLocation, '@'));
	}

	Renderer renderer(player, gameBoard);
	
	LOG_LN("Start Game");

	bool isGameWon = false;
	FVector2 winCondition(5, gameBoard->GetHeight());

	do
	{
		if (!player || !gameBoard)
		{
			return 1;
		}
		inputManager.Update();
		inputManager.MoveCharacterSingleSpace(*player);

		renderer.RenderGame(collectiblesOnBoard);

#if 0
		system("cls");

		for (int y = 0; y <= gameBoard->GetHeight(); ++y)
		{
			for (int x = 0; x <= gameBoard->GetWidth(); ++x)
			{
				if (x == 0 || x == gameBoard->GetWidth() || y == 0 || y == gameBoard->GetHeight())
				{
					//Rendering Boarder
					if (x == winCondition.mX && y == winCondition.mY)
					{
						LOG(" ");
					}
					else
					{
						LOG(gameBoard->GetWallIcon());
					}

					if (x == gameBoard->GetWidth())
					{
						std::cout << std::endl;
					}

				}
				//Rendering player
				else if (x == player->GetLocation().mX && y == player->GetLocation().mY)
				{
					LOG(player->GetIcon());
				}

				//Render empty
				else
				{
					LOG(" ");
				}
				
				//Loose condition
				if ((player->GetLocation().mX == 0
					|| player->GetLocation().mX == gameBoard->GetWidth()
					|| player->GetLocation().mY == 0
					|| player->GetLocation().mY == gameBoard->GetHeight()) 
					&& player->GetLocation().mX != winCondition.mX
					&& player->GetLocation().mY != winCondition.mY)
				{
					isGameOver = true;
				}

				//win condition
				if (player->GetLocation().mX == winCondition.mX
					&& player->GetLocation().mY == winCondition.mY)
				{
					isGameWon = true;
				}

			}
		}
#endif

	} while (isGameOver == false && isGameWon == false);

	if (isGameOver == true)
	{
		LOG("Game Over");
		LOG("Game Over");
		LOG("Game Over");
	}
	if (isGameWon == true)
	{
		LOG("You won!!!");
		LOG("You won!!!");
		LOG("You won!!!");
	}
	
}