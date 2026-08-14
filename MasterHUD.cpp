#include "MasterHUD.h"

MasterHUD::MasterHUD(const std::shared_ptr<PlayerState>& InPlayerStateShared)
{
	mGameplay = std::make_shared<HUDGameplay>(InPlayerStateShared);
}
