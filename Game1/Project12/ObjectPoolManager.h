#pragma once
#include "ObjectFactory.h"

class ObjectPoolManager
{
private:
	static ObjectPoolManager* pInst;
public:
	static ObjectPoolManager* GetInst()
	{
		if (pInst == nullptr)
		{
			pInst = new ObjectPoolManager;
		}

		return pInst;
	}

public:
	Obj* player;
	Obj* bullets[BulletCount];
	Obj* enemies[EnemyCount];
	Obj* items[ItemCount];
	Obj* items2[Item2Count];
	Obj* boss[BossCount];
	Obj* bossbullet[BulletCount];
	int currentnumber;


public:
	void CreateObject();
	void SetEnemyPattern(int index);
};
