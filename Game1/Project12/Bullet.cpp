#include "Bullet.h"
#include "DoubleBuffer.h"
#include "CollisionManager.h"
#include "ObjectPoolManager.h"

void Bullet::Initialize()
{
	info.act = false;
	info.x = 0;
	info.y = 0;
	info.shape[0] = "|";
}

void Bullet::Progress()
{
	if (info.act)
	{
		switch (ObjectPoolManager::GetInst()->player->bulletType)
		{
		case A:
			info.shape[0] = "|";
			break;
		case B:
			info.shape[0] = "¡è ¡è";
			break;
		case C:
			break;
		default:
			break;
		}

		info.y--;

		if (CollisionManager::GetInst()->MapCheck(info.x, info.y))
		{
			info.act = false;
		}

		for (int i = 0; i < EnemyCount; i++)
		{
			Obj* enemy = ObjectPoolManager::GetInst()->enemies[i];

			switch (ObjectPoolManager::GetInst()->player->bulletType)
			{
			case A:
				if (CollisionManager::GetInst()->CollisionCheck(enemy, this))
				{
					info.act = false;
					enemy->SetInfo(false);
				}
				break;
			case B:
				if (CollisionManager::GetInst()->CollisionCheck2(enemy, this))
				{
					info.act = false;
					enemy->SetInfo(false);
				}
				break;
			case C:
				break;
			default:
				break;
			}
		}
	}

	else
	{
		SetInfo(0, 0);
	}




}

void Bullet::Render()
{
	if (info.act)
	{
		if (ObjectPoolManager::GetInst()->player->bulletType == A)
		{
			DoubleBuffer::GetInst()->WriteBuffer(info.x, info.y, info.shape[0], Èò»ö);
		}
		else if (ObjectPoolManager::GetInst()->player->bulletType == B)
		{
			DoubleBuffer::GetInst()->WriteBuffer(info.x - 1, info.y, info.shape[0], Èò»ö);
		}
		
	}
}

void Bullet::Release()
{
}
