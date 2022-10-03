#include "CollisionManager.h"
#include "MapManager.h"

CollisionManager* CollisionManager::pInst = nullptr;

bool CollisionManager::CollisionCheck(Obj* first, Obj* second)
{
	if ((first->GetInfo().x == second->GetInfo().x && first->GetInfo().y == second->GetInfo().y) || (first->GetInfo().x == second->GetInfo().x && first->GetInfo().y == second->GetInfo().y + 1))
	{
		return true;
	}

	return false;
}

bool CollisionManager::CollisionCheck2(Obj* first, Obj* second)
{
	for (int i = -1; i < 2; i++)
	{
		if ((first->GetInfo().x == second->GetInfo().x +i && first->GetInfo().y == second->GetInfo().y) || (first->GetInfo().x  == second->GetInfo(). x + i && first->GetInfo().y == second->GetInfo().y + 1))
		{
			return true;
		}
	}


	return false;
}

bool CollisionManager::CollisionCheck(Obj* first, int x, int y)
{
	int check_x = x - first->GetInfo().x;
	int check_y = y - first->GetInfo().y;

	if ((first->GetInfo().rect.Left <= x && x < first->GetInfo().rect.Right) && (first->GetInfo().rect.Top <= y && y < first->GetInfo().rect.Bottom))
	{
		if (first->GetInfo().boolshape[check_y][check_x])
		{
			return true;
		}
	}

	return false;
}

bool CollisionManager::CollisionCheck(SMALL_RECT rect, int x, int y)
{
	if ((rect.Left <= x && x < rect.Right) && (rect.Top <= y && y < rect.Bottom))
	{
		return true;
	}

	return false;
}

//bool CollisionManager::CollisionCheck(SMALL_RECT rect1, SMALL_RECT rect2)
//{
//	if ((rect1.Left < rect2.Right && rect2.Left < rect1.Right) && (rect1.Top < rect2.Bottom && rect2.Top < rect1.Bottom))
//	{
//		return true;
//	}
//
//	return false;
//}

bool CollisionManager::MapCheck(Obj* obj, DIR dir)
{
	switch (dir)
	{
	case LEFT:
		return MapCheckLeft(obj->GetInfo().x, obj->GetInfo().y, obj->x_size, obj->y_size);
		break;
	case RIGHT:
		return MapCheckRight(obj->GetInfo().x, obj->GetInfo().y, obj->x_size, obj->y_size);
		break;
	case TOP:
		return MapCheckTop(obj->GetInfo().x, obj->GetInfo().y, obj->x_size, obj->y_size);
		break;
	case BOTTOM:
		return MapCheckBottom(obj->GetInfo().x, obj->GetInfo().y, obj->x_size, obj->y_size);
		break;
	default:
		break;
	}

	return false;
}

bool CollisionManager::MapCheck(int x, int y)
{
	if (MapManager::GetInst()->GetMapInfo( x, y ) == 1)
	{
		return true;
	}
	return false;
}



bool CollisionManager::MapCheckLeft(int x, int y, int x_size, int y_size)
{
	for (int i = 0; i < y_size; i++)
	{
		if (MapManager::GetInst()->GetMapInfo(x, y + i) == 1)
		{
			return true;
		}

	}
	return false;
}

bool CollisionManager::MapCheckRight(int x, int y, int x_size, int y_size)
{
	for (int i = 0; i < y_size; i++)
	{
		if (MapManager::GetInst()->GetMapInfo(x + x_size - 1, y + i) == 1)
		{
			return true;
		}

	}
	return false;
}

bool CollisionManager::MapCheckTop(int x, int y, int x_size, int y_size)
{
	for (int i = 0; i < x_size; i++)
	{
		if (MapManager::GetInst()->GetMapInfo(x + i, y) == 1)
		{
			return true;
		}
	}
	return false;
}

bool CollisionManager::MapCheckBottom(int x, int y, int x_size, int y_size)
{
	for (int i = 0; i < x_size; i++)
	{
		if (MapManager::GetInst()->GetMapInfo(x + i, y + y_size - 1) == 1)
		{
			return true;
		}
	}
	return false;
}


