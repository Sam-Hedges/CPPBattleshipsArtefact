#include "Grid.h"

void Grid::DrawGridCentered(Map& map) {
	SetupGrid(map.map, Output::Screen::Center);
}

void Grid::DrawGridLeft(Map& map) {
	SetupGrid(map.map, Output::Screen::Left);
}

void Grid::DrawGridRight(Map& map) {
	SetupGrid(map.map, Output::Screen::Right);
}

void Grid::SetupGrid(vector<vector<Tile>>& map, Output::Screen gridOrigin) {

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

	for (int y = 0; y < temp.size(); y++) {

		// Used as temporary variable to store the cumulative text of the current row of tiles
		string currentRow;

		for (int x = 0; x < temp[y].size(); x++) {

			// Set each tile to its' coordinate in the 2D vector
			temp[y][x].SetCoord(y, x);

			// Assigns the Y axis values of the grid (alphabet)
			if (y == 0) {

				// The top left corner case is dealt with in this x axis
				//
				// If corner of grid return empty, otherwise cycle through alphabet
				const char c = x == 0 ? 32 : 96 + x;

				// Save char as a string to concatenate with padding
				string output(1, c);

				// Set tile text
				temp[y][x].screenText = output + " ";
			}

			// Assigns the X axis values of the grid (numerical)
			if (x == 0 && y != 0) {

				// Save current y value as string for the Y axis
				string output = to_string(y);

				// Set tile text
				temp[y][x].screenText = output + " ";
			}

			// Assigns the values of the grid play area
			if (y != 0 && x != 0) {

				Tile& currentTile = map[x - 1][y - 1];

				switch (currentTile.isShip ? (currentTile.attacked ? 3 : 2) : 1) {
				case 1:
					temp[y][x].screenText = ". ";
					break;
				case 2:
					temp[y][x].screenText = "S ";
					break;
				case 3:
					temp[y][x].screenText = "X ";
					break;
				default:
					break;
				}

				// Sets the text of the referenced map to the start values of the temp grid
				currentTile.screenText = temp[y][x].screenText;

				#pragma region Set Screen Position

				// Get the current Y axis number as a string
				string yAxisStr = to_string(y);

				// Length of the line is (length of row * (2 to take into account padding)) +
				// (the length of the yAxisStr + (1 for padding))
				int lineLen = (map.size() * 2) + (yAxisStr.size() + 1);

				// The centered start position on the screen based on the screenWidth and lineLength
				int startPos = GetScreenPosition(currentScreenSize.X, lineLen, gridOrigin);

				// Set a COORD to the centered startPos adjusted for the current tile position
				COORD scrPos = { startPos + x * 2, CSBI.dwCursorPosition.Y + 1};

				// Sets the current tiles' screen position
				currentTile.SetScreenPos(scrPos);

				#pragma endregion
			}

			// Get Current row of text from the grid
			currentRow += temp[y][x].screenText;

		}

		// Repeated to collect current console screen buffer data  
		GetConsoleScreenBufferInfo(h_out, &CSBI);

		// Gets the length of the string
		const int stringLength = strlen(currentRow.c_str());

		// Figure out how many spaces in needed in order for string to be centered
		const int screenPos = GetScreenPosition(currentScreenSize.X, stringLength, gridOrigin);

		// Initialise a new position screenPos amount of spaces in X axis
		COORD pos = { screenPos, CSBI.dwCursorPosition.Y };

		// If the current row is greater than 10 then adjust the padding of the line
		if (y >= 10) { pos.X -= 1; }

		// Sets the cursor position to the coordinate passed in
		SetConsoleCursorPosition(h_out, pos);

		// Print the current row out to the console
		cout << currentRow << endl;
	}

	// Sets the cursor position to the corner
	COORD pos = CSBI.dwMaximumWindowSize; pos.X -= 1; pos.Y -= 1;
	SetConsoleCursorPosition(h_out, pos);
}

int Grid::GetScreenPosition(int screenWidth, int stringLength, Output::Screen origin) {

	switch (origin) {
		case Output::Screen::Center:
			return (screenWidth - stringLength) / 2;
		case Output::Screen::Left:
			return (screenWidth - stringLength) / 4;
		case Output::Screen::Right:
			return ((screenWidth - stringLength) / 4) * 3;
		default:
			return 0;
	}
}