#pragma once
#include "Obj.h"
class Player : public Obj
{
public :
	int itemcount;   //별아이템 지속시간
	int heartcount;  //하트아이템 수
	bool enemy_collision;   //적과의 충돌
	bool heart_collision;    //하트아이템과의 충돌
	
public:
	virtual void Initialize();
	virtual void Progress();
	virtual void Render();
	virtual void Release();
};

