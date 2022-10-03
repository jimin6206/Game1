#include "SceneManager.h"
#include "Logo.h"
#include "Menu.h"
#include "Stage.h"
#include "BossStage.h"
#include "Gameover.h"

SceneManager* SceneManager::pInst = nullptr;

void SceneManager::SetScene(SCENE_ID id)
{
	if (currentScene != nullptr)
	{
		delete currentScene;
		currentScene = nullptr;
	}

	switch (id)
	{
	case LOGO:
		currentScene = new Logo;
		break;
	case MENU:
		currentScene = new Menu;
		break;
	case STAGE:
		currentScene = new Stage;
		break;
	case BOSSSTAGE:
		currentScene = new BossStage;
		break;
	case GAMEOVER:
		currentScene = new Gameover;
		break;
	default:
		break;
	}

	currentScene->Initialize();
}

void SceneManager::Progress()
{
	currentScene->Progress();
}

void SceneManager::Render()
{
	currentScene->Render();
}

void SceneManager::Release()
{
	currentScene->Release();
}

SceneManager::SceneManager()
{
	currentScene = nullptr;
}
