
#include "Screen.h"
#include "Player.h"
#include "Managers.h"
#include <Windows.h>
#include <string>

int Screen::x = 0;
int Screen::y = 0;

char Screen::inGameMap[MAP_HEIGHT][MAP_WIDTH] = {
	{"000000011111111111111111111111111111111111111111111111111111111111"},
	{"000000010000000000000000100000000000000001000000000000000000000001"},
	{"000000010m0000000000000010000m00000000000100000000000m00000000i001"},
	{"000000010001111111000000100000000100000001000000000000000000000001"},
	{"000000010001000001000000100000000100000001000000011111111100000001"},
	{"00000001000100i001000000100000000100000001000000010000000100000001"},
	{"00000001000100000100000010000000010000000100000001000b000100000001"},
	{"000000010001000001000000100000000100000001000000010000000100000001"},
	{"000000010001000001000000100000000100000001000000010000000100000001"},
	{"000000010001000001000000100000000100000001000000010000000100000001"},
	{"000000010001000001000000100000000100000001000000010000000100000001"},
	{"0000000100010000010000001000000001000i0001000000010000000100000001"},
	{"000000010001000001000000100000000100000001000000010000000100000001"},
	{"000000010001000001000000100000000100000001000000010000000100000001"},
	{"00000001000100m001000000100000000100000001000000010000000100000001"},
	{"00000001000100000100000010000000010000000100000001000i000100000001"},
	{"000000010001000000000000100000000100000001000000010000000100000001"},
	{"000000010p01000000000000000000000100000000000000010000000000000001"},
	{"000000010001000000000000000000000100000000000000010000000000000001"},
	{"000000011111111111111111111111111111111111111111111111111111111111"}
};

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
	cin.ignore();
	getline(cin,name);
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
	cout << "HP : " << player->getHP() << "\t|| ���ݷ� : "<< player->getRole().getPower()<<" \t|| ��ø�� : "<< player->getRole().getSpeed() << endl;
	cout << "============================================================================" << endl;
	cout << "�̵� : A W S D // ��ȣ�ۿ� : M // ���� : Q" << endl;
}

void Screen::inGameScreen(int state)
{
	system("cls");
	basicUpperBar();
	switch (state)
	{
	case LEFT:
		moveMap(0, -1);
		break;
	case RIGHT:
		moveMap(0, 1);
		break;
	case UP:
		moveMap(-1, 0);
		break;
	case DOWN:
		moveMap(1, 0);
		break;
	case SUBMIT:
		break;
	default:
		break;
	}
	drawMap();
	basicUndderBar();
}


void Screen::moveMap(int moveX, int moveY)
{
	if (x + moveX < 0 || MAP_HEIGHT <= x + moveX || y + moveY < 7 || MAP_WIDTH <= y + moveY)
		return;
	else if (inGameMap[x + moveX][y + moveY] != '0')
		return;

	inGameMap[x][y] = '0';
	inGameMap[x + moveX][y + moveY] = 'p';
}

void Screen::drawMap()
{
	for (int i = 0; i < MAP_HEIGHT; i++)
	{
		for (int j = 0; j < MAP_WIDTH; j++)
		{
			char tile = inGameMap[i][j];
			if (tile == '0')
				cout << " ";
			else if (tile == '1')
				cout << "#";
			else if (tile == 'p')//�÷��̾�
			{
				cout << "@";
				x = i;
				y = j;
			}
			else if (tile == 'm')//����
				cout << "&";
			else if (tile == 'i')//������
				cout << "^";
			else if (tile == 'b')
				cout << "*";
			else if (tile == '\0')
			{
				cout << "";
			}
			else
				cout << "err";
		}
		cout << endl;
	}
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
