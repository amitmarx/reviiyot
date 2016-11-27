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


public:
	Card(Shape s);
	Card(const Card & c);
    virtual string toString() = 0; //Returns the string representation of the card "<value><shape>" exp: "12S" or "QD"
    virtual ~Card();
	int compareTo(Card& other);
	bool isValueEqual(Card& other);
	static Shape findShape(char &s);
	static int findNumericValue(string str);
	static int compareByShape(Card &lCard, Card &rCard);
	static int compareByFigure(Card &lCard, Card &rCard);
};

class FigureCard : public Card {
private:
	Figure figure;
    string getFigureFirstLetter();
public:
    FigureCard(Shape shape, Figure figure );
	FigureCard(const FigureCard & c);
	virtual string toString() override;
	Figure getFigure();

};

class NumericCard : public Card {
private:
    NumericCard(int num, Shape s);

    int number;
public:
	virtual string toString() override;
    NumericCard(Shape s, int number);
	NumericCard(const NumericCard & c);
};

#endif
