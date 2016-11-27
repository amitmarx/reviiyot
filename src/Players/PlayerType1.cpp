//
// Created by amitmarx on 26/11/16.
//

#include "../../include/Player.h"

CardRequest* PlayerType1::playTurn() {
    vector<Card*> inHand = getInHandCards();
    int counter=1;
    int counterMax = 0;
    Card *cardAppearedMost= inHand[0];

    for(int i=0;i<inHand.size()-1;i++){
        if(inHand[i]->isValueEqual(*inHand[i+1])){
            counter++;
        }
        else{
            counter=1;
        }
        if(counter>=counterMax){
            counterMax = counter;
            cardAppearedMost = inHand[i];
        }
    }
    string returnVal = cardAppearedMost->toString();
    returnVal = returnVal.substr(0,returnVal.size()-1);
    return new TakeFromHighestCardRequest(returnVal);
}