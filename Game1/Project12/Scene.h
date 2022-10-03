#pragma once
#include "Include.h"
class Scene
{
public:
	bool bosstime;
public:
	virtual void Initialize()PURE;
	virtual void Progress()PURE;
	virtual void Render()PURE;
	virtual void Release()PURE;
};

