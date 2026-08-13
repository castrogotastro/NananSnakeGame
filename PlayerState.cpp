#include "PlayerState.h"

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
    mScore += InScoreChangeAmount;

    if (mScore < mMinimumScore)
    {
        mScore = mMinimumScore;
    }
}
