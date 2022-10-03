#include "KeyManager.h"

KeyManager* KeyManager::pInst = nullptr;

void KeyManager::CheckKey()
{
	dwKey = 0;

	if (GetAsyncKeyState(VK_UP) & 0x8000)
	{
		dwKey |= KEY_UP;  // +=0x00000001
	}

	if (GetAsyncKeyState(VK_DOWN) & 0x8000)
	{
		dwKey |= KEY_DOWN;  //+=0x00000002
	}

	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
	{
		dwKey |= KEY_LEFT;  //+=0x00000004
	}

	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
	{
		dwKey |= KEY_RIGHT;  //0x00000008
	}

	if (GetAsyncKeyState(VK_SPACE) & 0x8000)
	{
		dwKey |= KEY_SPACE;  //0x00000010
	}

	if (GetAsyncKeyState(VK_RETURN) & 0x8000)
	{
		dwKey |= KEY_RETURN;  //0x00000016
	}
}
