#pragma once
#include "HUD.h"
class HUDMessageExit : public HUD
{
public:
	explicit HUDMessageExit(std::string InMenuTitle);
	HUDMessageExit(std::string InMenuTitle, std::vector<std::string> InMessages);

protected:
	std::vector<std::string> mMessages;
	std::string mMenuTitle;
public:
	// Inherited via HUD
	 void RenderHUD() override;

	void AddMessage(std::string InMessage);
};

