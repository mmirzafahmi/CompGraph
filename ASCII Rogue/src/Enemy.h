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
	Enemy(string name, char tile, int level, int health, int attack, int defense, int expValue);

	void setPosition(int x, int y);

	void getPosition(int &x, int &y);

	int attackMove();

	string getName(){ return name;}

	int takeDamage(int attack);

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
