
#include "Screen.h"
#include "Player.h"
#include "Managers.h"
#include <Windows.h>

int Screen::titleScreen()
{
	system("cls");
	cout << "============================================================================" << endl;
	cout << "____              ____             ____    ____     ____" << endl;
	cout << "/ ___ | ___ / ___ | ___ | _ \ | _ \ / ___|" << endl;
	cout << "| |  _ / _ \    | |  _ / _ \    | |_) | | |_) | | |  _" << endl;
	cout << "| |_| | | (_) |   | |_| | | (_) |   |  _ < | __/  | |_| |" << endl;
	cout << "\____ | \___ / \____ | \___/    |_ | \_\ | _ | \____ |" << endl;
	cout << "============================================================================" << endl<<endl;

	cout << "[1] 게임시작" << endl;
	cout << "[2] 게임종료" << endl << endl;
	cout << "============================================================================" << endl;

	int select;
	cin >> select;

	while (select != 1 && select != 2)
	{
		warningMessage("번호를 다시 입력해주세요.");
		cin >> select;
	}
	return select;

}
string Screen::inputName()
{
	system("cls");
	string name;
	cout << "============================================================================" << endl;
	cout << "닉네임을 입력해주세요 : ";
	cin >> name;
	cout << "============================================================================" << endl;
	return name;
}

int Screen::selectRole()
{
	system("cls");
	int input;
	cout << "============================================================================" << endl;
	cout << "[1] 전사(기본 공격력이 셉니다.)" << endl;
	cout << "[2] 궁수(기본 민첩력이 빠릅니다.)" << endl;
	cout << "============================================================================" << endl;
	cout << "직업을 선택해 주세요 : ";
	cin >> input;

	while (input != 1 && input != 2)
	{
		warningMessage("번호를 다시 입력해주세요.");
		cout << "직업을 선택해 주세요 : ";
		cin >> input;
	}

	return input;
}

void Screen::basicUpperBar()
{
	Player* player = Managers::Game->getPlayer();
	cout << "============================================================================" << endl;
	cout << "닉네임 : "<< player->getName() << "\t|| 직업 : "<< player->getRole().getName()<<endl;
	cout << "============================================================================" << endl;
}

void Screen::basicUndderBar()
{
	Player* player = Managers::Game->getPlayer();
	cout << "============================================================================" << endl;
	cout << "HP : " << player->getHP() << "\t|| 공격력 : "<<" \t|| 민첩성 : "<<endl;
	cout << "============================================================================" << endl;
}

void Screen::inGameScreen()
{
	system("cls");
	basicUpperBar();

	basicUndderBar();
}
void Screen::battleScreen()
{
	system("cls");
	basicUpperBar();

	basicUndderBar();
}

void Screen::warningMessage(string msg)
{
	cout <<"[warning] " << msg << endl;
}
