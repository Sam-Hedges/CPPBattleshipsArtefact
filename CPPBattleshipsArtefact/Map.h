#pragma once
#include "Tile.h"
#include "Ship.h"

class Map
{
	public:
		vector<vector<Tile>> map;
		vector<Ship> ships;

		Map(COORD mapSize);
		Map(); // Constructors
		void InitMap(COORD mapSize);
		static COORD MapSize(vector<vector<Tile>> map);
};

