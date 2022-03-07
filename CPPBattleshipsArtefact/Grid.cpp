#include "Grid.h"

void Grid::DrawGrid(vector<vector<Tile>> &map)
{
	// Used as a container to draw the grid
	vector<vector<Tile>> temp(map.size() + 1, vector<Tile>(map[0].size() + 1, Tile()));

	vector<string> gridLines(map.size() + 1, "");

	// Used to store data on the current console screen buffer
	CONSOLE_SCREEN_BUFFER_INFO CSBI;

	// Gets the standard output device; the active console screen-buffer
	const HANDLE h_out = GetStdHandle(STD_OUTPUT_HANDLE);

	// Stores the data of hOut in csbi via a reference 
	GetConsoleScreenBufferInfo(h_out, &CSBI);

	// Saves the current screen size of the active console screen-buffer
	const COORD currentScreenSize = CSBI.dwSize;

	for (int y = 0; y < temp.size(); y++)
	{
		for (int x = 0; x < temp[y].size(); x++)
		{
			// The Current Coordinate - 1
			const COORD CCM = { x - 1, y - 1 };

			// Set each tile to its' coordinate in the 2D vector
			temp[y][x].SetCoord(y, x);

			// Draws the Y axis of the grid
			if (y == 0)
			{
				// If corner of grid; return empty; otherwise cycle through alphabet
				const char c = x == 0 ? 32 : 96 + x;

				// Save char as a string to concatenate with padding
				string output(1, c);

				// Set tile text
				gridLines[y] += output + " ";
			}

			// Draws the X axis of the grid
			if (x == 0)
			{
				// If this is the top left corner tile leave empty
				if (y == 0) { continue; }

				// Save current y value as string for the Y axis
				string output = to_string(y);

				// Set tile text
				gridLines[y] += output + " ";
			}

			if (y != 0 && x != 0)
			{
				Tile &currentTile = map[x - 1][y - 1];

				switch (currentTile.isShip ? (currentTile.attacked ? 3 : 2) : 1)
				{
					case 1:
						gridLines[y] += ". ";
						break;
					case 2:
						gridLines[y] += "S ";
						break;
					case 3:
						gridLines[y] += "X ";
						break;
					default:
						break;
				}

				string yAxisStr = to_string(y);
				int lineLen = ((temp.size() - 1) * 2) + (yAxisStr.size() + 1);
				int startPos = (currentScreenSize.X - lineLen) / 2;
				COORD scrPos = { startPos + (x - 1) * 2, y - 1};
				currentTile.SetScreenPos(scrPos);
			}
		}
	}

	for (int y = 0; y < gridLines.size(); y++)
	{
		// Repeated to collect current console screen buffer data  
		GetConsoleScreenBufferInfo(h_out, &CSBI);

		// Gets the length of the string
		const int stringLength = strlen(gridLines[y].c_str());

		// Figure out how many spaces in needed in order for string to be centered
		const int screenPos = (currentScreenSize.X - stringLength) / 2;

		// Initialise a new position screenPos amount of spaces in X axis
		COORD pos; pos.X = screenPos; pos.Y = CSBI.dwCursorPosition.Y;
		if (y >= 10) { pos.X -= 1; }

		// Sets the cursor position to the coordinate passed in
		SetConsoleCursorPosition(h_out, pos);

		cout << gridLines[y] << endl;
	}
	string str = to_string(temp[3][5].position.X) + ", " + to_string(temp[3][5].position.Y);
	Output::OverridePrint(str.c_str(), map[3][5].screenPos, 0, 1);

	// Sets the cursor position to the corner
	COORD pos = CSBI.dwMaximumWindowSize; pos.X -= 1; pos.Y -= 1;
	SetConsoleCursorPosition(h_out, pos);
}

void Grid::Setup(Map& map)
{

}