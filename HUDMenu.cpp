#include "HUDMenu.h"

HUDMenu::HUDMenu(std::string InMenuTitle)
	: mMenuTitle(InMenuTitle)
{
}

HUDMenu::HUDMenu(std::string InMenuTitle, std::vector<MessageInputData>& InMessagesInputs)
	: mMessagesInputs(InMessagesInputs)
{
}

void HUDMenu::RenderHUD()
{
	LOG_LN("===============================");
	LOG_LN(mMenuTitle);
	NEXTLINE;
	for (MessageInputData& messageInput : mMessagesInputs)
	{
		LOG_LN(messageInput.mMessage);
	}
	NEXTLINE;
	LOG_LN("===============================");
}

char HUDMenu::GetUserInput()
{
	system("cls");
	char userInput = '!';
	bool isInputValid = true;

	do
	{
		if (isInputValid == false)
		{
			system("cls");
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			LOG_LN("Invalid input. Try again");
		}
		RenderHUD();

		std::cin >> userInput;
		
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			isInputValid = false;
		}

		isInputValid = IsInputValid(userInput);
		
	} while (isInputValid == false);

	return userInput;

}

bool HUDMenu::IsInputValid(char InUserInput)
{
	bool isValid = false;

	for (MessageInputData& messageInput : mMessagesInputs)
	{
		if (messageInput.mValidInput == InUserInput)
		{
			isValid = true;
			return isValid;
		}
	}
	return isValid;
}

void HUDMenu::AddMessageInput(MessageInputData InMessageInputData)
{
	mMessagesInputs.emplace_back(InMessageInputData);
}
