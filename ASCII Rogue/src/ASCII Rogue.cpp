//============================================================================
// Name        : ASCII.cpp
// Author      : M Mirza Fahmi
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <ncurses.h>
#include <cstring>
#include <cstdlib>

#include "GameSystem.h"

using namespace std;

int main() {

	GameSystem gs("/home/fahmi/Workspace/ASCII Rogue/src/mapPac.txt");
	gs.PlayGame();


	return 0;
}
