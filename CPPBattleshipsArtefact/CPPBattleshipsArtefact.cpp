// CPPBattleshipsArtefact.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Map.h"
#include "Grid.h"
#include <conio.h>
#include <windows.h>
#include "Menu.h"

int main()
{
	Map playerMap(Vector2(10, 10));

	ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);

	string title = "Main  Menu";
	vector<string> options = { "Game", "Settings", "Quit" };

	const int index = Menu::DisplayMenu(title, options);

	switch (index)
	{
		case 0:
			Grid::DrawGrid(playerMap.map);
			system("pause>nul");
			break;
		case 1:
			break;
		case 2:
			break;
		default:
			break;
	}

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
