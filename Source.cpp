#include "Utilities.h"
#include "AActor.h"
#include "GameBoard.h"
#include "InputManager.h"

int main()
{
	int testPush = 1;
	bool isGameOver = false;
	InputManager inputManager;
	GameBoard gameBoard(30,20);

	AActor player(FVector2(5, 5), 'P');
	LOG_LN("Start Game");

	bool isGameWon = false;
	FVector2 winCondition(gameBoard.mWidth / 2, gameBoard.mHeight);

	do
	{
		inputManager.Update();
		inputManager.MoveCharacterSingleSpace(player);
		system("cls");

		for (int y = 0; y <= gameBoard.mHeight; ++y)
		{
			for (int x = 0; x <= gameBoard.mWidth; ++x)
			{
				if (x == 0 || x == gameBoard.mWidth || y == 0 || y == gameBoard.mHeight)
				{
					if (x == winCondition.mX && y == winCondition.mY)
					{
						LOG(" ");
					}
					LOG(gameBoard.mIconWall);
					if (x == gameBoard.mWidth)
					{
						std::cout << std::endl;
					}

				}
				else if (x == player.GetLocation().mX && y == player.GetLocation().mY)
				{
					LOG(player.GetIcon());
				}
				else
				{
					LOG(" ");
				}
				
				//Loose condition
				if ((player.GetLocation().mX == 0
					|| player.GetLocation().mX == gameBoard.mWidth
					|| player.GetLocation().mY == 0
					|| player.GetLocation().mY == gameBoard.mHeight) 
					&& player.GetLocation().mX != winCondition.mX
					&& player.GetLocation().mY != winCondition.mY)
				{
					isGameOver = true;
				}

				//win condition
				if (player.GetLocation().mX == winCondition.mX
					&& player.GetLocation().mY == winCondition.mY)
				{
					isGameWon = true;
				}

			}
		}

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