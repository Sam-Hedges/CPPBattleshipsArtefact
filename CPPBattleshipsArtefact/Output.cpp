#include "Output.h"

COORD Output::Print(const char* string, Screen origin, int colour) {
	
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

	// Figure out how many spaces in needed in order for string to be centered on origin
	int screenPos;
	switch (origin) {
	case Output::Screen::Center:
		screenPos = (currentScreenSize.X - stringLength) / 2;
		break;
	case Output::Screen::Left:
		screenPos = (currentScreenSize.X - stringLength) / 4;
		break;
	case Output::Screen::Right:
		screenPos = ((currentScreenSize.X - stringLength) / 4) * 3;
		break;
	default:
		screenPos = 0;
	}

	// Initialise a new position screenPos amount of spaces in X axis
	COORD pos; pos.X = screenPos; pos.Y = CSBI.dwCursorPosition.Y;

	// Sets the cursor position to the coordinate passed in
	SetConsoleCursorPosition(hOut, pos);

	// Changes the active console colour
	SetConsoleTextAttribute(hOut, colour);

	// Prints the string to the console
	cout << string << endl;

	// Returns the position of the printed line
	COORD linePos = { screenPos, CSBI.dwCursorPosition.Y };
	return linePos;

}

COORD Output::PrintCentered(const char* string, int colour)
{
	return Print(string, Screen::Center, colour);
}

COORD Output::PrintLeft(const char* string, int colour)
{
	return Print(string, Screen::Left, colour);
}

COORD Output::PrintRight(const char* string, int colour)
{
	return Print(string, Screen::Right, colour);
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

void Output::HideCursor() {
	// Used to store data on the current console screen buffer
	CONSOLE_SCREEN_BUFFER_INFO CSBI;

	// Gets the standard output device; the active console screen-buffer
	const HANDLE h_out = GetStdHandle(STD_OUTPUT_HANDLE);

	// Stores the data of hOut in csbi via a reference 
	GetConsoleScreenBufferInfo(h_out, &CSBI);

	// Saves the current screen size of the active console screen-buffer
	const COORD currentScreenSize = CSBI.dwSize;
	
	// Sets the cursor position to the corner
	COORD pos = CSBI.dwMaximumWindowSize; pos.X -= 1; pos.Y -= 1;
	SetConsoleCursorPosition(h_out, pos);
}