#include "ObjectFactory.h"
#include "Enemy.h"
#include "Enemy2.h"
#include "Enemy3.h"
#include "Player.h"
#include "Bullet.h"
#include "Item.h"
#include "Item2.h"
#include "Boss.h"
#include "Bossbullet.h"

ObjectFactory* ObjectFactory::pInst = nullptr;

Obj* ObjectFactory::CreateObj(Object id)
{
	Obj* obj = nullptr;

	switch (id)
	{
	case PLAYER:
		obj = new Player;
		break;
	case ENEMY:
		obj = new Enemy;
		break;
	case ENEMY2:
		obj = new Enemy2;
		break;
	case ENEMY3:
		obj = new Enemy3;
		break;
	case BOSS:
		obj = new Boss;
		break;
	case BOSSBULLET:
		obj = new Bossbullet;
		break;
	case BULLET:
		obj = new Bullet;
		break;
	case ITEM:
		obj = new Item;
		break;
	case ITEM2:
		obj = new Item2;
	default:
		break;
	}

	if (obj != nullptr)
	{
		obj->Initialize();
	}

	return obj;
}
