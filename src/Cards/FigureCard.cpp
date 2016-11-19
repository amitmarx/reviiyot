//
// Created by Amit Marx on 19/11/2016.
//

#include "../../include/Card.h"

FigureCard::FigureCard(Shape s, Figure f): Card(s),figure(f) {

}
string FigureCard::toString() {
    return getFigureFirstLetter() + Card::getShapeFirstLetter();
}

string FigureCard::getFigureFirstLetter(){
    switch (figure){
        case (Figure::Ace) : return "A";
        case (Figure::Jack) : return "J";
        case (Figure::King) : return "K";
        default: return "Q";
    }
}

