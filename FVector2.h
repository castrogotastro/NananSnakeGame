#pragma once

struct FVector2
{
	int mX = 0;
	int mY = 0;

	FVector2();
	FVector2(int InX, int InY);
	FVector2(const FVector2& InFVector2);

	bool operator==(const FVector2& InRightOperand) const
	{
		bool isSameX = mX == InRightOperand.mX;
		bool isSameY = mY == InRightOperand.mY;
		if (isSameX == true && isSameY == true)
		{
			return true;
		}
		return false;
	}
	
};

//bool operator==(const FVector2& InLeftOperand, const FVector2& InRightOperand)
//{
//	bool isSameX = InLeftOperand.mX == InRightOperand.mX;
//	bool isSameY = InLeftOperand.mY == InRightOperand.mY;
//	if (isSameX == true && isSameY == true)
//	{
//		return true;
//	}
//	return false;
//}