#include "Map.h"

Map::Map(Vector2 mapSize)
{
	vector<vector<Tile>> temp(mapSize.x, vector<Tile>(mapSize.y, Tile()));

	for (int col = 0; col < temp.size(); col++)
	{
		for (int row = 0; row < temp[col].size(); row++)
		{
			temp[col][row].SetCoord(row, col);
			//cout << temp[col][row].position.StrVec() << endl;
			if (col == 4 && row == 3)
			{
				temp[row][col].isShip = true;
			}
		}
	}

	map = temp;
}

Vector2 Map::MapSize(vector<vector<Tile>> map)
{
	return Vector2(map.size(), map[0].size());
}