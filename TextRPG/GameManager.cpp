
#include "GameManager.h"
#include "Screen.h"

void GameManager::Play()
{
	switch (Screen::titleScreen())
	{
	case 1:
		SetPlayer();
		break;
	case 2:
		return;
	default:
		break;
	}
}

void GameManager::SetPlayer()
{
	player.setName(Screen::inputName());
	player.setRole(Screen::selectRole());
	InGame();
}

void GameManager::InGame()
{
	Screen::inGameScreen();
}