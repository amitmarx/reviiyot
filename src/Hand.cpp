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
    string s=card.toString().substr(0,(card.toString()).length()-1);
    remove4ofAKind(s);
    return true;
};

bool Hand::removeCard(Card &card){
    int x= binarySearch(getInHandCards(),0,getInHandCards().size()-1,card);
    inHand.erase(inHand.begin()+x);
//    for(int i=0;i<inHand.size();i++){
//        if(card.toString()==inHand[i]->toString()){
//            inHand.erase(inHand.begin()+i);
//            break;
//        }
//    }
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

void Hand::remove4ofAKind(string s) {
    int counter=1;
    for(int i=1;i<inHand.size();i++) {
        if (inHand[i]->toString().substr(0,inHand[i]->toString().length()-1)==s){
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
    }}

int Hand::binarySearch(std::vector<Card *> vec, int start, int end, Card &card) {
    if(start > end) {
        return -1;
    }
    const int middle = start + ((end - start) / 2);
    if(vec[middle]->isValueEqual(card)){
        return middle;
    }
    else if(vec[middle]->compareTo(card)==1){
        return binarySearch(vec, start, middle - 1, card);
    }
    return binarySearch(vec, middle + 1, end, card);
};


