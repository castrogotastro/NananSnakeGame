#pragma once
#include "HUD.h"
#include <vector>

struct MessageInputData
{
	std::string mMessage;
	char mValidInput;

	MessageInputData(std::string InMessage, char InValidInput)
		: mMessage(InMessage), mValidInput(InValidInput)
	{

	}
};

//1. Render a container of string to screen
//2. test if user input is correct. 

class HUDMenu : public HUD
{
public:
	HUDMenu(std::string InMenuTitle);


	//Properties
private:
	std::vector<MessageInputData> mMessagesInputs;
	std::string mMenuTitle;

public:
	char GetUserInput();

	bool IsInputValid(char InUserInput);

	void AddMessageInput(MessageInputData InMessageInputData);

private:
	// Inherited via HUD
	void RenderHUD() override;
};

