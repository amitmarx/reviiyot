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
	string getName();   //Returns the name of the player
	virtual CardRequest* playTurn()=0;
	void increaseLocationToAskByOne();
};

class PlayerType1 : public Player {

public://For strategy 1
	PlayerType1(string n, int loc) : Player(n,loc){ };
    virtual CardRequest* playTurn();

};

class PlayerType2 : public Player {  //For strategy 2

public:
	PlayerType2(string n, int loc) : Player(n,loc){ };
    virtual CardRequest* playTurn();
};

class PlayerType3 : public Player {
private:

public://For strategy 3
	PlayerType3(string n, int loc) : Player(n,loc){ };
    virtual CardRequest* playTurn();//returns the id of the last player from whom this player asked for a card
};

class PlayerType4 : public Player {  //For strategy 4
private:
public :
	PlayerType4(string n, int loc) : Player(n,loc){ };
    virtual CardRequest* playTurn();
};

#endif
