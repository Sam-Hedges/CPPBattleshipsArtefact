#pragma once
#include <iostream>
#include <vector>
#include <cstdlib>
#include "Output.h"
#include "Tile.h"
#include "Map.h"
#include "Grid.h"
#include "Menu.h"
#include "Input.h"
using namespace std;

class Game
{
	private:
		Map map;

	public:
		Game();
		void SetupShips();
};

