
#include "exercise3.h"
#include <iostream>
#include "console.h"
#include "simpio.h"
#include "grid.h"
#include "vector.h"
#include "map.h"
#include <ctime>
#include "exercise2.h"
#include "random.h"
#include <iomanip>

using namespace std;


void swapItemsEx3(Vector<int> & vect, int posA, int posB);
void sortEx3(Vector<int> & vect);
void fillCurSet(Vector<int> & curSet, int n);
Vector< Vector<int> > getSetOfVects();
double getElapsedTime(Vector<int> & vect);
void getTrack(Vector< Vector<int> > & setOfVects);

void exercise3() {
    Vector< Vector<int> > setOfVects = getSetOfVects();
    getTrack(setOfVects);
}

void fillCurSet(Vector<int> & curSet, int n){
    for (int i = 0; i < n; i++) {
        int randomValue = randomInteger(0,n);
        curSet.add(randomValue);
    }
}

Vector< Vector<int> > getSetOfVects() {
    Vector< Vector<int> > result;
    for (int i = 0; i < 9; i ++) {
        Vector<int> curSet;
        if (i == 0) fillCurSet(curSet, 10);
        if (i == 1) fillCurSet(curSet, 50);
        if (i == 2) fillCurSet(curSet, 100);
        if (i == 3) fillCurSet(curSet, 500);
        if (i == 4) fillCurSet(curSet, 1000);
        if (i == 5) fillCurSet(curSet, 5000);
        if (i == 6) fillCurSet(curSet, 10000);
        if (i == 7) fillCurSet(curSet, 50000);
        if (i == 8) fillCurSet(curSet, 100000);
        result.add(curSet);
    }
    return result;
}

double getElapsedTime(Vector<int> & vect) {
    int size = vect.size();
    if (size > 50) {
        size = 1;
    } else {
       size = 1000;
    }
    double start = double(clock()) / CLOCKS_PER_SEC;
    for (int i = 0; i < size; i++) {
        Vector<int> copy = vect;
        sortEx3(copy);
    }
    double finish = (double(clock()) / size) / CLOCKS_PER_SEC;
    double elapsed = finish - start;
    return elapsed;
}

void getTrack(Vector< Vector<int> > & setOfVects) {
    cout << setw(6) << " N" << setw(6) << "|" << setw(6) << "Time (msec)" << endl;
    cout << "-----------+-----------" << endl;
    for (int i = 0; i < setOfVects.size(); i++) {
        Vector<int> vect = setOfVects[i];
        double elapsed = getElapsedTime(vect);
        cout << setw(6) << vect.size() << setw(6) << "|" << setw(6) << elapsed << endl;
    }
}

void sortEx3(Vector<int> & vect) {
    for (int i = 0; i < vect.size(); i++) {
        for (int j = 1; j < vect.size(); j++) {
           // cout << "i = " << i << " j = " << j << endl;
            if (vect[j] < vect[j - 1]) {
                swapItemsEx3(vect, j, j - 1);
               //printVect(vect);
            }
        }
        //cout << i << endl;
    }
}

void swapItemsEx3(Vector<int> & vect, int posA, int posB) {
    int tmp = vect[posA];
    vect[posA] = vect[posB];
    vect[posB] = tmp;
}

