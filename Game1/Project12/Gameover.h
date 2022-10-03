#pragma once
#include "Scene.h"
class Gameover : public Scene
{
private:
	const char* gameover[8];
public:
	virtual void Initialize();
	virtual void Progress();
	virtual void Render();
	virtual void Release();
};

