#include "Stage.h"
#include "ObjectPoolManager.h"
#include "MapManager.h"
#include "SceneManager.h"
#include <time.h>

void Stage::Initialize()
{
	ObjectPoolManager::GetInst()->CreateObject();
	index = 0;
	//bosstime = true;
	time = 0;
}

void Stage::Progress()
{
	time++;

	if (time>500)
	{
		SceneManager::GetInst()->SetScene(BOSSSTAGE);
	}

	int end = 0;

	ObjectPoolManager::GetInst()->player->Progress();

	for (int i = 0; i < BulletCount; i++)
	{
		ObjectPoolManager::GetInst()->bullets[i]->Progress();
	}


	//for (int i = 0; i < BossCount; i++)
	//{
	//	ObjectPoolManager::GetInst()->boss[i]->Progress();
	//}
	

	for (int i = 0; i < EnemyCount; i++)
	{
		if (!ObjectPoolManager::GetInst()->enemies[i]->GetInfo().act)
		{
			end++;
		}
		ObjectPoolManager::GetInst()->enemies[i]->Progress();
	}

	
	if (end >= EnemyCount)
	{
		index = rand()%3;
		ObjectPoolManager::GetInst()->SetEnemyPattern(index);
	}


	for (int i = 0; i < ItemCount; i++)
	{
		ObjectPoolManager::GetInst()->items[i]->Progress();
	}

	for (int i = 0; i < Item2Count; i++)
	{
		ObjectPoolManager::GetInst()->items2[i]->Progress();
	}


}

void Stage::Render()
{
	MapManager::GetInst()->Render();

	ObjectPoolManager::GetInst()->player->Render();
	for (int i = 0; i < BulletCount; i++)
	{
		ObjectPoolManager::GetInst()->bullets[i]->Render();
	}

	//for (int i = 0; i < BossCount; i++)
	//{
	//	ObjectPoolManager::GetInst()->boss[i]->Render();
	//}

	for (int i = 0; i < EnemyCount; i++)
	{
		ObjectPoolManager::GetInst()->enemies[i]->Render();
	}


	for (int i = 0; i < ItemCount; i++)
	{
		ObjectPoolManager::GetInst()->items[i]->Render();
	}
	for (int i = 0; i < Item2Count; i++)
	{
		ObjectPoolManager::GetInst()->items2[i]->Render();
	}

}

void Stage::Release()
{
	ObjectPoolManager::GetInst()->player->Release();
	for (int i = 0; i < BulletCount; i++)
	{
		ObjectPoolManager::GetInst()->bullets[i]->Release();
	}
	//for (int i = 0; i < BossCount; i++)
	//{
	//	ObjectPoolManager::GetInst()->boss[i]->Release();
	//}

	for (int i = 0; i < EnemyCount; i++)
	{
		ObjectPoolManager::GetInst()->enemies[i]->Release();
	}

	for (int i = 0; i < ItemCount; i++)
	{
		ObjectPoolManager::GetInst()->items[i]->Release();
	}

	for (int i = 0; i < Item2Count; i++)
	{
		ObjectPoolManager::GetInst()->items2[i]->Release();
	}
}
