#pragma once
#include "Scene.h"
class BossStage : public Scene
{

public:
	virtual void Initialize();
	virtual void Progress();
	virtual void Render();
	virtual void Release();
};

