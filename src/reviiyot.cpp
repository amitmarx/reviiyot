#include "../include/Game.h"
#include <iostream>

using namespace std;

int main(int argc, char **argv) {

	//char* configurationFile = argv[1];

    char* configurationFile = "/home/amitmarx/dev/reviiyot/config/testeasy";

	Game game = Game(configurationFile);
	game.init();
 	Game initializedGame = game;
 	game.play();

	cout << std::endl;
 	game.printWinner();
	game.printNumberOfTurns();
	cout << "----------" << endl;
	cout<<"Initial State:"<<endl;
  	initializedGame.printState();
	cout<<"----------"<<endl;
	cout<<"Final State:"<<endl;
	game.printState();
	return 0;
}

