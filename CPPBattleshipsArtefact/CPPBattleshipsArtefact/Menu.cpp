#include "Menu.h"

int Menu::DisplayMenu(string &title, vector<string> options)
{
	// Gets the standard output device; the active console screen-buffer
	const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	// Used to reduce the amount of size() calls of options
	const int optionsSize = options.size();

	// Used the initialize the vector of coordinates
	COORD origin; origin.X = 0; origin.Y = 0;

	// Stores the postions of all the menu options
	vector<COORD> linePos(optionsSize, origin);

	// Used the navigate the menu and store which option is selected
	int menuIndex = 0; int lastMenuIndex = -1;
	
	#pragma region InitMenu

	// Prints the menu title
	Output::PrintCentered(title.c_str());
	Output::PrintCentered(" ");

	// Loops through and prints each option
	for (int i = 0; i < optionsSize; i++)
	{
		// Save the current option string as a const char*
		// Refer to PrintCentered as to why this is
		const char* currentOption = options[i].c_str();

		// Gets the current colour needed for option
		const int currentColour = i == menuIndex ? (int)Output::ConsoleColour::Green : (int)Output::ConsoleColour::White;

		// Prints the options
		linePos[i] = Output::PrintCentered(currentOption, currentColour);
	}

	#pragma endregion Prints the whole menu to the screen

	while (true)
	{
		// If the menu index goes out of bounds it's wrapped around to the opposite option
		menuIndex = menuIndex == optionsSize ? 0 : menuIndex < 0 ? optionsSize - 1 : menuIndex;

		// Prints over the current menu index in the selection colour
		Output::OverridePrint(options[menuIndex].c_str(), linePos[menuIndex], menuIndex, lastMenuIndex);

		// Pauses the system for an input
		// The >nul stops it printing a message
		system("pause>nul");

		// Sets the 
		lastMenuIndex = menuIndex;
		Output::OverridePrint(options[lastMenuIndex].c_str(), linePos[lastMenuIndex], menuIndex, lastMenuIndex);

		// If the arrows are pressed, the index of the current options is
		// Incremented or decremented according to the input
		// Enter returns the current menu index (which option was selected)
		if (Input::UpArrow()) {	menuIndex--; }
		else if (Input::DownArrow()) { menuIndex++;	}
		else if (Input::Enter()) 
		{ 
			system("CLS");
			return menuIndex; 
		}

	}
}
