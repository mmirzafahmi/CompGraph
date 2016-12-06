/*
 * GameSystem.h
 *
 *  Created on: Nov 29, 2016
 *      Author: root
 */

#ifndef GAMESYSTEM_H_
#define GAMESYSTEM_H_
#include "Player.h"
#include <cstring>
#include "Level.h"


using namespace std;

class GameSystem {
public:
	GameSystem(string levelFileName);
	void PlayGame();
	void PlayerMove();
private:
	Player player;
	Level level;

};

#endif /* GAMESYSTEM_H_ */
