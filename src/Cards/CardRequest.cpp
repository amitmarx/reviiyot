//
// Created by amitmarx on 22/11/16.
//

#include "../../include/CardRequest.h"
string CardRequest::getValue() const {
    return requestedValue;
}
CardRequest::CardRequest(string value): requestedValue(value) {
}

CardRequest::CardRequest(const CardRequest& req): requestedValue(req.requestedValue) {
}


InOrderCardRequest::InOrderCardRequest(string value, int pos): CardRequest(value),position(pos) {
}
InOrderCardRequest::InOrderCardRequest(const InOrderCardRequest &inOr) : CardRequest(inOr),position(inOr.position)  {

}

int InOrderCardRequest::getPosition() {
    return position;
}

CardRequest* InOrderCardRequest::clone() {
    return new InOrderCardRequest(*this);
}


CardRequest* TakeFromHighestCardRequest::clone() {
    return new TakeFromHighestCardRequest(*this);
}

