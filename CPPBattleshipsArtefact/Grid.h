#pragma once
#include "Map.h"
#include <iostream>
using namespace std;

class Grid
{
	public:
		//char gridC[12] = { 218,196,194,191,195,180,197,192,193,217,179,' ' };

		static void DrawGrid(const vector<vector<Tile>> &map);
};

