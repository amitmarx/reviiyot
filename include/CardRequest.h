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
    CardRequest(const CardRequest& req);
    virtual ~CardRequest(){ };
    virtual CardRequest* clone()=0;
    string getValue() const;
};

class InOrderCardRequest : public CardRequest {
private:
    int position;
public:
    InOrderCardRequest(string reqValue, int pos);
    InOrderCardRequest(const InOrderCardRequest& inOr);
    CardRequest* clone();
    int getPosition();
    virtual ~InOrderCardRequest(){ };
};

class TakeFromHighestCardRequest  : public CardRequest{
public:
    TakeFromHighestCardRequest(string reqValue ): CardRequest(reqValue) { };
    TakeFromHighestCardRequest(const TakeFromHighestCardRequest& req ): CardRequest(req) { };
    CardRequest* clone();
    virtual ~TakeFromHighestCardRequest(){ };
};

#endif //REVIIYOT_CARDREQUEST_H
