//
// Created by amitmarx on 22/11/16.
//

#include "../../include/CardRequest.h"
string CardRequest::getValue() {
    return requestedValue;
}
CardRequest::CardRequest(string value) {
    requestedValue=value;
}
InOrderCardRequest::InOrderCardRequest(string value, int pos): CardRequest(value) {
    position = pos;
}
int InOrderCardRequest::getPosition() {
    return position;
}