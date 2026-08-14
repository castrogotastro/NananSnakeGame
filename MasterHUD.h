#pragma once
#include <memory>
#include "HUDMenu.h"
#include "HUDMessageExit.h"
#include "HUDGameplay.h"
#include "HUDMessageNextLevel.h"

class HUDGameplay;
class PlayerState;

class MasterHUD
{
public:
	explicit MasterHUD(const std::shared_ptr<PlayerState>& InPlayerStateShared);
public:
	std::shared_ptr<HUDMenu> mMainMenu = std::make_shared<HUDMenu>(
		"SNAKE - Main Menu", 
		std::vector<MessageInputData>
	{
		MessageInputData("Press s to start", 's'),
		MessageInputData("Press e to exit", 'e')
	});

	std::shared_ptr<HUDMenu> mRestartMenu = std::make_shared<HUDMenu>(
		"SNAKE - Restart Menu",
		std::vector<MessageInputData>
	{
		MessageInputData("Press r to restart level", 'r'),
		MessageInputData("Press m to return to main menu", 'm'),
		MessageInputData("Press e to exit", 'e')
	});

	std::shared_ptr<HUDGameplay> mGameplay;

	std::shared_ptr<HUDMessageExit> mExitMenu = std::make_shared<HUDMessageExit>(
		"SNAKE - Exit Game Menu",
		std::vector<std::string>
	{
		"Thanks for playing",
		"Please play again"
	});



	
	
	

};

