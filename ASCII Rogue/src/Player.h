/*
 * Player.h
 *
 *  Created on: Nov 29, 2016
 *      Author: root
 */

#ifndef PLAYER_H_
#define PLAYER_H_



class Player {
public:
	Player();
	void init(int levelInit, int healthInit, int attackInit, int defenseInit, int experienceInit);

	int attackMove();

	void setPosition(int x, int y);

	void addExp(int addExp);

	int takeDamage(int atk);

	void getPosition(int &x, int &y);

private:
	int level;
	int health;
	int attack;
	int defense;
	int experience;
	int x;
	int y;

};

#endif /* PLAYER_H_ */
