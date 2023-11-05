
#include "GameManager.h"
#include "Screen.h"
#include <conio.h>

void GameManager::gameLoop()
{
	//¸Ê Ãâ·Â
	bool isEnd = false;
	while (!isEnd)
	{
		int key = keyControl();
		switch (key)
		{
			case LEFT :
				break;
			case RIGHT:
				break;
			case UP:
				break;
			case DOWN:
				break;
			case END:
				isEnd = true;
				break;
			case SUBMIT:
				break;
		default:
			break;
		}

	}
}


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
	gameLoop();
}


int GameManager::keyControl()
{
	char input = getch();
	switch (input)
	{
	case 'a' : case 'A':
		return LEFT;
	case 's' : case 'S':
		return DOWN;
	case 'w' : case 'W':
		return UP;
	case 'd' : case 'D':
		return RIGHT;
	case 'q' : case 'Q':
		return END;
	case 'x': case 'X':
		return SUBMIT;
	default:
		break;
	}
	return -1;
}