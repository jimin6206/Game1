#include "MapManager.h"
#include "DoubleBuffer.h"

MapManager* MapManager::pInst = nullptr;

int MapManager::GetMapInfo(int x, int y)
{
	return map[y][x];
}

void MapManager::SetMapInfo(int x, int y, int value)
{
	map[y][x] = value;
}

void MapManager::Render()
{
	for (int y = 0; y < 40; y++)
	{
		for (int x = 0; x < 40; x++)
		{
			switch (map[y][x])
			{
			case 0:
				break;
			case 1:
				DoubleBuffer::GetInst()->WriteBuffer(x,y,"¡á",Èò»ö);
				break;
			default:
				break;
			}
		}
	}
}
