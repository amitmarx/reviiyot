#ifndef DECK_H_
#define DECK_H_

#include <iostream>
#include <stack>

#include "Card.h"

using namespace std;

class Deck {
private:
	stack<Card*> cards;

	Card *createCard(string cardStr) const;
	Shape findShape(char &s) const;
	Figure findFigure(char &s) const;

public:
	void initDeck(string deck);
	Card* fetchCard();   //Returns the top card of the deck and remove it from the deck
	int getNumberOfCards(); // Get the number of cards in the deck
	string toString(); // Return the cards in top-to-bottom order in a single line, cards are separated by a space ex: "12S QD AS 3H"
	~Deck();
};

#endif
