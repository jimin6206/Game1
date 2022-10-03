#include "ObjectPoolManager.h"
#include <time.h>

ObjectPoolManager* ObjectPoolManager::pInst = nullptr;

void ObjectPoolManager::CreateObject()
{

	player = ObjectFactory::GetInst()->CreateObj(PLAYER);

	for (int i =0; i < BulletCount; i++)
	{
		bullets[i] = ObjectFactory::GetInst()->CreateObj(BULLET);
	}

	for (int i = 0; i < EnemyCount; i++)
	{
		currentnumber = i;
		enemies[i] = ObjectFactory::GetInst()->CreateObj(ENEMY3);
	}

	for (int i = 0; i < ItemCount; i++)
	{
		items[i] = ObjectFactory::GetInst()->CreateObj(ITEM);
	}

	for (int i = 0; i < Item2Count; i++)
	{
		items2[i] = ObjectFactory::GetInst()->CreateObj(ITEM2);
	}

	for (int i = 0; i < BossCount; i++)
	{
		boss[i] = ObjectFactory::GetInst()->CreateObj(BOSS);
	}

	for (int i = 0; i < BulletCount ; i++)
	{
		bossbullet[i] = ObjectFactory::GetInst()->CreateObj(BOSSBULLET);
	}

}

void ObjectPoolManager::SetEnemyPattern(int index)
{
	for (int i = 0; i < EnemyCount; i++)
	{
		if (enemies[i] != nullptr)
		{
			delete(enemies[i]);
			enemies[i] = nullptr;
		}
	}
	
	

	for (int i = 0; i < EnemyCount; i++)
	{

		switch (index)
		{
		case 0:
			currentnumber = i;
			enemies[i] = ObjectFactory::GetInst()->CreateObj(ENEMY);
			enemies[i]->Initialize();
			break;
		case 1:
			currentnumber = i;
			enemies[i] = ObjectFactory::GetInst()->CreateObj(ENEMY2);
			enemies[i]->Initialize();
			break;
		case 2:
			currentnumber = i;
			enemies[i] = ObjectFactory::GetInst()->CreateObj(ENEMY3);
			enemies[i]->Initialize();
			break;

		}
	}

}


