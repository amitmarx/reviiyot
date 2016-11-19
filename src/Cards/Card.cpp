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
Card::~Card() {

}
