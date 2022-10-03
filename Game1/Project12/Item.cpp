#include "Item.h"
#include "DoubleBuffer.h"
#include "ObjectPoolManager.h"
#include "CollisionManager.h"

void Item::Initialize()
{
	info.act = true;
	info.shape[0] = "¡Ú";

	SetInfo(rand() % 36 + 2, 2);
}

void Item::Progress()
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
		SetInfo(rand() % 36 + 2, 2);
	}
}

void Item::Render()
{
	if (info.act && info.y >= 2)
	{
		DoubleBuffer::GetInst()->WriteBuffer(info.x, info.y, info.shape[0], ³ë¶õ»ö);
	}
}

void Item::Release()
{

}
