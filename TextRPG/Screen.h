
#ifndef SCREEN_H
#define SCREEN_H

#include <iostream>
using namespace std;

class Screen
{
private:
	const static int MAP_WIDTH = 80;
	const static int MAP_HEIGHT = 20;
	static char inGameMap[MAP_HEIGHT][MAP_WIDTH];
	static void basicUpperBar();
	static void basicUndderBar();
public:
	Screen();
	~Screen();
	static int titleScreen();
	static string inputName();
	static int selectRole();

	static void inGameScreen();
	static void battleScreen();
	static void warningMessage(string msg);
};

#endif