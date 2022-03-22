#pragma once
#include "Vector2.h"
#include <vector>
#include <windows.h>
#include <string>

class Tile
{
	public:
		string screenText;
		COORD position;
		// Used to know where on the screen each cell is positioned
		COORD screenPos;
		bool isShip;
		bool attacked;
		void SetCoord(int x, int y);
		void SetCoord(COORD pos);
		void SetScreenPos(int x, int y);
		void SetScreenPos(COORD pos);
};

