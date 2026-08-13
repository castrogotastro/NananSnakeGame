#include "PlayerState.h"
#include "GameMode.h"

int PlayerState::GetScore()
{
    return mScore;
}

void PlayerState::SetScore(int InScore)
{
    if (InScore >= mMinimumScore)
    {
        mScore = InScore;
    }
}

void PlayerState::ResetScoreToMin()
{
    mScore = mMinimumScore;
}

void PlayerState::ChangeScore(int InScoreChangeAmount)
{
    GameMode* gamemode = GameMode::GetInstace();

    if (gamemode == nullptr)
    {
        return;
    }

    mScore += InScoreChangeAmount;

    if (mScore < mMinimumScore)
    {
        mScore = mMinimumScore;
    }

    gamemode->UpdateWinState();
}
