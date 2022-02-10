#pragma once
#include <iostream>
#include <cstdlib>
#include "Input.h"
using namespace std;

class Menu
{
	public:
		static void PrintCentered(const char* string);
		static int DisplayMenu(string &title, string options[]);
		enum ConsoleColour
		{
			Dark_Blue = 9,
			Green,
			Light_Blue,
			Red,
			Magenta,
			Yellow,
			White
		};
};

