#pragma once
#include "HUD.h"
class HUDMessageExit : public HUD
{
	friend class MasterHUD;
public:
	explicit HUDMessageExit(std::string InMenuTitle);
	HUDMessageExit(std::string InMenuTitle, std::vector<std::string> InMessages);

protected:
	std::vector<std::string> mMessages;
	std::string mMenuTitle;
protected:
	// Inherited via HUD
	 void RenderHUD() override;

public:
	void AddMessage(std::string InMessage);
};

