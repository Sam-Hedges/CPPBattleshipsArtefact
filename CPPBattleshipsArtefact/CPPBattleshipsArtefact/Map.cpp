#include "Map.h"

Map::Map() {
	COORD size{ 10, 10 };
	Map(size);
}

Map::Map(COORD mapSize)
{
	vector<vector<Tile>> temp(mapSize.X, vector<Tile>(mapSize.Y, Tile()));

	for (int col = 0; col < temp.size(); col++)
	{
		for (int row = 0; row < temp[col].size(); row++)
		{
			temp[col][row].SetCoord(row, col);
		}
	}

	map = temp;
}

COORD Map::MapSize(vector<vector<Tile>> map) {

	const COORD size = { map.size(), map[0].size() };
	return size;
}