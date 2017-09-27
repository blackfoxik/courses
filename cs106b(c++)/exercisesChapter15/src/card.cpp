#include <iostream>
#include <string>
#include "card.h"
#include "map.h"
using namespace std;


string rankToString(int curRank);
string suitToString(Suit curSuit);
int stringToRank(string curRank);
Suit stringToSuit(string curSuit);


    Card::Card() {

    }

    Card::Card(string rankAndSuit) {
        if(rankAndSuit.size() == 2){
            string curRank = rankAndSuit.substr(0,1);
            rank = stringToRank(curRank);
            if(rank == 0) {
                rank = stringToInteger(curRank);
            }
            string curSuit = rankAndSuit.substr(1);
            suit = stringToSuit(curSuit);
        }
        else if(rankAndSuit.size() == 3){
            string curRank = rankAndSuit.substr(0,2);
            rank = stringToInteger(curRank);
            string curSuit = rankAndSuit.substr(2);
            suit = stringToSuit(curSuit);
        }
    }

    Card::Card(Rank inputRank, Suit inputSuit){
        suit = inputSuit;
        rank = inputRank;
    }

    string Card::toString() {
        return rankToString(rank) + suitToString(suit);
    }

    Rank Card::getRank() {
        return Rank(rank);
    }

    Suit Card::getSuit() {
        return suit;
    }

    void Card::setRank(int curRank) {
        rank = curRank;
    }

    void Card::setSuit(Suit curSuit) {
        suit = curSuit;
    }

    ostream & operator<<(ostream &os, Card curCard) {
        return os << curCard.toString();
    }

    Suit operator++(Suit & curSuit, int) {
        Suit old = curSuit;
        curSuit = Suit(curSuit + 1);
        return old;
    }

    Rank operator++(Rank & curRank, int) {
        Rank old = curRank;
        curRank = Rank(curRank + 1);
        return old;
    }

    string rankToString(int curRank) {
        switch(curRank){
            case 1:
                return "A";
            case 11:
                return "J";
            case 12:
                return "Q";
            case 13:
                return "K";
            default:
                return to_string(curRank);
        }
    }

    string suitToString(Suit curSuit) {
        switch(curSuit){
            case DIAMONDS:
                return "D";
            case CLUBS:
                return "C";
            case HEARTS:
                return "H";
            case SPADES:
                return "S";
            default:
                return "NOT A SUIT";
        }
    }

    int stringToRank(string curRank) {
        Map<string,int> ranks;
        ranks.add("A",1);
        ranks.add("J",11);
        ranks.add("Q",12);
        ranks.add("K",13);
        return ranks.get(curRank);
    }
    Suit stringToSuit(string curSuit) {
        Map<string,Suit> suits;
        suits.add("D",DIAMONDS);
        suits.add("C",CLUBS);
        suits.add("H",HEARTS);
        suits.add("S",SPADES);
        return suits.get(curSuit);
    }


