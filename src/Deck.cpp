//
// Created by Amit Marx on 19/11/2016.
//

#include "../include/Deck.h"

Card* Deck::fetchCard() {
    Card * returnVal = nullptr;
    if(!cards.empty()){
        returnVal = cards.top();
        cards.pop();
    }
    return returnVal;
}
