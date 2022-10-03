#pragma once
#include "Scene.h"
class SceneManager
{
private:
	static SceneManager* pInst;
public:
	static SceneManager* GetInst()
	{
		if (pInst == nullptr)
		{
			pInst = new SceneManager;
		}

		return pInst;
	}
private:
	Scene* currentScene;
public:
	void SetScene(SCENE_ID id);
	void Progress();
	void Render();
	void Release();
public:
	SceneManager();
};

