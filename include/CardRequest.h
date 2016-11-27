//
// Created by amitmarx on 22/11/16.
//

#ifndef REVIIYOT_CARDREQUEST_H
#define REVIIYOT_CARDREQUEST_H


#include "Card.h"

class CardRequest {
private:
    string requestedValue;
public:
    CardRequest(string reqValue);
    string getValue();
    virtual ~CardRequest(){ };
};

class InOrderCardRequest : public CardRequest {
private:
    int position;
public:
    InOrderCardRequest(string reqValue, int pos);
    int getPosition();
    virtual ~InOrderCardRequest(){ };
};

class TakeFromHighestCardRequest  : public CardRequest{
public:
    TakeFromHighestCardRequest(string reqValue ): CardRequest(reqValue) { };
    virtual ~TakeFromHighestCardRequest(){ };
};

#endif //REVIIYOT_CARDREQUEST_H
