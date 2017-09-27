#include "exercise1.h"
#include <iostream>
#include "console.h"
#include "simpio.h"
#include "grid.h"
#include "vector.h"

using namespace std;

int raiseToPower( int x, int n);

void exercise1() {
 int x = getInteger("input x: ");
 int n = getInteger("input n: ");
 cout << raiseToPower(x, n) << endl;
}

int raiseToPower( int x, int n) {
    if (n == 1) return x;
    int mid = n / 2;
    return raiseToPower( x, mid) * raiseToPower(x, n - mid);
}
