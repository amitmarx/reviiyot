//
// Created by Amit Marx on 19/11/2016.
//

#include "../../include/Card.h"


NumericCard::NumericCard(Shape s, int num): Card(s),number(num) {

}
string NumericCard::toString() {
    return to_string(number) + Card::getShapeFirstLetter();
}

NumericCard::NumericCard(const NumericCard & c) :Card(c){
    number = c.number;
}

Card *NumericCard::clone() {
    return new NumericCard(*this);
}





