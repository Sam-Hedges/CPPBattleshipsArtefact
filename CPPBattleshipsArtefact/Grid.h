#pragma once
#include <iostream>
#include <vector>
#include <cstdlib>
#include "Output.h"
#include "Tile.h"
#include "Map.h"
using namespace std;

class Grid
{
	private:
		static int GetScreenPosition(int screenWidth, int stringLength, Output::Screen origin);
		static void SetupGrid(vector<vector<Tile>>& map, Output::Screen gridOrigin);

	public:
		static void DrawGridCentered(Map &map);
		static void DrawGridLeft(Map &map);
		static void DrawGridRight(Map &map);
};

