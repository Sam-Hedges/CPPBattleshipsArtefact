#include "Game.h"

Game::Game() {

}

void Game::SetupShips() {
	
	COORD mapSize { 10, 10 };

	string title = "Please Choose a difficulty: ";
	vector<string> options = { "Easy", "Medium", "Hard" };

	const int index = Menu::DisplayMenu(title, options);

	switch (index) {
	case 0:
		mapSize = { 10, 10 };
		break;
	case 1:
		mapSize = { 12, 12 };
		break;
	case 2:
		mapSize = { 15, 15 };
		break;
	}

	Map tempMap(mapSize);
	map = tempMap;

	Output::PrintCentered("Please place all of your ships");
	Output::PrintCentered("Arrow keys to move ships");
	Output::PrintCentered("Space to rotate ships");
	Output::PrintCentered("Enter to confirm placement");
	cout << endl;

	Grid::DrawGridCentered(map);

	COORD currentPosition{0,0};
	int currentRot = 0;
	vector<Tile> currentTiles;
	vector<Tile> previousTiles;
	//int& currentShip;

	while (true) {

		COORD currentScreenPos = map.map[currentPosition.Y][currentPosition.X].screenPos;

		Output::OverridePrint(to_string(currentPosition.Y).c_str(), currentScreenPos, 0, 1);
		// Pauses the system for an input
		// The >nul stops it printing a message
		system("pause>nul");

		if (Input::UpArrow) {
			currentPosition.Y = currentPosition.Y - 1;
			currentPosition.Y = currentPosition.Y < 0 ? mapSize.Y : currentPosition.Y;
		}
		else if (Input::DownArrow) {
			currentPosition.Y = currentPosition.Y + 1;
			currentPosition.Y = currentPosition.Y > mapSize.Y-- ? 0 : currentPosition.Y;
		}
		else if (Input::LeftArrow) {
			currentPosition.X = currentPosition.X - 1;
			currentPosition.X = currentPosition.Y < 0 ? 0 : currentPosition.X;
		}
		else if (Input::RightArrow) {
			currentPosition.Y = currentPosition.X + 1;
			currentPosition.Y = currentPosition.X > mapSize.X-- ? mapSize.X-- : currentPosition.X;
		}
		else if (Input::Enter) {

		}
		else if (Input::Space) {

		}

		Output::OverridePrint(to_string(currentPosition.Y).c_str(), currentScreenPos, 0, 1);
	}
}