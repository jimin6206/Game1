#include "BossStage.h"
#include "ObjectPoolManager.h"
#include "MapManager.h"

void BossStage::Initialize()
{
	ObjectPoolManager::GetInst()->CreateObject();
}

void BossStage::Progress()
{
	ObjectPoolManager::GetInst()->player->Progress();
	
	for (int i = 0; i < BulletCount; i++)
	{
		ObjectPoolManager::GetInst()->bullets[i]->Progress();
	}

	for (int i = 0; i < BossCount; i++)
	{
		ObjectPoolManager::GetInst()->boss[i]->Progress();
	}

	for (int i = 0; i < BulletCount; i++)
	{
		ObjectPoolManager::GetInst()->bossbullet[i]->Progress();
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

void BossStage::Render()
{
	
	MapManager::GetInst()->Render();
	
	ObjectPoolManager::GetInst()->player->Render();
	for (int i = 0; i < BulletCount; i++)
	{
		ObjectPoolManager::GetInst()->bullets[i]->Render();
	}
	
	for (int i = 0; i < BossCount; i++)
	{
		ObjectPoolManager::GetInst()->boss[i]->Render();
	}
	for (int i = 0; i < BulletCount; i++)
	{
		ObjectPoolManager::GetInst()->bossbullet[i]->Render();
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

void BossStage::Release()
{
	ObjectPoolManager::GetInst()->player->Release();
	for (int i = 0; i < BulletCount; i++)
	{
		ObjectPoolManager::GetInst()->bullets[i]->Release();
	}
	for (int i = 0; i < BossCount; i++)
	{
		ObjectPoolManager::GetInst()->boss[i]->Release();
	}
	for (int i = 0; i < BulletCount; i++)
	{
		ObjectPoolManager::GetInst()->bossbullet[i]->Release();
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
