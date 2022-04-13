#include "Input.h"

// This class serves as a wrapper to make calling inputs more human readable
// in other parts of this program.
//
// GetAsyncKeyState() returns if a key was up or down at the time called.
// The key is determined by a virtual-key code; ref "https://rb.gy/tjnpjk".

SHORT Input::UpArrow() { return GetAsyncKeyState(VK_UP); }

SHORT Input::DownArrow() { return GetAsyncKeyState(VK_DOWN); }

SHORT Input::LeftArrow() { return GetAsyncKeyState(VK_RIGHT); }

SHORT Input::RightArrow() {	return GetAsyncKeyState(VK_LEFT); }

SHORT Input::Enter() { return GetAsyncKeyState(VK_RETURN); }

SHORT Input::Space() { return GetAsyncKeyState(VK_SPACE); }
