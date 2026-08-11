#pragma once

#include "InputState.h"

class AActor;
class FVector2;

class InputManager
{
	
public:

	void Update();
	bool IsButtonPressed(char InWASD);
	bool changeButtonPressed();
	const InputState& GetInputState();
	void MoveCharacterContinuous(AActor& InActorToMove);
	void MoveCharacterSingleSpace(AActor& InActorToMove);
	void MoveCharacterAdditional(AActor& InActorToMove, FVector2& InOldHeadLocation);

private:
	InputState mInputState;
	int displayRefreshSpeed = 200;
	char mLastKeyPressed = ' ';
	static bool mIsKeyDown;
};
