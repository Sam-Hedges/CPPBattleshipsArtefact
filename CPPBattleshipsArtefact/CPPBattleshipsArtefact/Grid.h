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
		static enum class Screen { Left, Right, Center };
		static int GetScreenPosition(int screenWidth, int stringLength, Screen origin);
		static void SetupGrid(vector<vector<Tile>>& map, Screen gridOrigin);

	public:
		static void DrawGridCentered(Map &map);
		static void DrawGridLeft(Map &map);
		static void DrawGridRight(Map &map);
};

