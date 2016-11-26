//
// Created by amitmarx on 22/11/16.
//

#ifndef REVIIYOT_CARDREQUEST_H
#define REVIIYOT_CARDREQUEST_H


#include "Card.h"

class CardRequest {
private:
    Card* requestedCard;
public:
    Card* getCard(){
        return requestedCard;
    };
    virtual ~CardRequest();
};

class InOrderCardRequest : public CardRequest {
private:
    int position;
public:
    int getPosition();
};

class TakeFromHeighestCardRequest  : public CardRequest{
};

#endif //REVIIYOT_CARDREQUEST_H
