#pragma once

#include "InputState.h"

class AActor;

class InputManager
{
	
public:

	void Update();
	bool IsButtonPressed(char InWASD);
	bool changeButtonPressed();
	const InputState& GetInputState();
	void MoveCharacterContinuous(AActor& InActorToMove);
	void MoveCharacterSingleSpace(AActor& InActorToMove);

private:
	InputState mInputState;
	int displayRefreshSpeed = 200;
	char mLastKeyPressed = ' ';
	static bool mIsKeyDown;
};
