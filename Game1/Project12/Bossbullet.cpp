#include "Bossbullet.h"
#include "DoubleBuffer.h"
#include "CollisionManager.h"
#include "ObjectPoolManager.h"

void Bossbullet::Initialize()
{
	info.act = false;
	info.x = 0;
	info.y = 0;
	info.shape[0] = "¡Ü";
}

void Bossbullet::Progress()
{
	if (info.act)
	{
		info.y++;

		if (CollisionManager::GetInst()->MapCheck(info.x, info.y))
		{
			info.act = false;
		}

		for (int i = 0; i < BulletCount; i++)
		{
			Obj* bullet = ObjectPoolManager::GetInst()->bullets[i];

			if (CollisionManager::GetInst()->CollisionCheck(this, bullet))
			{
				info.act = false;
				bullet->SetInfo(false);
			}
		}
	}
}

void Bossbullet::Render()
{
	if (info.act)
	{
		DoubleBuffer::GetInst()->WriteBuffer(info.x, info.y, info.shape[0], ÃÊ·Ï»ö);
	}
}

void Bossbullet::Release()
{
}
