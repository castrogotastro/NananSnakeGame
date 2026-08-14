#include "HUDMessageExit.h"
#include <chrono>
#include <thread>

HUDMessageExit::HUDMessageExit(std::string InMenuTitle)
	: mMenuTitle(InMenuTitle)
{
}

HUDMessageExit::HUDMessageExit(std::string InMenuTitle, std::vector<std::string> InMessages)
	: mMenuTitle(InMenuTitle), mMessages(InMessages)
{
}

void HUDMessageExit::RenderHUD()
{
	HUD::RenderHUD();
	//Current level # complete
	//Next level #

	//YOU Won
	//thanks for playing
	LOG_LN("===============================");
	LOG_LN(mMenuTitle);
	NEXTLINE;
	for (std::string& message : mMessages)
	{
		LOG_LN(message);
	}
	NEXTLINE;
	LOG_LN("===============================");
	std::this_thread::sleep_for(std::chrono::milliseconds(2000));
}

void HUDMessageExit::AddMessage(std::string InMessage)
{
	mMessages.emplace_back(InMessage);
}
