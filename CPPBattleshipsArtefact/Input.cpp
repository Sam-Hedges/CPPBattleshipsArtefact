#include "Input.h"

SHORT Input::UpArrow() { return GetAsyncKeyState(VK_UP); }

SHORT Input::DownArrow() { return GetAsyncKeyState(VK_DOWN); }

SHORT Input::LeftArrow() { return GetAsyncKeyState(VK_RIGHT); }

SHORT Input::RightArrow() {	return GetAsyncKeyState(VK_LEFT); }

SHORT Input::Enter() { return GetAsyncKeyState(VK_RETURN); }

SHORT Input::Space() { return GetAsyncKeyState(VK_SPACE); }