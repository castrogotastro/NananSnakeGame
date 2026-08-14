#include "HUDGameplay.h"
#include "PlayerState.h"

HUDGameplay::HUDGameplay(const std::shared_ptr<PlayerState>& InPlayerStateShared)
	: mPlayerStateWeak(InPlayerStateShared)
{
}

void HUDGameplay::RenderHUD()
{
	if (std::shared_ptr<PlayerState> playerStateShared = mPlayerStateWeak.lock())
	{
		int score = playerStateShared->GetScore();
		LOG_LN("=========================================");
		LOG_LN("Score : " << score);
		LOG_LN("=========================================");
	}
}
