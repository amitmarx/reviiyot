#ifndef CARD_H_
#define CARD_H_

#include <iostream>
using namespace std;

enum Shape {
	Club,
	Diamond,
	Heart,
	Spade
};

enum Figure {
	Jack,
	Queen,
	King,
	Ace
};

class Card {
private:
    Shape shape;
protected:
    string getShapeFirstLetter();
    Card(Shape s);

public:
    virtual string toString() = 0; //Returns the string representation of the card "<value><shape>" exp: "12S" or "QD"
    virtual ~Card();


};

class FigureCard : public Card {
private:
	Figure figure;
    string getFigureFirstLetter();
public:
    FigureCard(Shape shape, Figure figure );
	virtual string toString() override;
};

class NumericCard : public Card {
private:
    NumericCard(int num, Shape s);

    int number;
public:
	virtual string toString() override;
    NumericCard(Shape s, int number);
};

#endif
