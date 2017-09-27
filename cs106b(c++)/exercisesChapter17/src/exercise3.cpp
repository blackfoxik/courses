#include "exercise3.h"
#include <iostream>
#include "console.h"
#include "simpio.h"
#include "set.h"
#include <cmath>


using namespace std;

void printSet(Set<int> &s) {
    Set<int>::iterator it;
    for ( it=s.begin() ; it != s.end(); it++ )
        cout << " " << *it;
    cout<< endl;
}

Set<int> createPrimeSet(int n) {
    Set<int> result;
    for (int i = 2; i < n; i++) {
        int top = int(sqrt(double(i)));
        bool prime = true;
        for (int j = 2; j <= top; j++) {
            if (i % j == 0) {
                prime = false;
                break;
            }
        }
        if (prime) result.add(i);
    }
    return result;
}


void exercise3() {
  int n = 100;
  Set<int> s = createPrimeSet(n);
  printSet(s);
}
