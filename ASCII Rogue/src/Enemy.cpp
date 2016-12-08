/*
 * Enemy.cpp
 *
 *  Created on: Dec 5, 2016
 *      Author: root
 */

#include "Enemy.h"
#include <random>
#include <ctime>

Enemy::Enemy(string nameInit, char tileInit, int levelInit, int healthInit, int attackInit,
		int defenseInit, int expValueInit) {
	name = nameInit;
	tile = tileInit;
	level = levelInit;
	health = healthInit;
	attack = attackInit;
	defense = defenseInit;
	expValue = expValueInit;
	x = 0;
	y = 0;
}

void Enemy::setPosition(int xpos, int ypos) {
	x = xpos;
	y = ypos;
}

void Enemy::getPosition(int &xpos, int &ypos) {
	xpos = x;
	ypos = y;

}

int Enemy::attackMove() {
	static default_random_engine randomEngine(time(NULL));
	uniform_int_distribution<int> attackRoll(0, attack);
	return attackRoll(randomEngine);
}

int Enemy::takeDamage(int atk) {
	atk -= defense;
	if (atk > 0) {
		health -= atk;
		if (health <= 0) {
			return expValue;
		}
	}

	return 0;
}

char Enemy::getMove(int playerX, int playerY) {
	static default_random_engine randEngine(time(NULL));
	uniform_int_distribution<int> moveRoll(0, 6);

	int dist;
	int dx = x - playerX;
	int dy = y - playerY;
	int adx = abs(dx);
	int ady = abs(dy);

	dist = adx + ady;

	if (dist <= 5) {
		if (adx > ady) {
			if (dx > 0) {
				return 'a';
			} else {
				return 'd';
			}
		} else {
			if (dy > 0) {
				return 'w';
			} else {
				return 's';
			}
		}
	}

	int randMove = moveRoll(randEngine);
	switch(randMove){
	case 0:
		return 'a';
	case 1:
		return 'w';
	case 2:
		return 's';
	case 3:
		return 'd';
	default:
		return '.';
	}
}
