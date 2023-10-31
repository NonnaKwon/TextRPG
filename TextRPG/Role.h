#ifndef ROLE_H
#define ROLE_H
#include <iostream>

using namespace std;
class Role
{
private:
	int roleID;
	string roleName;
	float maxHp;
	//´É·ÂÄ¡
	float power;
	float speed;
public:
	string getName() { return roleName; }
};

#endif