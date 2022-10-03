#pragma once
#include "Obj.h"
class CollisionManager
{
private:
	static CollisionManager* pInst;
public:
	static CollisionManager* GetInst()
	{
		if (pInst == nullptr)
		{
			pInst = new CollisionManager;
		}

		return pInst;
	}
public:
	bool CollisionCheck(Obj* first, Obj* second);       
	bool CollisionCheck2(Obj* first, Obj* second);
	bool CollisionCheck(Obj* first, int x, int y);
	bool CollisionCheck(SMALL_RECT rect, int x, int y);

	
public:
	bool MapCheck(Obj* obj, DIR dir);
	bool MapCheck(int x, int y);
	bool MapCheckBottom(int x, int y, int x_size, int y_size);
private:
	bool MapCheckLeft(int x, int y, int x_size, int y_size);
	bool MapCheckRight(int x, int y, int x_size, int y_size);
	bool MapCheckTop(int x, int y, int x_size, int y_size);
};

