#pragma once
#include "Vector2.h"
#include <vector>
#include <windows.h>

class Tile
{
	public:
		COORD position;
		bool isShip;
		bool attacked;

		void SetCoord(int x, int y);
};

