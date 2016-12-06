/*
 * Level.h
 *
 *  Created on: Nov 29, 2016
 *      Author: root
 */

#ifndef LEVEL_H_
#define LEVEL_H_
#include <vector>
#include <cstring>
#include <iostream>
#include "Enemy.h"
#include "Player.h"

using namespace std;

class Level {

public:
	Level();
	void load(string FileName, Player &player);
	void print();
	void movePlayer(char input, Player &player);
	char getTile(int x, int y);
	void setTile(int x, int y, char tile);

private:

	void processMovePlayer(Player &player, int x, int y);
	void battleMonster(Player &player, int targetX, int targetY);

private:
	vector <string> levelData;
	vector<Enemy> enemies;
};

#endif /* LEVEL_H_ */
