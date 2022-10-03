#include "Boss.h"
#include "DoubleBuffer.h"
#include "ObjectPoolManager.h"
#include "CollisionManager.h"
#include "SceneManager.h"

void Boss::Initialize()
{
	info.act = true;

	SetInfo(20, 5);

	info.shape[0] = " ^ ^";
	info.shape[1] = "(O,O)";
	info.shape[2] = "(   )";
	info.shape[3] = "-\"-\"-";

	hp = 3;

	x_size = 3;
	y_size = 4;

	info.dir = LEFT;

	collision = false;
	
}

void Boss::Progress()
{
	if (info.act)
	{
		switch (info.dir)
		{
		case LEFT:
			info.x--;
			if (CollisionManager::GetInst()->MapCheck(this, LEFT))
			{
				info.x++;
				info.dir = RIGHT;
			}
			break;
		case RIGHT:
			info.x++;
			if (CollisionManager::GetInst()->MapCheck(this, RIGHT))
			{
				info.x--;
				info.dir = LEFT;
			}
			break;
		default:
			break;
		}

		SetInfo(info.x, info.y);

		for (int i = 0; i < BulletCount; i++)
		{
			Obj* bullet = ObjectPoolManager::GetInst()->bullets[i];

			if (CollisionManager::GetInst()->CollisionCheck(info.rect, bullet->GetInfo().x, bullet->GetInfo().y))
			{
				collision = true;
				bullet->SetInfo(false);
				break;
			}
		}

		if (collision)
		{
			collision = false;
			hp--;
		}

		if (hp < 1)
		{
			SetInfo(false);
		}
	}
	else
	{
		SetInfo(0, 0);
		SceneManager::GetInst()->SetScene(STAGE);
	}


	for (int i = 0; i < BulletCount; i++)
	{
		Obj* bullet = ObjectPoolManager::GetInst()->bossbullet[i];
		if (!bullet->GetInfo().act)
		{
			bullet->SetInfo(info.x+1, info.y+2);
			bullet->SetInfo(true);
			break;
		}
	}
}

void Boss::Render()
{
	if (info.act && info.y >= 2)
	{
		for (int i = 0; i < 4; i++)
		{
			DoubleBuffer::GetInst()->WriteBuffer(info.x, info.y +i, info.shape[i], 초록색);
		}
		for (int i = 0; i < hp; i++)
		{
			DoubleBuffer::GetInst()->WriteBuffer(info.x + i , info.y - 1, "■", 빨간색);
		}
	}
}

void Boss::Release()
{
}
