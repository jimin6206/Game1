#pragma once
#include "Obj.h"

class Item2 : public Obj
{
public:
	virtual void Initialize();
	virtual void Progress();
	virtual void Render();
	virtual void Release();

};

