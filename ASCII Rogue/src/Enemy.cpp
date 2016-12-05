/*
 * Enemy.cpp
 *
 *  Created on: Dec 5, 2016
 *      Author: root
 */

#include "Enemy.h"

Enemy::Enemy(string name, char tile, int level, int health, int attack, int defense, int expValue) {
	this->name = name;
	this->tile = tile;
	this->level = level;
	this->health = health;
	this->attack = attack;
	this->defense = defense;
	this->expValue = expValue;
}

