#ifndef _card_h
#define _card_h
#include <iostream>
#include <string>
using namespace std;

enum Rank { ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING};
enum Suit { CLUBS, DIAMONDS, HEARTS, SPADES };

class Card {
public:
    Card();
    Card(string rankAndSuit);
    Card(Rank inputRank, Suit inputSuit);
    string toString();
    Rank getRank();
    Suit getSuit();

    void setRank(int curRank);
    void setSuit(Suit curSuit);

private:
    int rank;
    Suit suit;
};


ostream & operator<<(ostream &os, Card curCard);
Suit operator++(Suit & curSuit, int);
Rank operator++(Rank & curRank, int);

#endif
