
#include "console.h"
#include "simpio.h"  // for getLine
#include "lexicon.h"
#include "set.h"
#include "exercise9.h"
#include <foreach.h>
#include "domino.h"
#include "vector.h"

using namespace std;

//func prototypes
bool formsDominoChain(Vector<Domino> & dominos);
bool formsDominoChain(Vector<Domino> & dominos, string chain);
Vector<Domino> initSet();

//general
void exercise9() {
    Vector<Domino> dominos = initSet();
    if (formsDominoChain(dominos)) {
        cout << "set is solved" << endl;
    } else {
        cout << "set isn't solved" << endl;
    }
}

Vector<Domino> initSet() {
    Domino d1(1,3);
    Domino d2(2,6);
    Domino d3(3,4);
    Domino d4(5,6);
    Domino d5(4,2);
    Domino d6(1,1);
    Domino d7(2,3);
    Vector<Domino> dominos;
    dominos.add(d1);
    dominos.add(d2);
    dominos.add(d3);
    dominos.add(d4);
    dominos.add(d5);
    dominos.add(d6);
    dominos.add(d7);
    return dominos;
}

bool formsDominoChain(Vector<Domino> & dominos) {
    string chain = "";
    if (formsDominoChain(dominos, chain)) {
        return true;
    } else {
        return false;
    }
}

bool formsDominoChain(Vector<Domino> & dominos, string chain) {
    if (dominos.size() == 0) {
        cout << chain << endl;
        return true;
    }
    Vector<Domino> rest = dominos;
    //cout << chain << endl;

    if (chain == "") {
        Domino curD = rest.get(0);
        rest.remove(0);
        chain = integerToString(curD.getLeftDots()) + integerToString(curD.getRightDots());
    }
    for (int i = 0; i < rest.size(); i++) {
       string prevChain = chain;
       string firstSign = chain.substr(0,1);
       string lastSign = chain.substr(chain.length() - 1);
       Domino curD = rest.get(i);
       string curDLeftSide = integerToString(curD.getLeftDots());
       string curDRightSide = integerToString(curD.getRightDots());
       if (firstSign == curDLeftSide) {
           Vector<Domino> curDominos = rest;
           curDominos.remove(i);
           prevChain = curDRightSide + curDLeftSide + chain;
           if (formsDominoChain(curDominos, prevChain)) return true;
       }
       prevChain = chain;
       if (firstSign == curDRightSide) {
           prevChain = curDLeftSide + curDRightSide + chain;
           Vector<Domino> rest2 = rest;
           rest2.remove(i);
           if (formsDominoChain(rest2, prevChain)) return true;
       }
       prevChain = chain;
       if (lastSign == curDLeftSide) {
           Vector<Domino> rest2 = rest;
           rest2.remove(i);
           prevChain = chain + curDLeftSide + curDRightSide;
           if (formsDominoChain(rest2, prevChain)) return true;
       }
       prevChain = chain;
       if (lastSign == curDRightSide) {
           Vector<Domino> rest2 = rest;
           rest2.remove(i);
           prevChain = chain + curDRightSide + curDLeftSide;
           if (formsDominoChain(rest2, prevChain)) return true;
       }
    }
    return false;
}




