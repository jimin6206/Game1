#include "Player.h"
#include "DoubleBuffer.h"
#include "ObjectPoolManager.h"
#include "CollisionManager.h"
#include "KeyManager.h"
#include "SceneManager.h"

void Player::Initialize()
{
	SetInfo(true);
	SetInfo(10, 30);
	SetInfo(¹àÀº³ë¶õ»ö);

	info.shape[0] = "    __£¡__    ";
	info.shape[1] = "_____(£ß)_____";
	info.shape[2] = "   !  £¡  !   ";

	x_size = 7;
	y_size = 3;

	bulletType = A;

	int boolshape[3][7] =
	{
		{0,0,1,1,1,0,0},
		{1,1,1,1,1,1,1},
		{0,1,1,1,1,1,0},
	};

	for (int i = 0; i < 3; i++)
	{	
		for (int j = 0; j < 7; j++)
		{
			info.boolshape[i][j] = boolshape[i][j];
		}
	}

	player_item = false;
	enemy_collision = false;
	heart_collision = false;

	heartcount = 3;
	itemcount = 0;

}

void Player::Progress()
{

	DWORD dwKey = KeyManager::GetInst()->GetKey();

	if (dwKey & KEY_LEFT)
	{
		info.x--;
		if (CollisionManager::GetInst()->MapCheck(this,LEFT))
		{
			info.x++;
		}
	}
	if (dwKey & KEY_RIGHT)
	{
		info.x++;
		if (CollisionManager::GetInst()->MapCheck(this, RIGHT))
		{
			info.x--;
		}
	}	
	if (dwKey & KEY_UP)
	{
		info.y--;
		if (CollisionManager::GetInst()->MapCheck(this, TOP))
		{
			info.y++;
		}
	}
	if (dwKey & KEY_DOWN)
	{
		info.y++;
		if (CollisionManager::GetInst()->MapCheck(this, BOTTOM))
		{
			info.y--;
		}
	}

	SetInfo(info.x, info.y);

	if (dwKey & KEY_SPACE)
	{
		Obj* bullet = nullptr;

		for (int i = 0; i < BulletCount; i++)
		{
			if (ObjectPoolManager::GetInst()->bullets[i]->GetInfo().act == false)
			{
				bullet = ObjectPoolManager::GetInst()->bullets[i];
				break;
			}
		}

		if (bullet != nullptr)
		{
			bullet->SetInfo(info.x + 3, info.y);
			bullet->SetInfo(true);
		}
	}

	for (int i = 0; i < BossCount; i++)
	{
		Obj* boss = ObjectPoolManager::GetInst()->boss[i];

		if (CollisionManager::GetInst()->CollisionCheck(this, boss->GetInfo().x, boss->GetInfo().y))
		{
			boss->SetInfo(false);
			enemy_collision = true;
			break;
		}
	}


	for (int i = 0; i < EnemyCount; i++)
	{
		Obj* enemy = ObjectPoolManager::GetInst()->enemies[i];

		if (CollisionManager::GetInst()->CollisionCheck(this, enemy->GetInfo().x, enemy->GetInfo().y))
		{
			enemy->SetInfo(false);
			enemy_collision = true;
			break;
		}
	}

	if (enemy_collision)
	{
		enemy_collision = false;
		heartcount--;
	}

	for (int i = 0; i < ItemCount; i++)
	{
		Obj* item = ObjectPoolManager::GetInst()->items[i];

		if (CollisionManager::GetInst()->CollisionCheck(this, item->GetInfo().x, item->GetInfo().y))
		{
			item->SetInfo(false);

			player_item = true;
			bulletType = B;
		}
	}

	for (int i = 0; i < Item2Count; i++)
	{
		Obj* item2 = ObjectPoolManager::GetInst()->items2[i];

		if (CollisionManager::GetInst()->CollisionCheck(this, item2->GetInfo().x, item2->GetInfo().y))
		{
			item2->SetInfo(false);

			heart_collision = true;

			break;
		}
	}

	if (player_item)
	{
		itemcount++;
		if (itemcount > 100)
		{
			player_item = false;
			bulletType = A;
			itemcount = 0;
		}
	}

	if (heart_collision)
	{
		heart_collision = false;
		heartcount++;
	}
	
	if (heartcount < 0)
	{
		SceneManager::GetInst()->SetScene(GAMEOVER);
	}
}

void Player::Render()
{
   
	for (int i = 0; i < 3; i++)
	{
		DoubleBuffer::GetInst()->WriteBuffer(info.x, info.y + i , info.shape[i], ¹àÀº³ë¶õ»ö);
		
	}

	for (int i = 0; i < heartcount; i++)
	{
		
		DoubleBuffer::GetInst()->WriteBuffer(42 + i, 5, "¢¾ ", ¹àÀº»¡°£»ö);
		
	}

}

void Player::Release()
{

}
