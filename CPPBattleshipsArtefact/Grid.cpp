#include "Grid.h"

void Grid::DrawGrid(const vector<vector<Tile>> &map)
{
	vector<vector<Tile>> temp(map.size() + 1, vector<Tile>(map[0].size() + 1, Tile()));

	for (int y = 0; y < temp.size(); y++)
	{
		for (int x = 0; x < temp[y].size(); x++)
		{
			temp[y][x].SetCoord(y, x);

			if (y == 0)
			{
				// If corner of grid return empty otherwise cycle through alphabet
				const char output = x == 0 ? 32 : 96 + x;

				// Cast acsii value to a char and print
				cout << output << " ";
			}

			if (x == 0)
			{
				if (y == 0) { continue; }

				cout << y << (y < 10 ? " " : "");
			}

			if (y != 0 && x != 0)
			{
				if (map[y-1][x-1].isShip)
				{
					cout << "S ";
				}
				else
				{
					cout << ". ";
				}
			}
		}
		cout << endl;
	}


}
