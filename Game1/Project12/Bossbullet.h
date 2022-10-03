#pragma once
#include "Obj.h"

class Bossbullet : public Obj
{
public:
	virtual void Initialize();
	virtual void Progress();
	virtual void Render();
	virtual void Release();
};

