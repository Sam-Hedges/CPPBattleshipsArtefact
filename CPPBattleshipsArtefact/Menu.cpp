#include "Menu.h"

/// <summary>
/// Prints a string centered to the current console size
/// </summary>
/// <param name="string">Is a const char* pointer so a string
/// can be entered directly with "" as a parameter. Use .c_str() to
/// convert a string variable to the correct type.</param>
void Menu::PrintCentered(const char* string)
{
	// Used to store data on the current console screen buffer
	CONSOLE_SCREEN_BUFFER_INFO CSBI;

	// Gets the standard output device; the active console screen-buffer
	const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	// Stores the data of hOut in csbi via a reference
	GetConsoleScreenBufferInfo(hOut, &CSBI);

	// Saves the current screen size of the active console screen-buffer
	const COORD currentScreenSize = CSBI.dwSize;

	// Gets the length of the string
	const int stringLength = strlen(string);

	// Figure out how many spaces in needed in order for string to be centered
	const int screenPos = (currentScreenSize.X - stringLength) / 2;

	// Adds the necessary amount of spaces in order to center the string
	for (int i = 0; i < screenPos; i++) { cout << " "; }

	// Prints the string to the console
	cout << string << endl;
}

int Menu::DisplayMenu(string &title, string options[])
{
	const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	int menuIndex = 0;

	while (true)
	{
		// Clears the console window
		system("CLS");

		if (menuIndex == -1)
		{
			menuIndex = 2;
		}
		if (menuIndex == 3)
		{
			menuIndex = 0;
		}

		const char* t = title.c_str();
		//PrintCentered(t);
		//PrintCentered(" ");

		for (int i = 0; i < options->size(); i++)
		{
			// Save the current option string as a const char*
			// Refer to PrintCentered as to why this is
			const char* currentOption = options[i].c_str();

			SetConsoleTextAttribute(hOut, White);

			if (i == menuIndex)
			{
				SetConsoleTextAttribute(hOut, Green);
				PrintCentered(currentOption);
				SetConsoleTextAttribute(hOut, White);
				continue;
			}

			PrintCentered(currentOption);
		}

		/*
		switch (menuIndex)
		{
			case 0:
				SetConsoleTextAttribute(hOut, Green);
				PrintCentered("asdfasdf");
				SetConsoleTextAttribute(hOut, White);
				PrintCentered("adfasd");
				PrintCentered("adgfdsfg");
				break;
			case 1:
				PrintCentered("asdfasdf");
				SetConsoleTextAttribute(hOut, Green);
				PrintCentered("adfasd");
				SetConsoleTextAttribute(hOut, White);
				PrintCentered("adgfdsfg");
				break;
			case 2:
				PrintCentered("asdfasdf");
				PrintCentered("adfasd");
				SetConsoleTextAttribute(hOut, Green);
				PrintCentered("adgfdsfg");
				break;
			default:
				menuIndex = 0;
				break;
		}
		SetConsoleTextAttribute(hOut, White);
		*/

		// Pauses the system for an input
		// The >nul forces it to print no message
		system("pause>nul");

		// If the arrows are pressed, the index of the current options is
		// Incremented or decremented according to the input
		if (Input::UpArrow())
		{
			menuIndex--;
		}
		else if (Input::DownArrow())
		{
			menuIndex++;
		}
		else if (Input::Enter())
		{
			return menuIndex;
		}
	}
}
