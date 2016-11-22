//
// Created by amitmarx on 22/11/16.
//

#ifndef REVIIYOT_CARDREQUEST_H
#define REVIIYOT_CARDREQUEST_H


#include "Card.h"

class CardRequest {
private:
    Card reauestedCard;
public:
    int getCard();
};

class InOrderCardRequest : CardRequest {
private:
    int position;
public:
    int getPosition();
};

class TakeFromHeighestCardRequest  : CardRequest{
};

#endif //REVIIYOT_CARDREQUEST_H
