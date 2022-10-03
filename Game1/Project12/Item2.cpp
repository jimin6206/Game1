#include "Item2.h"
#include "DoubleBuffer.h"
#include "ObjectPoolManager.h"
#include "CollisionManager.h"


void Item2::Initialize()
{
	info.act = true;
	info.shape[0] = "¢¾";

	SetInfo(rand() % 36 + 2, 2);

}

void Item2::Progress()
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
		info.act = true;
		
		SetInfo(rand()%36+2, 2);
	}
}

void Item2::Render()
{
	if (info.act && info.y >= 2)
	{
		DoubleBuffer::GetInst()->WriteBuffer(info.x, info.y, info.shape[0], ¹àÀº»¡°£»ö);
	}
}

void Item2::Release()
{

}
