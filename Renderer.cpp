#include "Renderer.h"
#include "GameBoard.h"
#include "Utilities.h"
#include "Snake.h"

Renderer::Renderer(const std::shared_ptr<Snake>& InPlayer, const std::shared_ptr<GameBoard>& InGameBoard)
	: mPlayerWeak(InPlayer), mGameboardWeak(InGameBoard)
{
}

void Renderer::RenderGame()
{
	system("cls");

	bool hasAActorRender = false;

	if (std::shared_ptr<GameBoard> gameboardShared = mGameboardWeak.lock())
	{
		for (int y = 0; y <= gameboardShared->GetHeight(); ++y)
		{
			for (int x = 0; x <= gameboardShared->GetWidth(); ++x)
			{
				hasAActorRender = DrawBoarderTopBottom(x, y, gameboardShared);
				if (hasAActorRender == true)
				{
					continue;
				}
				hasAActorRender = DrawBoarderLeftRight(x, y, gameboardShared);
				if (hasAActorRender == true)
				{
					continue;
				}

				if (std::shared_ptr<Snake> playerShared = mPlayerWeak.lock())
				{
					hasAActorRender = DrawPlayer(x, y, playerShared);
					if (hasAActorRender == true)
					{
						continue;
					}
				}

				if (hasAActorRender == false)
				{
					LOG(" ");
				}
			}
		}
	}
	
}

bool Renderer::DrawBoarderTopBottom(int InX, int InY, const std::shared_ptr<GameBoard>& InGameBoardShared)
{
	//Top boarder		-> y =0
	//bottom boarder	-> y = height

	//width = 5

//######


	if (InY == 0 || InY == InGameBoardShared->GetHeight())
	{
		LOG(InGameBoardShared->GetWallIcon());

		if (InX == InGameBoardShared->GetWidth())
		{
			NEXTLINE;
		}
		return true;
	}
	return false;
}

bool Renderer::DrawBoarderLeftRight(int InX, int InY, const std::shared_ptr<GameBoard>& InGameBoardShared)
{
	//left boarder		-> x = 0
	//right boarder		-> x = width

	if (InX == 0 || InX == InGameBoardShared->GetWidth())
	{
		LOG(InGameBoardShared->GetWallIcon());

		if (InX == InGameBoardShared->GetWidth())
		{
			NEXTLINE;
		}
		return true;
	}
	return false;

}

bool Renderer::DrawPlayer(int InX, int InY, const std::shared_ptr<Snake>& InPlayerShared)
{

	if (InX == InPlayerShared->GetLocation().mX && InY == InPlayerShared->GetLocation().mY)
	{
		LOG(InPlayerShared->GetIcon());
		return true;
	}
	return false;
}
