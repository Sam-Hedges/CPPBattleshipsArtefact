#pragma once
#include <iostream>
#include <vector>
#include <cstdlib>
#include <windows.h>
#include "Input.h"
#include "Output.h"
using namespace std;

class Output
{
	public:
		static enum class Screen { Left, Right, Center };
		static COORD PrintCentered(const char* string, int colour = 15);
		static COORD PrintLeft(const char* string, int colour = 15);
		static COORD PrintRight(const char* string, int colour = 15);
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
		static void HideCursor();

	private:
		static COORD Print(const char* string, Screen origin, int colour);
};

