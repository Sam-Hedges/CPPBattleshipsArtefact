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
	public:
		static void Setup(Map &map);
		static void DrawGrid(vector<vector<Tile>> &map);
};

