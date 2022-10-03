#pragma once
#include "Scene.h"
class Logo : public Scene
{
private:
	const char* logo[13];
	const char* start;
public:
	virtual void Initialize();
	virtual void Progress();
	virtual void Render();
	virtual void Release();
};

