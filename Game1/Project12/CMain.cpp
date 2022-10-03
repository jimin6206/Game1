#include "Game.h"

int main()
{
	Game game;
	game.Initialize();

	ULONGLONG ullTime = GetTickCount64();

	while (true)
	{
		if (ullTime + 30 < GetTickCount64())
		{

			game.Progress();
			game.Render();

			ullTime = GetTickCount64();
		}
	}

	game.Release();
}