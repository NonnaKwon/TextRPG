#ifndef ROLE_H
#define ROLE_H
#include <iostream>

using namespace std;
class Role
{
private:
	string roleName;
	float maxHp;
	//´É·ÂÄ¡
	float power;
	float speed;
public:
	Role(string name, float hp, float power, float speed) :roleName(name), maxHp(hp), power(power), speed(speed) {};
	Role() {};
	string getName() { return roleName; }
	float getMaxHP() { return maxHp; }
	float getPower() { return power; }
	float getSpeed() { return speed; }
};

#endif