
#ifndef SCREEN_H
#define SCREEN_H

#include <iostream>
using namespace std;

class Screen
{
private:
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
	//void setGamaManager(GameManager *inputManager) { gm = inputManager; }
};

#endif