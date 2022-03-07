#pragma once
#include "Vector2.h"
#include <vector>
#include <windows.h>

class Tile
{
	public:
		COORD position;
		COORD screenPos;
		bool isShip;
		bool attacked;
		void SetCoord(int x, int y);
		void SetCoord(COORD pos);
		void SetScreenPos(int x, int y);
		void SetScreenPos(COORD pos);
};

