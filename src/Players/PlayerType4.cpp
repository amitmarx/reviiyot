//
// Created by amitmarx on 26/11/16.
//

#include "../../include/Player.h"
CardRequest* PlayerType4::playTurn() {
    string returnVal = getInHandCards()[0]->toString();
    returnVal = returnVal.substr(0,returnVal.size()-1);

    InOrderCardRequest* response = new InOrderCardRequest(returnVal,playerToAsk);
    playerToAsk++;

    return response;
}