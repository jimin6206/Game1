#include "Game.h"
#include "SceneManager.h"
#include "KeyManager.h"


void Game::Initialize()
{
	SceneManager::GetInst()->SetScene(LOGO);
	DoubleBuffer::GetInst()->InitBuffer();

}

void Game::Progress()
{
	KeyManager::GetInst()->CheckKey();

	SceneManager::GetInst()->Progress();
}

void Game::Render()
{

	SceneManager::GetInst()->Render();

	DoubleBuffer::GetInst()->FlipBuffer();
	DoubleBuffer::GetInst()->ClearBuffer();
}

void Game::Release()
{

	SceneManager::GetInst()->Release();
	DoubleBuffer::GetInst()->DestroyBuffer();
}
