#ifndef PLAYER_H_
#define PLAYER_H_

#include <iostream>
#include "Hand.h"
#include "CardRequest.h"

using namespace std;

class Player : public Hand {
private:
	std::string name; //did amit do it or did they and can i change it??
	int location;
public:
	Player::Player(std::string * n, int loc);
	string getName();   //Returns the name of the player
};

class PlayerType1 : public Player {  //For strategy 1
    virtual TakeFromHeighestCardRequest playTurn();
};

class PlayerType2 : public Player {  //For strategy 2
    virtual TakeFromHeighestCardRequest playTurn();
};

class PlayerType3 : public Player {  //For strategy 3
    virtual InOrderCardRequest playTurn();
    int lastRequest(); //returns the id of the last player from whom this player asked for a card
};

class PlayerType4 : public Player {  //For strategy 4
    virtual InOrderCardRequest playTurn();
    int lastRequest(); //returns the id of the last player from whom this player asked for a card
};

#endif
