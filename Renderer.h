#pragma once
#include <memory>

class GameBoard;
class Snake;

class Renderer
{
public:
	Renderer(const std::shared_ptr<Snake>& InPlayer, const std::shared_ptr<GameBoard>& InGameBoard);

private:
	std::weak_ptr<Snake> mPlayerWeak;
	std::weak_ptr<GameBoard> mGameboardWeak;

public:
	void RenderGame();
	bool DrawBoarderTopBottom(int InX, int InY, const std::shared_ptr<GameBoard>& InGameBoardShared);
	bool DrawBoarderLeftRight(int InX, int InY, const std::shared_ptr<GameBoard>& InGameBoardShared);
	bool DrawPlayer(int InX, int InY, const std::shared_ptr<Snake>& InPlayerShared);
};

