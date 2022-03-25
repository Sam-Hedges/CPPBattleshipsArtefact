#include "Game.h"

Game::Game() {

}

void Game::SetupShips() {
	
	COORD mapSize{10, 10};

	string title = "Please Choose a difficulty: ";
	vector<string> options = { "Easy", "Medium", "Hard" };

	const int index = Menu::DisplayMenu(title, options);

	switch (index) {
	case 0:
		mapSize = { 10, 10 };
		system("pause>nul");
		break;
	case 1:
		mapSize = { 12, 12 };
		system("pause>nul");
		break;
	case 2:
		mapSize = { 15, 15 };
		system("pause>nul");
		break;
	}

	Map tempMap(mapSize);
	map = tempMap;

	cout << "Please place all of your ships" << endl;
	cout << "Arrow keys to move ships" << endl;
	cout << "Space to rotate ships" << endl;
	cout << "Enter to confirm placement" << endl;
	cout << endl;

	Grid::DrawGridCentered(map);

	while (true) {

	}
}