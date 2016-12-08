/*
 * Enemy.h
 *
 *  Created on: Dec 5, 2016
 *      Author: root
 */

#ifndef ENEMY_H_
#define ENEMY_H_
#include <iostream>

using namespace std;

class Enemy {
public:
	Enemy(string nameInit, char tileInit, int levelInit, int healthInit, int attackInit,
			int defenseInit, int expValueInit);

	void setPosition(int xpos, int ypos);

	void getPosition(int &xpos, int &ypos);

	char getTile(){return tile;}

	int attackMove();

	string getName(){ return name;}

	int takeDamage(int atk);

	char getMove(int playerX, int playerY);

private:
	string name;
	char tile;
	int level;
	int health;
	int attack;
	int defense;
	int expValue;
	int x;
	int y;

};

#endif /* ENEMY_H_ */
