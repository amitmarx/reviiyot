//
// Created by Amit Marx on 19/11/2016.
//

#include "../../include/Card.h"

string Card::getShapeFirstLetter() {
    switch (shape){
        case (Shape ::Club) : return "C";
        case (Shape ::Diamond) : return "D";
        case (Shape ::Heart) : return "H";
        default: return "S";
    }
}

Card::Card(Shape s) {
    shape=s;
}
Card::Card(const Card & c) {
    shape=c.shape;
}
Card::~Card() {

}

int Card::compareTo(Card &other) {

    string otherStr=other.toString();
    int otherNum = findNumericValue(otherStr);

    string thisStr = toString();
    int thisNum = findNumericValue(thisStr);

    //Equals but not figure
    if(thisNum!=0 && thisNum==otherNum){
        return compareByShape(*this,other);
    }
    //Both numbers
    if(thisNum!=0 &&otherNum!=0){
        return thisNum>otherNum;
    }
    //This is figure
    else if(thisNum==0 && otherNum!=0){
        return 1;
    }
    //Other is figure
    else if(thisNum!=0 && otherNum==0){
        return 0;
    }
    //Both figures
    else{
        return compareByFigure(*this,other);
    }
}
int Card::compareByShape(Card& lCard,Card& rCard){
    string rCardStr=rCard.toString();
    char rCardShape = rCardStr[rCardStr.size()-1];

    string lCardStr=lCard.toString();
    char lCardShape = lCardStr[lCardStr.size()-1];

    return lCardShape > rCardShape;


}
int Card::compareByFigure(Card& lCard,Card& rCard){
    FigureCard * lFigureCard =
            dynamic_cast<FigureCard*>(&lCard);

    FigureCard * rFigureCard =
            dynamic_cast<FigureCard*>(&rCard);

    if(lFigureCard->getFigure() == rFigureCard->getFigure()){
        return compareByShape(lCard,rCard);
    }
    return lFigureCard->getFigure() > rFigureCard->getFigure();
}

int Card::findNumericValue(string str){
    int i=0;
    int sum=0;
    while(str[i]>='0' && str[i]<='9'){
        sum*=10;
        sum+=str[i] - '0';
        i++;
    }
    return sum;
}
Shape Card::findShape(char &s) {
    switch(s){
        case 'C':
            return Shape ::Club;
        case 'D':
            return Shape ::Diamond;
        case 'H':
            return Shape ::Heart;
        default:
            return Shape ::Spade;
    }
}

bool Card::isValueEqual(Card &other) {
    string thisStr = toString();
    thisStr = thisStr.substr(0,thisStr.size()-1);
    string otherStr = other.toString();
    otherStr = otherStr.substr(0,otherStr.size()-1);
    return thisStr==otherStr;
}



