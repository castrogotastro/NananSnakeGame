#pragma once
#include "HUD.h"
class HUDMessageNextLevel : public HUD
{
	friend class MasterHUD;
public:
	explicit HUDMessageNextLevel(std::string InMenuTitle);

protected:
	std::string mMenuTitle;

protected:
	// Inherited via HUD
	void RenderHUD() override;
};

