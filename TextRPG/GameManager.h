#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define SUBMIT 4
#define END 5

#define INGAME 10
#define BATTLE 11

#include <iostream>
#include "Player.h"
using namespace std;

class GameManager
{
private:
	Player player;
	int keyControl();
public:
	int GameState;
	void Play();
	void gameLoop();
	void SetPlayer();
	Player* getPlayer() { return &player; }
	void InGame();
};

#endif