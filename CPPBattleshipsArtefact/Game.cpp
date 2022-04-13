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

		COORD currentScreenPos = map.map[currentPosition.X][currentPosition.Y].screenPos;

		Output::OverridePrint(".", currentScreenPos, 0, 1);
		Output::HideCursor();

		// Pauses the system for an input
		// The >nul stops it printing a message
		system("pause>nul");

		if (Input::UpArrow()) {
			currentPosition.Y--;
			currentPosition.Y = currentPosition.Y < 0 ? mapSize.Y - 1 : currentPosition.Y;
		}
		else if (Input::DownArrow()) {
			currentPosition.Y++;
			currentPosition.Y = currentPosition.Y > mapSize.Y - 1 ? 0 : currentPosition.Y;
		}
		else if (Input::LeftArrow()) {
			currentPosition.X++;
			currentPosition.X = currentPosition.X > mapSize.X - 1 ? 0 : currentPosition.X;
		}
		else if (Input::RightArrow()) {
			currentPosition.X--;
			currentPosition.X = currentPosition.X < 0 ? mapSize.X - 1 : currentPosition.X;
		}
		else if (Input::Enter()) {

		}
		else if (Input::Space()) {

		}

		Output::OverridePrint(".", currentScreenPos, 0, 0);
		Output::HideCursor();
	}
}