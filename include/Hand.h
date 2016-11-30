#ifndef HAND_H_
#define HAND_H_

#include <iostream>

#include "Card.h"
#include <vector>
using namespace std;

class Hand {
protected:
    vector<Card*> getInHandCards();
private:
    // Declare here the collection of "Card *" of the hand
    vector<Card*> inHand;
public:
    Hand();
    Hand(const Hand &otherHand);
    virtual ~Hand();
    bool addCard(Card &card);
    bool removeCard(Card &card);
    vector<Card*> tryGetCards(string value);
    int getNumberOfCards(); // Get the number of cards in hand
    string toString(); // Return a list of the cards, separated by space, in one line,in a sorted order, ex: "2S 5D 10H"
    void remove4ofAKind(string s);
    int binarySearch(std::vector<Card *> vec, int start, int end, Card &card);
};

#endif
