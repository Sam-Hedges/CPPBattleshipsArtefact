#include "Vector2.h"

Vector2::Vector2()
{
	x = 0;
	y = 0;
}

Vector2::Vector2(int x, int y)
{
	this->x = x;
	this->y = y;
}

string Vector2::StrVec()
{
	stringstream ss;
	ss << x << ", " << y;
	string s = ss.str();
	return s;
}