//
// Created by amitmarx on 26/11/16.
//

#include <limits>
#include "../../include/Player.h"
CardRequest* PlayerType2::playTurn() {
    vector<Card*> inHand = getInHandCards();
    int counter=1;
    int counterMin = std::numeric_limits<int>::max();
    Card *cardAppearedLeast= inHand[0];

    for(int i=0;i<inHand.size()-1;i++){
        if(inHand[i]->isValueEqual(*inHand[i+1])){
            counter++;
        }
        else{
            if(counter<counterMin){
                counterMin = counter;
                cardAppearedLeast = inHand[i];
            }
            counter=1;
        }

    }
    string returnVal = cardAppearedLeast->toString();
    returnVal = returnVal.substr(0,returnVal.size()-1);
    return new TakeFromHighestCardRequest(returnVal);
}