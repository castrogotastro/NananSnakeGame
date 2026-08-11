#pragma once
#include "FVector2.h"

class AActor
{
public:
	AActor(FVector2 InLocation, char InIcon);
	AActor(const AActor& InAActor);
	virtual ~AActor();

private:
	FVector2 mLocation;
	char mIcon;

public:
	FVector2 GetLocation();
	void SetLocation(FVector2 InLocation);
	void SetLocationX(int InX);
	void SetLocationY(int InY);

	char GetIcon();

	void Move(int InChangeX, int InChangeY);
	
};

