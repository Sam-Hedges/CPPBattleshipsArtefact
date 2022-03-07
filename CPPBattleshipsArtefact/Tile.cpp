#include "Tile.h"

void Tile::SetCoord(int x, int y)
{
	position.X = x;
	position.Y = y;
}

void Tile::SetCoord(COORD pos)
{
	position.X = pos.X;
	position.Y = pos.Y;
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