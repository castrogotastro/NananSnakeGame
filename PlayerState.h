#pragma once
class PlayerState
{
	int mScore = 0;
	int mMinimumScore = 0;
public:
	int GetScore();
	void SetScore(int InScore);
	void ResetScoreToMin();
	void ChangeScore(int InScoreChangeAmount);
};

