#pragma once
#include "Tile.h"
#include "Ship.h"

class Map
{
	public:
		vector<vector<Tile>> map;
		vector<Ship> ships;

		Map(Vector2 mapSize);
		static Vector2 MapSize(vector<vector<Tile>> map);
};

