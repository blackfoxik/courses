
#include "console.h"
#include "simpio.h"  // for getLine
#include "lexicon.h"
#include "vector.h"
#include "exercise7.h"
#include <foreach.h>
#include "card.h"
using namespace std;

//func prototypes
int countFifteens(Vector<Card> &cards);
void countFifteens(Vector<Card> &curSet, Vector<Card> &cards, int &count);
bool setHasSumOfFefteen(Vector<Card> &curSet);
void printSet(Vector<Card> &cards);

//general
void exercise7() {

    Card newCard1 = Card("AD");
    Card newCard2 = Card("5C");
    Card newCard3 = Card("10S");
    Card newCard4 = Card("4H");
    Card newCard5 = Card("9C");

    Card newCard11 = Card(FIVE,CLUBS);
    Card newCard12 = Card(FIVE,DIAMONDS);
    Card newCard13 = Card(FIVE,HEARTS);
    Card newCard14 = Card(FIVE,SPADES);
    Card newCard15 = Card(JACK,CLUBS);

    Vector<Card> setOfCards1 {newCard1,newCard2,newCard3, newCard4, newCard5};
    Vector<Card> setOfCards2 {newCard11, newCard12, newCard13, newCard14, newCard15};
    cout << countFifteens(setOfCards1) << endl;
}

int countFifteens(Vector<Card> &cards) {
    Vector<Card> curSet;
    int count = 0;
    countFifteens(curSet, cards, count);
    return count;
}

void countFifteens(Vector<Card> &curSet, Vector<Card> &cards, int &count) {
    if (setHasSumOfFefteen(curSet) || cards.isEmpty()) {
          if (setHasSumOfFefteen(curSet)) {
              count++;
              printSet(curSet);
          }
        curSet.clear();
        return;
    }
    Card curCard = cards.get(0);
    Vector<Card> rest = cards;
    rest.remove(0);

    Vector<Card> prevCurSet = curSet;

    curSet.add(curCard);
    countFifteens(curSet, rest, count);
    countFifteens(prevCurSet, rest, count);
}

void printSet(Vector<Card> &cards) {
    foreach (Card curCard in cards) {
        cout << curCard << endl;
    }
    cout << "********" << endl;
}

bool setHasSumOfFefteen(Vector<Card> &curSet) {
    int sum = 0;
    foreach (Card curCard in curSet) {
        int curRank = curCard.getRank();
        if (curRank == 11 || curRank == 12 || curRank == 13) {
            curRank = 10;
        }
        sum += curRank;
    }
    return sum == 15;
}

