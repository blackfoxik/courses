
#include "console.h"
#include <iostream>
#include "simpio.h"  // for getLine

#include "exercise2.h"
using namespace std;

void moveTowerEx2(int n, char start, char finish, char tmp);
void moveSingleDiskEx2(char start, char finish);
//void moveTowerOriginal(int n, char start, char finish, char tmp);


void exercise2() {
    int n = getInteger("Input n:");
    moveTowerEx2(n, 'A', 'B', 'C');
    //return 0;
}

void moveTowerEx2(int n, char start, char finish, char tmp) {
    if (n == 0) {
        return ;
    } else {
        moveTowerEx2(n - 1, start, tmp, finish);
        moveSingleDiskEx2(start, finish);
        moveTowerEx2(n - 1, tmp, finish, start);
    }
}


void moveSingleDiskEx2(char start, char finish) {
    cout << start << " -> " << finish << endl;
}

/*void moveTowerOriginal(int n, char start, char finish, char tmp) {
    if (n == 1) {
        moveSingleDiskEx2(start, finish);
    } else {
        moveTowerOriginal(n - 1, start, tmp, finish);
        moveSingleDiskEx2(start, finish);
        moveTowerOriginal(n - 1,  tmp, finish, start);
    }
}*/
