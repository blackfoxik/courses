#include "exercise1.h"
#include <iostream>
#include "console.h"
#include "simpio.h"
#include "grid.h"
#include "vector.h"


#include "exercise2.h"
void printVect(Vector<int> & vect);
void swapItems(Vector<int> & vect, int posA, int posB);
void sort(Vector<int> & vect);

void exercise2() {
    Vector<int> vect {56,25,37,58,95,19,73,30};
    printVect(vect);
    sort(vect);
    printVect(vect);
}

void sort(Vector<int> & vect) {
    for (int i = 0; i < vect.size(); i++) {
        for (int j = 1; j < vect.size(); j++) {
           // cout << "i = " << i << " j = " << j << endl;
            if (vect[j] < vect[j - 1]) {
                swapItems(vect, j, j - 1);
               //printVect(vect);
            }
        }
        //cout << i << endl;
    }
}

void swapItems(Vector<int> & vect, int posA, int posB) {
    int tmp = vect[posA];
    vect[posA] = vect[posB];
    vect[posB] = tmp;
}

void printVect(Vector<int> & vect) {
    for (int tmp : vect) {
        cout << tmp << " ";
    }
    cout << endl;
}
