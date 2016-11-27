#ifndef GAME_H_
#define GAME_H_

#include <iostream>
#include <vector>

#include "Player.h"
#include "Deck.h"

using namespace std;

class Game {
private:
	vector<Player *> players;  //The list of the players
	Deck deck;                 //The deck of the game
	bool isVerbal;
	int highest;
	string initState;
	int turns=0;

	bool isThereAWinner();
	void setVerbal(string basic_string);
	void setHighest(string basic_string);
	void setDeck(string basic_string);
	void setPlayer(string basic_string,int position);
	Player *findPlayerToAsk(CardRequest *request);
	Player *findPlayerToAsk(CardRequest *request, int playerPosition);
	string stateString();

public:
	Game(char* configurationFile); //Read all configuration and creates objects
	Game (const Game &obj); //copy ctor

	void init(); // Deal cards to players
	void play();
	void printState();        //Print the state of the game as described in the assignment.
	void printWinner();       //Print the winner of the game as describe in the assignment.
	void printNumberOfTurns(); //Print the number of played turns at any given time.
	~Game();

	void printEndState();
};

#endif
