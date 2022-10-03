#include "Enemy2.h"
#include "DoubleBuffer.h"
#include "ObjectPoolManager.h"
#include "CollisionManager.h"

void Enemy2::Initialize()
{
	info.act = true;
	info.shape[0] = "¡ß";

	if (ObjectPoolManager::GetInst()->currentnumber < EnemyCount/2)
	{
		SetInfo(ObjectPoolManager::GetInst()->currentnumber + 2, - ObjectPoolManager::GetInst()->currentnumber);
	}
	else
	{
		SetInfo(ObjectPoolManager::GetInst()->currentnumber + 2 ,  -36 + ObjectPoolManager::GetInst()->currentnumber );
	}
}

void Enemy2::Progress()
{
	if (info.act)
	{
		info.y++;
		if (info.y >= 38)
		{
			info.act = false;
		}
	}

	else
	{
		SetInfo(0, 0);
	}

}

void Enemy2::Render()
{
	if (info.act && info.y >= 2)
	{
		DoubleBuffer::GetInst()->WriteBuffer(info.x, info.y, info.shape[0], ÃÊ·Ï»ö);
	}
}


void Enemy2::Release()
{

}

