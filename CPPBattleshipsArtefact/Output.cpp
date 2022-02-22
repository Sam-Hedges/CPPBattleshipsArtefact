#include "Output.h"

COORD Output::PrintCentered(const char* string, int colour)
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

	// Initialise a new position screenPos amount of spaces in X axis
	COORD pos; pos.X = screenPos; pos.Y = CSBI.dwCursorPosition.Y;

	// Sets the cursor position to the coordinate passed in
	SetConsoleCursorPosition(hOut, pos);

	// Changes the active console colour
	SetConsoleTextAttribute(hOut, colour);

	// Prints the string to the console
	cout << string << endl;

	// Returns the position of the printed line
	COORD linePos; linePos.X = screenPos; linePos.Y = CSBI.dwCursorPosition.Y;
	return linePos;
}

void Output::OverridePrint(const char* string, COORD& pos, int selected, int previouslySelected)
{
	// Gets the standard output device; the active console screen-buffer
	const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	// Sets the cursor position to the coordinate passed in
	SetConsoleCursorPosition(hOut, pos);

	// Changes the colour to indicate which option is selected
	if (selected == previouslySelected)
	{
		// Sets the active print colour to White
		SetConsoleTextAttribute(hOut, (int)ConsoleColour::White);
	}
	else if (selected != previouslySelected)
	{
		// Sets the active print colour to Green
		SetConsoleTextAttribute(hOut, (int)ConsoleColour::Green);
	}

	// Prints over the currently displayed option in the new colour
	cout << string;
}