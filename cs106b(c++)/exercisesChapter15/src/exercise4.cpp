#include "console.h"
#include "simpio.h"  // for getLine
#include "stack.h"
#include "assert.h"
#include "exercise4.h"
using namespace std;

int* getTable();
int romanToDecimal(string roman);
int getValue(int *lookup, char curSign);


void exercise4() {
    string roman = "MCMLXIX";
    cout << romanToDecimal(roman) << endl;
}

int romanToDecimal(string roman) {
    int *lookup = getTable();
    int res = 0;
    //go through every except last element
    for (int i = 0; i < roman.size() - 1; i++) {
        int cur = getValue(lookup,roman[i]);
        int following = getValue(lookup,roman[i + 1]);
        if (cur >= following) {
            res += cur;
        } else {
            res -= cur;
        }
    }
    //last element always add to result
    res += getValue(lookup, roman[roman.size()-1]);
    return res;
}

int getValue(int *lookup, char curSign) {
    return lookup[curSign - 'A'];
}

int* getTable() {
    int indexI = 'I' - 'A';
    int indexV = 'V' - 'A';
    int indexX = 'X' - 'A';
    int indexL = 'L' - 'A';
    int indexC = 'C' - 'A';
    int indexD = 'D' - 'A';
    int indexM = 'M' - 'A';
    int *lookUp = new int[24];
    for (int i = 0; i < 24; i++) {
        lookUp[i] = 0;
    }
    lookUp[indexI] = 1;
    lookUp[indexV] = 5;
    lookUp[indexX] = 10;
    lookUp[indexL] = 50;
    lookUp[indexC] = 100;
    lookUp[indexD] = 500;
    lookUp[indexM] = 1000;
    return lookUp;
}

