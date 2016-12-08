/*
 * Player.cpp
 *
 *  Created on: Nov 29, 2016
 *      Author: root
 */

#include "Player.h"
#include <random>
#include <ctime>

using namespace std;

Player::Player(){
	level = 0;
	health = 0;
	attack = 0;
	defense = 0;
	experience = 0;
	x = 0;
	y = 0;
}

void Player::init(int levelInit, int healthInit, int attackInit, int defenseInit, int experienceInit){
	level = levelInit;
	health = healthInit;
	attack = attackInit;
	defense = defenseInit;
	experience = experienceInit;
}

void Player::setPosition(int xpos, int ypos){
	x = xpos;
	y = ypos;
}

void Player::getPosition(int &xpos, int &ypos){
	xpos = x;
	ypos = y;

}

int Player::attackMove(){
	static default_random_engine randomEngine(time(NULL));
	uniform_int_distribution<int> attackRoll(0, attack);
	return attackRoll(randomEngine);
}

void Player::addExp(int addExp){
	experience += addExp;

	while(experience > 50){
		printf("Leveled up!\n");
		experience -= 50;
		attack += 10;
		defense += 5;
		health += 10;
		level++;
	}
}

int Player::takeDamage(int atk){
	atk -= defense;
	if(atk > 0){
		health -= atk;
		if(health <= 0){
			return 1;
		}
	}

	return 0;
}

