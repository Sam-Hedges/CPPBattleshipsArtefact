#include "Menu.h"

void Menu::PrintCentered(const char* s)
{
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD NewSBSize;
	NewSBSize = GetLargestConsoleWindowSize(hOut);
	int l = strlen(s);
	int pos = (int)((NewSBSize.X - l) / 2);
	for (int i = 0; i < pos; i++)
		cout << " ";

	cout << s << endl;
}


void Menu::MainMenu()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	bool running = true;
	int menuIndex = 0;

	while (running)
	{
		system("CLS");
		switch (menuIndex)
		{
			case 0:
				SetConsoleTextAttribute(hConsole, 2);
				PrintCentered("asdfasdf");
				SetConsoleTextAttribute(hConsole, 15);
				PrintCentered("adfasd");
				PrintCentered("adgfdsfg");
				break;
			case 1:
				PrintCentered("asdfasdf");
				SetConsoleTextAttribute(hConsole, 2);
				PrintCentered("adfasd");
				SetConsoleTextAttribute(hConsole, 15);
				PrintCentered("adgfdsfg");
				break;
			case 2:
				PrintCentered("asdfasdf");
				PrintCentered("adfasd");
				SetConsoleTextAttribute(hConsole, 2);
				PrintCentered("adgfdsfg");
				break;
		}
		SetConsoleTextAttribute(hConsole, 15);

		system("pause>nul"); // the >nul bit causes it the print no message

		if (Input::UpArrow())
		{
			menuIndex--;
			if (menuIndex == -1)
			{
				menuIndex = 2;
			}
		}
		else if (Input::DownArrow())
		{
			menuIndex++;
			if (menuIndex == 3)
			{
				menuIndex = 0;
			}
		}
	}
}
