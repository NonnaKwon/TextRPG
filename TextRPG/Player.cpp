
#include "Player.h"


void Player::setRole(int role)
{
	switch (role)
	{
	case 1:
	{
		Role tmp("Àü»ç", 150, 200, 1);
		this->role = tmp;
		break;
	}
	case 2:
	{
		Role tmp("±Ã¼ö", 100, 100, 3);
		this->role = tmp;
		break;
	}
	default:
		break;
	}

	this->hp = this->role.getMaxHP();
}
