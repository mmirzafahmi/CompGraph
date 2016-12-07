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

void Player::init(int level, int health, int attack, int defense, int experience){
	this->level = level;
	this->health = health;
	this->attack = attack;
	this->defense = defense;
	this->experience = experience;
}

void Player::setPosition(int x, int y){
	this->x = x;
	this->y = y;
}

void Player::getPosition(int &x, int &y){
	x = this->x;
	y = this->y;

}

int Player::attackMove(){
	static default_random_engine randomEngine(time(NULL));
	uniform_int_distribution<int> attackRoll(0, attack);
	return attackRoll(randomEngine);
}

void Player::addExp(int experience){
	experience += experience;

	while(experience > 50){
		printf("Leveled up!\n");
		experience -= 50;
		attack += 10;
		defense += 5;
		health += 10;
		level++;
	}
}

int Player::takeDamage(int attack){
	attack -= defense;
	if(attack > 0){
		health -= attack;
		if(health <= 0){
			return 1;
		}
	}

	return 0;
}

