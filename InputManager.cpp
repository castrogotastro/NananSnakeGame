#include "InputManager.h"
#include <conio.h>
#include "Utilities.h"
#include <chrono>
#include <thread>
#include "AActor.h"
#include "Snake.h"


bool InputManager::mIsKeyDown = false;

void InputManager::Update()
{
    bool isButtonChanged = changeButtonPressed();

    if (isButtonChanged == true)
    {
        mInputState.mUp = IsButtonPressed('w');
        mInputState.mDown = IsButtonPressed('s');
        mInputState.mLeft = IsButtonPressed('a');
        mInputState.mRight = IsButtonPressed('d');
    }

    std::this_thread::sleep_for(std::chrono::milliseconds(displayRefreshSpeed));
}

bool InputManager::IsButtonPressed(char InWASD)
{
    if (mLastKeyPressed == InWASD)
    {
        return true;
    }
    return false;
}

bool InputManager::changeButtonPressed()
{
    if (_kbhit())
    {
        switch (_getch())
        {
        case 'w':
            mLastKeyPressed = 'w';
            mIsKeyDown = true;
            return true;
        case 's':
            mLastKeyPressed = 's';
            mIsKeyDown = true;
            return true;
        case 'a':
            mLastKeyPressed = 'a';
            mIsKeyDown = true;
            return true;
        case 'd':
            mLastKeyPressed = 'd';
            mIsKeyDown = true;
            return true;
        default:
            mIsKeyDown = false;
            return false;
        }
    }
    mIsKeyDown = false;
    return false;
}

const InputState& InputManager::GetInputState()
{
    return mInputState;
}

void InputManager::MoveCharacterContinuous(AActor& InActorToMove)
{
    FVector2 headPostion = InActorToMove.GetLocation();
    if (mInputState.isUp())
    {
        InActorToMove.Move(0, -1);
    }
    else if (mInputState.isDown())
    {
        InActorToMove.Move(0, 1);
    }
    else if (mInputState.isLeft())
    {
        InActorToMove.Move(-1, 0);
    }
    else  if (mInputState.isRight())
    {
        InActorToMove.Move(1, 0);
    }

    if (headPostion != InActorToMove.GetLocation())
    {
        MoveCharacterAdditional(InActorToMove, headPostion);
    }
}

void InputManager::MoveCharacterSingleSpace(AActor& InActorToMove)
{
    FVector2 headPostion = InActorToMove.GetLocation();
    if (mInputState.isUp() && mIsKeyDown == true)
    {
        InActorToMove.Move(0, -1);
    }
    else if (mInputState.isDown() && mIsKeyDown == true)
    {
        InActorToMove.Move(0, 1);
    }
    else if (mInputState.isLeft() && mIsKeyDown == true)
    {
        InActorToMove.Move(-1, 0);
    }
    else  if (mInputState.isRight() && mIsKeyDown == true)
    {
        InActorToMove.Move(1, 0);
    }
    
    if (headPostion != InActorToMove.GetLocation())
    {
        MoveCharacterAdditional(InActorToMove, headPostion);
    }
}

void InputManager::MoveCharacterAdditional(AActor& InActorToMove, FVector2& InOldHeadLocation)
{
    if (Snake* snake = dynamic_cast<Snake*>(&InActorToMove))
    {
        snake->MoveTail(InOldHeadLocation);
    }
}
