#include "exercise1.h"
#include <iostream>
#include "console.h"
#include "simpio.h"

#include "swap.h"

//using namespace std;

void exercise1() {
    int i = 1;
    int r = 5;
    swap2(i, r);
    string s1 = "s1";
    string s2 = "s2";
    swap2(s1, s2);
    cout << "i: " << i << " r: " << r << endl;
    cout << "s1: " << s1 << " s2: " << s2 << endl;
}
