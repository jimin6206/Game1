#pragma once
#include "Scene.h"
class Stage : public Scene
{
public:
	int index;
	int time;
public:
	virtual void Initialize();
	virtual void Progress();
	virtual void Render();
	virtual void Release();
};