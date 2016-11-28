//
// Created by liorgre on 26/11/16.
//

#include <vector>
#include "../include/Hand.h"

Hand::Hand(){
};
Hand::Hand(const Hand &otherHand) {

    for(int i=0;i<otherHand.inHand.size();i++){
        inHand.push_back(otherHand.inHand[i]->clone());
    }
}

int Hand::getNumberOfCards(){
    return inHand.size();
};
Hand::~Hand() {
    for(int i=0; i<inHand.size();i++){
        delete(inHand[i]);
    }
    inHand.clear();
}

std::vector<Card*> Hand::tryGetCards(string value){
    std::string compare =value;
    int size;
    int i=0;
    vector<Card*> ans;

    for(int i=0; i<inHand.size();i++){
        string cardToCompare = inHand[i]->toString();
        cardToCompare = cardToCompare.substr(0,cardToCompare.size()-1);

        if(cardToCompare==compare){
            ans.push_back(inHand[i]);
        }
    }
    return ans;
};

bool Hand::addCard(Card &card){
    int i;
    for(i=0;i<inHand.size();i++){
        if(card.compareTo(*inHand[i])==0){
            break;
        }
    }
    inHand.insert(inHand.begin()+i, &card);
    remove4ofAKind();
    return true;
};

bool Hand::removeCard(Card &card){
    for(int i=0;i<inHand.size();i++){
        if(card.toString()==inHand[i]->toString()){
            inHand.erase(inHand.begin()+i);
            break;
        }
    }
    return true;
};

vector<Card*> Hand::getInHandCards() {
    return inHand;
}

string Hand::toString() {
    string returnStr = "";
    for (int i = 0; i < inHand.size(); i++) {
        returnStr += inHand[i]->toString() + " ";
    }
    return returnStr.substr(0,returnStr.size()-1);
}

void Hand::remove4ofAKind() {
    int counter=1;

    for(int i=1;i<inHand.size();i++) {
        if (inHand[i]->isValueEqual(*inHand[i - 1])) {
            counter++;
        }
        else {
            counter = 1;
        }
        if (counter == 4) {
            for (int x = i - 3; x <= i; x++) {
                delete (inHand[x]);
            }
            inHand.erase(inHand.begin() + (i - 3), inHand.begin() + i+1);
            i -= 3;
            counter = 1;
        }
    }
}


