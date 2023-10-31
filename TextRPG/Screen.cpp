
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

	cout << "[1] ���ӽ���" << endl;
	cout << "[2] ��������" << endl << endl;
	cout << "============================================================================" << endl;

	int select;
	cin >> select;

	while (select != 1 && select != 2)
	{
		warningMessage("��ȣ�� �ٽ� �Է����ּ���.");
		cin >> select;
	}
	return select;

}
string Screen::inputName()
{
	system("cls");
	string name;
	cout << "============================================================================" << endl;
	cout << "�г����� �Է����ּ��� : ";
	cin >> name;
	cout << "============================================================================" << endl;
	return name;
}

int Screen::selectRole()
{
	system("cls");
	int input;
	cout << "============================================================================" << endl;
	cout << "[1] ����(�⺻ ���ݷ��� ���ϴ�.)" << endl;
	cout << "[2] �ü�(�⺻ ��ø���� �����ϴ�.)" << endl;
	cout << "============================================================================" << endl;
	cout << "������ ������ �ּ��� : ";
	cin >> input;

	while (input != 1 && input != 2)
	{
		warningMessage("��ȣ�� �ٽ� �Է����ּ���.");
		cout << "������ ������ �ּ��� : ";
		cin >> input;
	}

	return input;
}

void Screen::basicUpperBar()
{
	Player* player = Managers::Game->getPlayer();
	cout << "============================================================================" << endl;
	cout << "�г��� : "<< player->getName() << "\t|| ���� : "<< player->getRole().getName()<<endl;
	cout << "============================================================================" << endl;
}

void Screen::basicUndderBar()
{
	Player* player = Managers::Game->getPlayer();
	cout << "============================================================================" << endl;
	cout << "HP : " << player->getHP() << "\t|| ���ݷ� : "<<" \t|| ��ø�� : "<<endl;
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
