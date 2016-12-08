/*
* GameSystem.cpp
 *
 *  Created on: Nov 29, 2016
 *      Author: root
 */

#include "GameSystem.h"
#include <cstdio>


GameSystem::GameSystem(string levelFileName){
	player.init(1, 100, 20, 10, 0);
	level.load(levelFileName, player);
	level.print();
}

void GameSystem::PlayGame(){

	bool isDone = false;
	while(isDone != true){
		level.print();
		PlayerMove();
		level.updateEnemy(player);

	}

}

void GameSystem::PlayerMove(){
	char input;
	cout << "Enter a move command (w/a/s/d): ";
	input = getchar();
	level.movePlayer(input, player);
}
