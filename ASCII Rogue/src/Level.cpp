/*
 * Level.cpp
 *
 *  Created on: Nov 29, 2016
 *      Author: root
 */

#include "Level.h"

#include <fstream>
#include <iostream>
#include <cstdio>

Level::Level() {

}

void Level::load(string FileName, Player &player) {
	ifstream file;

	file.open(FileName.c_str());
	if (file.fail()) {
		perror(FileName.c_str());
		return;
	}

	string line;
	while (getline(file, line)) {
		levelData.push_back(line);
	}

	file.close();

	char tile;
	for (unsigned int i = 0; i < levelData.size(); i++) {
		for (unsigned int j = 0; j < levelData[i].size(); j++) {
			tile = levelData[i][j];

			switch (tile) {
			case '@':
				player.setPosition(j, i);
				break;
			case 'S':
				enemies.push_back(Enemy("Snake", tile, 1, 3, 1, 10, 50));
				enemies.back().setPosition(j, i);
				break;
			case 'g':
				enemies.push_back(Enemy("Goblin", tile, 2, 10, 5, 35, 100));
				enemies.back().setPosition(j, i);
				break;
			case 'O':
				enemies.push_back(Enemy("Ogre", tile, 4, 20, 20, 200, 500));
				enemies.back().setPosition(j, i);
				break;
			case 'D':
				enemies.push_back(
						Enemy("Dragon", tile, 100, 2000, 2000, 2000, 50000000));
				enemies.back().setPosition(j, i);
				break;
			case 'B':
				enemies.push_back(Enemy("Bandit", tile, 3, 15, 10, 100, 250));
				enemies.back().setPosition(j, i);
				break;
			}
		}
	}
}

void Level::print() {

	cout << string(10, '\n');

	for (unsigned int i = 0; i < levelData.size(); i++) {
		printf("%s\n", levelData[i].c_str());
	}
	printf("\n");
}

void Level::movePlayer(char input, Player &player) {
	int playerX;
	int playerY;
	player.getPosition(playerX, playerY);

	switch (input) {
	case 'w':
	case 'W':
		processMovePlayer(player, playerX, playerY - 1);
		break;
	case 's':
	case 'S':
		processMovePlayer(player, playerX, playerY + 1);
		break;
	case 'a':
	case 'A':
		processMovePlayer(player, playerX - 1, playerY);
		break;
	case 'd':
	case 'D':
		processMovePlayer(player, playerX + 1, playerY);
		break;
	default:
		printf("INVALID INPUT!\n");
		break;
	}
}

char Level::getTile(int x, int y) {
	return levelData[y][x];
}

void Level::processMovePlayer(Player &player, int x, int y) {
	int playerX;
	int playerY;
	player.getPosition(playerX, playerY);

	char moveTile = getTile(x, y);
	switch (moveTile) {
	case '#':
		break;
	case '.':
		player.setPosition(x, y);
		setTile(playerX, playerY, '.');
		setTile(x, y, '@');
		break;
	default:
		battleMonster(player, x, y);
	}
}

void Level::processMoveEnemy(Player &player, int enemyIndex, int targetX, int targetY) {
	int playerX;
	int playerY;
	int enemyX;
	int enemyY;

	enemies[enemyIndex].getPosition(enemyX, enemyY);
	player.getPosition(playerX, playerY);

	char moveTile = getTile(targetX, targetY);
	switch (moveTile) {
	case '@':
		battleMonster(player, enemyX, enemyY);
		break;
	case '.':
		enemies[enemyIndex].setPosition(targetX, targetY);
		setTile(enemyX, enemyY, '.');
		setTile(targetX, targetY, enemies[enemyIndex].getTile());
		break;
	default:
		break;
	}
}

void Level::setTile(int x, int y, char tile) {
	levelData[y][x] = tile;
}

void Level::battleMonster(Player &player, int targetX, int targetY) {
	int enemyX;
	int enemyY;
	int playerX;
	int playerY;
	int attackRoll;
	int attackResult;
	string enemyName;

	player.getPosition(playerX, playerY);

	for (unsigned int i = 0; i < enemies.size(); i++) {
		enemies[i].getPosition(enemyX, enemyY);
		enemyName = enemies[i].getName();
		if (targetX == enemyX && targetY == enemyY) {
			attackRoll = player.attackMove();
			printf("Player attack %s with a roll of %d\n", enemyName.c_str(),
					attackRoll);
			attackResult = enemies[i].takeDamage(attackRoll);
			if (attackResult != 0) {
				setTile(targetX, targetY, '.');
				print();
				printf("%s Died!\n", enemyName.c_str());

				enemies[i] = enemies.back();
				enemies.pop_back();
				i--;

				player.addExp(attackResult);

				return;
			}
			attackRoll = enemies[i].attackMove();
			printf("%s attacked player with a roll of %d\n", enemyName.c_str(),
					attackRoll);
			attackResult = player.takeDamage(attackRoll);
			if (attackResult != 0) {
				setTile(playerX, playerY, 'x');
				print();
				printf("You Died!\n");
				exit(0);
			}

			return;
		}
	}
}

void Level::updateEnemy(Player &player) {
	char aiMove;
	int playerX;
	int playerY;
	int enemyX;
	int enemyY;

	player.getPosition(playerX, playerY);

	for (unsigned int i = 0; i < enemies.size(); i++) {
		aiMove = enemies[i].getMove(playerX, playerY);
		enemies[i].getPosition(enemyX, enemyY);
		switch (aiMove) {
		case 'w':
			processMoveEnemy(player, i,enemyX, enemyY - 1);
			break;
		case 's':
			processMoveEnemy(player, i,enemyX, enemyY + 1);
			break;
		case 'a':
			processMoveEnemy(player, i,enemyX - 1, enemyY);
			break;
		case 'd':
			processMoveEnemy(player, i ,enemyX + 1, enemyY);
			break;
		}
	}
}

