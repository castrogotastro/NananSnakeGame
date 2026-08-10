#include "Utilities.h"
#include "AActor.h"
#include "GameBoard.h"
#include "InputManager.h"

int main()
{
	bool isGameOver = false;
	InputManager inputManager;
	GameBoard gameBoard(30,20);

	AActor player(FVector2(5, 5), 'P');
	LOG_LN("Start Game");

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
				
				if (player.GetLocation().mX == 0
					|| player.GetLocation().mX == gameBoard.mWidth
					|| player.GetLocation().mY == 0
					|| player.GetLocation().mY == gameBoard.mHeight)
				{
					isGameOver = true;
				}
			}
		}

	} while (isGameOver == false);

	LOG("Game Over");
	LOG("Game Over");
	LOG("Game Over");
}