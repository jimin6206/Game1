#pragma once
#include "Define.h"

enum BulletType
{
	A,
	B,
	C,
};

enum Object
{
	PLAYER,
	ENEMY,
	ENEMY2,
	ENEMY3,
	BOSS,
	BOSSBULLET,
	BULLET,
	ITEM,
	ITEM2,
};


enum Color
{
	검정색,
	파란색,
	초록색,
	옥색,
	빨간색,
	자주색,
	노란색,
	흰색,
	회색,
	밝은파란색,
	밝은초록색,
	밝은옥색,
	밝은빨간색,
	밝은자주색,
	밝은노란색,

};

enum SCENE_ID
{
	LOGO,
	MENU,
	STAGE,
	BOSSSTAGE,
	GAMEOVER,
};

enum MENU_ID
{
	START,
	OPTION,
	EXIT,
};

enum DIR
{
	LEFT,
	RIGHT,
	TOP,
	BOTTOM,
};