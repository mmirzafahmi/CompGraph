/*
 * Player.cpp
 *
 *  Created on: Nov 29, 2016
 *      Author: root
 */

#include "Player.h"

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

