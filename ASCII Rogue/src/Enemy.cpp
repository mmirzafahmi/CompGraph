/*
 * Enemy.cpp
 *
 *  Created on: Dec 5, 2016
 *      Author: root
 */

#include "Enemy.h"
#include <random>
#include <ctime>

Enemy::Enemy(string name, char tile, int level, int health, int attack, int defense, int expValue) {
	this->name = name;
	this->tile = tile;
	this->level = level;
	this->health = health;
	this->attack = attack;
	this->defense = defense;
	this->expValue = expValue;
	x = 0;
	y = 0;
}

void Enemy::setPosition(int x, int y){
	this->x = x;
	this->y = y;
}

void Enemy::getPosition(int &x, int &y){
	x = this->x;
	y = this->y;

}

int Enemy::attackMove(){
	static default_random_engine randomEngine(time(NULL));
	uniform_int_distribution<int> attackRoll(0, attack);
	return attackRoll(randomEngine);
}

int Enemy::takeDamage(int attack){
	attack -= defense;
	if(attack > 0){
		health -= attack;
		if(health <= 0){
			return expValue;
		}
	}

	return 0;
}
