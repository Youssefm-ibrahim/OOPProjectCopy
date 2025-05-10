#pragma once
#include "CMUgraphicsLib\CMUgraphics.h"
#include "CMUgraphicsLib\auxil.h"	
#include "Toolbar.h"
#include "Player.h"
#include "Background.h"
#include "Enemy.h"
#include "Fuel.h"
#include "GameConfig.h"
#include "StatusBar.h"
#include <iostream>
#include <sstream>
#include <vector>


class Game
{
private:
	window* pWind;	//Pointer to the CMU graphics window
	point p = { -1, -1 };
	ToolBar T1;
	Background BG;
	EnemyManager En;
	Fuel F1;
	Player player;
	vector<GameObject*> objects;
public:
	Game();
	~Game();

	clicktype getMouseClick(int& x, int& y) const; //Get coordinate where user clicks and returns click type (left/right)
	string getSrting() const;	 //Returns a string entered by the user


	window* CreateWind(int, int, int, int) const; //creates the game window
	//void createToolbar();
	void clearStatusBar() const;	//Clears the status bar


	void printMessage(string msg) const;	//Print a message on Status bar

	void go();

	window* getWind() const;		//returns a pointer to the graphics window
	EnemyManager getEnemyManager() const { return En; }
	Fuel getFuel() const { return F1; }
	Player getPlayer() const { return player; }
	Background getBackground() const { return BG; }

	void DrawGame();
	void MoveForward(int speed);
};

