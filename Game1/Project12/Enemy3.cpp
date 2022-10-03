#include "Enemy3.h"
#include "DoubleBuffer.h"
#include "ObjectPoolManager.h"
#include "CollisionManager.h"

void Enemy3::Initialize()
{
	info.act = true;
	info.shape[0] = "¡ß";

	int current = ObjectPoolManager::GetInst()->currentnumber;

	if ( current < 6 )
	{
		SetInfo(current + 2, current - 6);
	}
	else if(6 <= current && current <12)
	{
		SetInfo(current + 2, 6 - current);
	}
	else if (12 <= current && current < 18)
	{
		SetInfo(current + 2, current - 18);
	}
	else if (18 <= current && current < 24)
	{
		SetInfo(current + 2, 18 - current);
	}
	else if (24 <= current && current < 30)
	{
		SetInfo(current + 2, current - 30);
	}
	else if (30 <= current && current < 36)
	{
		SetInfo(current + 2, 30 - current);
	}
}

void Enemy3::Progress()
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

void Enemy3::Render()
{
	if (info.act && info.y >= 2)
	{
		DoubleBuffer::GetInst()->WriteBuffer(info.x, info.y, info.shape[0], ÃÊ·Ï»ö);
	}
}

void Enemy3::Release()
{
}
