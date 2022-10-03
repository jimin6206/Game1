#pragma once
#include "Scene.h"

class Menu : public Scene
{
private:
	MenuIcon arrow;
	MenuIcon menu[3];

private:
	MENU_ID id;
	int index;
public:
	virtual void Initialize();
	virtual void Progress();
	virtual void Render();
	virtual void Release();
};