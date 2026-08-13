#pragma once
#include "HUD.h"
#include <memory>

class PlayerState;

class HUDGameplay : public HUD
{
public:
	HUDGameplay(const std::shared_ptr<PlayerState>& InPlayerStateShared);

private:
	std::weak_ptr<PlayerState> mPlayerStateWeak;

public:
	// Inherited via HUD
	void RenderHUD() override;


};

