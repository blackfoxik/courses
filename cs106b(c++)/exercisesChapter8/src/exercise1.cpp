
#include "console.h"
#include "simpio.h"  // for getLine

#include "exercise1.h"
using namespace std;

void moveTower(int n, int &countOfMoves) {
    if (n == 1) {
        countOfMoves++;
    } else {
        moveTower(n - 1, countOfMoves);
        countOfMoves++;
        moveTower(n - 1, countOfMoves);
    }
}

int countHanoiMoves(int n) {
    int countOfMoves = 0;
    moveTower(n,countOfMoves);
    return countOfMoves;
}

void exercise1() {
    int n = getInteger("Input n:");
    cout<< countHanoiMoves(n) << endl;
}
