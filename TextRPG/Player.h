#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include "Role.h"
using namespace std;

class Player
{
private:
	string name;
	Role role;
	float hp;
public:
	void setName(string name) { this->name = name; }
	string getName() { return name; }
	void setRole(int role);
	Role getRole() { return role; }
	void decreaseHP(float damage) { hp -= damage; }
	float getHP() { return hp; }
};

#endif