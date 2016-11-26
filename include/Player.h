#ifndef PLAYER_H_
#define PLAYER_H_

#include <iostream>
#include "Hand.h"
#include "CardRequest.h"

using namespace std;

class Player : public Hand {
private:
	const string name;
	const int position;
public:

	Player(const string &name, const int position) : name(name), position(position) { }

	string getName();   //Returns the name of the player
	virtual CardRequest* playTurn()=0;
	virtual ~Player(){}
};

class PlayerType1 : public Player {  //For strategy 1

public:
	PlayerType1(const string &name, const int position) : Player(name, position) { }
	CardRequest* playTurn(){
		return nullptr;
	}
};

class PlayerType2 : public Player {  //For strategy 2

public:
	PlayerType2(const string &name, const int position) : Player(name, position) { }
	CardRequest* playTurn(){
		return nullptr;
	}
};

class PlayerType3 : public Player {  //For strategy 3

public:
	PlayerType3(const string &name, const int position) : Player(name, position) { }
	CardRequest* playTurn(){
		return nullptr;
	}
};

class PlayerType4 : public Player {  //For strategy 4

public:
	PlayerType4(const string &name, const int position) : Player(name, position) { }
	CardRequest* playTurn(){
		return nullptr;
	}
};

#endif
