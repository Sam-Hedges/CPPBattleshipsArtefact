#include "Map.h"

Map::Map(COORD mapSize) {
	InitMap(mapSize);
}

Map::Map() {
	COORD size{ 10, 10 };
	InitMap(size);
}

void Map::InitMap(COORD mapSize) {
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
	const COORD size = { static_cast<SHORT>(map.size()), static_cast<SHORT>(map[0].size()) };
	return size;
}