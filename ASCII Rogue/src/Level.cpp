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
	for (int i = 0; i < levelData.size(); i++) {
		for (int j = 0; j < levelData[i].size(); j++) {
			tile = levelData[i][j];

			switch (tile) {
			case '@':
				player.setPosition(j, i);
				break;
			case 'S':
				enemies.push_back(Enemy("snake", tile, 1, 3, 1, 10, 10));
				break;
			case 'g':
				enemies.push_back(Enemy("goblin", tile, 2, 10, 5, 35, 50));
				break;
			case 'O':
				enemies.push_back(Enemy("ogre", tile, 4, 20, 20, 200, 500));
				break;
			case 'D':
				enemies.push_back(Enemy("dragon", tile, 100, 2000, 2000, 2000, 50000000));
				break;
			case 'B':
				enemies.push_back(Enemy("Bandit", tile, 3, 15, 10, 100, 250));
				break;
			}
		}
	}
}

void Level::print() {

	cout << string(100, '\n');

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

void Level::setTile(int x, int y, char tile) {
	levelData[y][x] = tile;
}

void Level::battleMonster(Player &player, int targetX, int targetY){
	int enemyX;
	int enemyY;

	for(int i = 0; i < enemies.size(); i++){
		enemies[i].getPosition(enemyX, enemyY);
		if(targetX == enemyX && targetY == enemyY){


			return;
		}
	}
}

