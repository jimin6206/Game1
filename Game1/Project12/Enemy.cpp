#include "Enemy.h"
#include "DoubleBuffer.h"
#include "ObjectPoolManager.h"
#include "CollisionManager.h"

void Enemy::Initialize()
{
	info.act = true; 
	info.shape[0] = "��";

	SetInfo(rand() % 36 + 2, -ObjectPoolManager::GetInst()->currentnumber);
}

void Enemy::Progress()
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

void Enemy::Render()
{
	if (info.act && info.y >= 2)
	{
		DoubleBuffer::GetInst()->WriteBuffer(info.x, info.y , info.shape[0], �ʷϻ�);
	}
}


void Enemy::Release()
{

}

