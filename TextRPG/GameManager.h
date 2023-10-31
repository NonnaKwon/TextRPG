#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

#include <iostream>
#include "Player.h"
using namespace std;

class GameManager
{
private:
	Player player;
public:
	void Play();
	void SetPlayer();
	Player* getPlayer() { return &player; }
	void InGame();
};

#endif