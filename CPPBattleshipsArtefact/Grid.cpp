#include "Grid.h"

void Grid::DrawGrid(vector<vector<Tile>> &map)
{
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
			temp[y][x].SetCoord(y, x);

			if (y == 0)
			{
				// If corner of grid; return empty; otherwise cycle through alphabet
				const char c = x == 0 ? 32 : 96 + x;
				string output(1, c);

				// Cast acsii value to a char and print
				gridLines[y] += output + " ";
				//cout << output << " ";
			}

			if (x == 0)
			{
				if (y == 0) { continue; }

				string output = to_string(y);

				gridLines[y] += output + " ";
				//cout << y << (y < 10 ? " " : "");
			}

			if (y != 0 && x != 0)
			{
				if (map[y-1][x-1].isShip)
				{
					gridLines[y] += "S ";
					//cout << "S ";
				}
				else
				{
					gridLines[y] += ". ";
					//cout << ". ";
				}

				string yAxisStr = to_string(y);
				int lineLen = ((temp.size() - 1) * 2) + (yAxisStr.size() + 1);
				int startPos = (currentScreenSize.X - lineLen) / 2;
				int xCoord = startPos + (x - 1) * 2;
				int yCoord = y;
				map[y-1][x-1].SetScreenPos(xCoord, yCoord);
			}
		}
	}

	for (int y = 0; y < gridLines.size(); y++)
	{
		// Repeated to collect current data 
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

	Output::OverridePrint(".", map[3][5].screenPos, 0, 1);

	// Sets the cursor position to the corner
	COORD pos = CSBI.dwMaximumWindowSize; pos.X -= 1; pos.Y -= 1;
	SetConsoleCursorPosition(h_out, pos);
}

void Grid::Setup(Map& map)
{

}