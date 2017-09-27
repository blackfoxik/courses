#include <string>
//#include <ostream>
#include "domino.h"
using namespace std;

Domino::Domino() {
    leftDots = 0;
    rightDots = 0;
}

Domino::Domino(int inputLeftDots,int inputRightDots) {
    leftDots = inputLeftDots;
    rightDots = inputRightDots;
}

int Domino::getLeftDots() {
    return leftDots;
}

int Domino::getRightDots() {
    return rightDots;
}

string Domino::toString() {
    return "[ " + to_string(getLeftDots()) + " | " + to_string(getRightDots()) + " ]";
    //return "domino has " + to_string(getLeftDots()) + " on the left side and " + to_string(getRightDots()) + " on the right side";
}

ostream & operator<<(ostream & os, Domino domino){
    os << domino.toString();
    return os;
}


