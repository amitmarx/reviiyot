//
// Created by Amit Marx on 19/11/2016.
//

#include "../include/Deck.h"
#include <queue>

Card* Deck::fetchCard() {
    Card * returnVal = nullptr;
    if(!cards.empty()){
        returnVal = cards.top();
        cards.pop();
    }
    return returnVal;
}

int Deck::getNumberOfCards() {
    return cards.size();
}

string Deck::toString() {
    stack<Card*> tempDeck = cards;
    string output="";
    while(!tempDeck.empty()){
        output += tempDeck.top()->toString();
        tempDeck.pop();
        output+= " ";
    }
    //remove last space as required
    output = output.substr(0,output.length()-1);
    return output;
}

void Deck::initDeck(string deck) {
    int lastLetter=deck.length()-1;

    //dealing with spaces at the end of the string
    while(deck[lastLetter]<'A'||deck[lastLetter]>'Z'){
        --lastLetter;
    }

    //insert top to bottom
    for(int i=lastLetter;i>=0;i--){
    if(deck[i]==' '){
        int wordLength = lastLetter-i;
        string cardStr = deck.substr(i+1,wordLength);
        cards.push(createCard(cardStr));
        lastLetter=i-1;
        }
    }
    string cardStr = deck.substr(0,lastLetter+1);
    cards.push(createCard(cardStr));
}

Card *Deck::createCard(string cardStr) const {
    Shape shape = Card::findShape(cardStr[cardStr.length()-1]);
    int i=0;
    int sum=0;
    while(cardStr[i]>='0' && cardStr[i]<='9'){
        sum*=10;
        sum+=cardStr[i] - '0';
        i++;
    }
    Card* returnValue;
    //means that the card is a figure
    if(sum==0) {
        returnValue = new FigureCard(shape,findFigure(cardStr[0]));
    }
    else{
        returnValue = new NumericCard(shape,sum);
    }
    return returnValue;
}



Figure Deck::findFigure(char &s) const {
    switch(s){
        case 'A':
            return Figure ::Ace;
        case 'J':
            return Figure ::Jack;
        case 'K':
            return Figure ::King;
        default:
            return Figure ::Queen;
    }
}

Deck::~Deck() {
    while(!cards.empty()){
        delete cards.top();
        cards.pop();
    }
}

Deck:: Deck(const Deck &otherDeck) {
    stack<Card*> tempStack= otherDeck.cards;

    stack<Card*> reversedStack;
    while (!tempStack.empty()){
        reversedStack.push(tempStack.top()->clone());
        tempStack.pop();
    }
    while(!reversedStack.empty()){
        cards.push(reversedStack.top());
        reversedStack.pop();
    }

}

Deck &Deck::operator=(const Deck &otherDeck) {
    stack<Card*> tempStack= otherDeck.cards;

    stack<Card*> reversedStack;
    while (!tempStack.empty()){
        reversedStack.push(tempStack.top()->clone());
        tempStack.pop();
    }
    while(!reversedStack.empty()){
        cards.push(reversedStack.top());
        reversedStack.pop();
    }
}













