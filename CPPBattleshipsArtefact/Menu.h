#pragma once
#include <iostream>
#include <vector>
#include <cstdlib>
#include "Grid.h"
#include "Input.h"
#include "Output.h"
using namespace std;

class Menu
{
public:
	static int DisplayMenu(string& title, vector<string> options);
};

