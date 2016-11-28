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
	virtual ~Card();
	virtual string toString() = 0; //Returns the string representation of the card "<value><shape>" exp: "12S" or "QD"
	virtual Card* clone()=0;
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
	virtual ~FigureCard(){};
	Card* clone();
	virtual string toString() override;
	Figure getFigure();

};

class NumericCard : public Card {
private:
    int number;
public:
	NumericCard(Shape s, int number);
	NumericCard(const NumericCard& c );
	virtual ~NumericCard(){};
	virtual string toString() override;
	Card* clone();
};

#endif
