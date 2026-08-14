#pragma once
#include "HUD.h"
#include <memory>

class PlayerState;

class HUDGameplay : public HUD
{
	friend class MasterHUD;
public:
	explicit HUDGameplay(const std::shared_ptr<PlayerState>& InPlayerStateShared);

private:
	std::weak_ptr<PlayerState> mPlayerStateWeak;

protected:
	// Inherited via HUD
	void RenderHUD() override;


};

