#ifndef PLAYER_H_
#define PLAYER_H_

#include <iostream>
#include "Hand.h"
#include "CardRequest.h"

using namespace std;

class Player : public Hand {
private:
	const string name;

protected:
	int playerToAsk;
	int location;

public:
	Player(string n, int loc);
	Player(const Player& p);
	string getName();   //Returns the name of the player
	virtual CardRequest* playTurn()=0;
	virtual Player* clone()=0;
	void increaseLocationToAskByOne();
};

class PlayerType1 : public Player {

public://For strategy 1
	PlayerType1(string n, int loc) : Player(n,loc){ };
	PlayerType1(PlayerType1& p):Player(p){};
    virtual CardRequest* playTurn();
	Player* clone();
};

class PlayerType2 : public Player {  //For strategy 2

public:
	PlayerType2(string n, int loc) : Player(n,loc){ };
	PlayerType2(PlayerType2& p):Player(p){};
	virtual CardRequest* playTurn();
	Player* clone();
};

class PlayerType3 : public Player {
public://For strategy 3
	PlayerType3(string n, int loc) : Player(n,loc){ };
	PlayerType3(PlayerType3& p):Player(p){};
	virtual CardRequest* playTurn();
	Player* clone();
};

class PlayerType4 : public Player {  //For strategy 4
public:
	PlayerType4(string n, int loc) : Player(n,loc){ };
	PlayerType4(PlayerType4& p):Player(p){};
	virtual CardRequest* playTurn();
	Player* clone();
};

#endif
