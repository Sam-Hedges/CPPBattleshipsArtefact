#include "Tile.h"

void Tile::SetCoord(int x, int y)
{
	position.X = x;
	position.Y = y;
}

void Tile::SetScreenPos(int x, int y)
{
	screenPos.X = x;
	screenPos.Y = y;
}

void Tile::SetScreenPos(COORD pos)
{
	screenPos.X = pos.X;
	screenPos.Y = pos.Y;
}