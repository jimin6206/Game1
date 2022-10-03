#pragma once
#include "Obj.h"

class Boss : public Obj
{
public:
	int hp;
	bool collision;
public:
	virtual void Initialize();
	virtual void Progress();
	virtual void Render();
	virtual void Release();
};

