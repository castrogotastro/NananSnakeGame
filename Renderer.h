#pragma once
#include <memory>
#include <vector>

class GameBoard;
class Snake;
class Collectible;

class Renderer
{
public:
	Renderer(
		const std::shared_ptr<Snake>& InPlayer, 
		const std::shared_ptr<GameBoard>& InGameBoard);

private:
	std::weak_ptr<Snake> mPlayerWeak;
	std::weak_ptr<GameBoard> mGameboardWeak;


public:
	void RenderGame(std::vector<std::shared_ptr<Collectible>>& InCollectibles);
	bool DrawBoarderTopBottom(int InX, int InY, const std::shared_ptr<GameBoard>& InGameBoardShared);
	bool DrawBoarderLeftRight(int InX, int InY, const std::shared_ptr<GameBoard>& InGameBoardShared);
	bool DrawPlayer(int InX, int InY, const std::shared_ptr<Snake>& InPlayerShared);
	bool DrawCollectible(int InX, int InY, std::vector<std::shared_ptr<Collectible>>& InCollectibles);

};

