#pragma once
#include <iostream>
#include <vector>
#include <cstdlib>
#include <windows.h>
#include "Output.h"
using namespace std;

class Output
{
	public:
		static COORD PrintCentered(const char* string, int colour = 15);
		static void OverridePrint(const char* string, COORD& pos, int selected, int previouslySelected);
		enum class ConsoleColour
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

