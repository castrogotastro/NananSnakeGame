#pragma once
#include "HUD.h"
class HUDMessageNextLevel : public HUD
{
public:
	explicit HUDMessageNextLevel(std::string InMenuTitle);

protected:
	std::string mMenuTitle;

public:
	// Inherited via HUD
	void RenderHUD() override;
};

