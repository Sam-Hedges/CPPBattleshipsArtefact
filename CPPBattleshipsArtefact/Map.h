#pragma once
#include "Tile.h"
#include "Ship.h"

class Map
{
	public:
		vector<vector<Tile>> map;
		vector<Ship> ships;

		Map();
		Map(COORD mapSize); // Constructors
		static COORD MapSize(vector<vector<Tile>> map);
};

