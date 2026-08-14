#include "HUDMessageNextLevel.h"
#include "Level.h"
#include <chrono>
#include <thread>

HUDMessageNextLevel::HUDMessageNextLevel(std::string InMenuTitle)
	: mMenuTitle(InMenuTitle)
{
}

void HUDMessageNextLevel::RenderHUD()
{
	HUD::RenderHUD();
	Level* level = Level::GetInstance();

	if (level)
	{
		int currentLevel = level->GetCurrentLevel();
		int nextLevel = currentLevel + 1;

		std::string levelCompleteMessage = "Level : " + std::to_string(currentLevel)  + " complete";
		std::string nextLevelMessage = "Level : " + std::to_string(nextLevel)  + " starting";
		LOG_LN("===============================");
		LOG_LN(mMenuTitle);
		NEXTLINE;
		LOG_LN(levelCompleteMessage);
		NEXTLINE;
		LOG_LN(nextLevelMessage);
		LOG_LN("===============================");
		std::this_thread::sleep_for(std::chrono::milliseconds(2000));
	}
}
