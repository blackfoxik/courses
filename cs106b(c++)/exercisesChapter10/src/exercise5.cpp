
#include "exercise5.h"
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


void swapItemsEx5(Vector<int> & vect, int posA, int posB);
void sortEx5(Vector<int> & vect);
void fillCurSetEx5(Vector<int> & curSet, int n);
Vector< Vector<int> > getSetOfVectsEx5();
//double getElapsedTime(Vector<int> & vect);
void getTrackEx5(Vector< Vector<int> > & setOfVects);

void exercise5() {
    Vector< Vector<int> > setOfVects = getSetOfVectsEx5();
    getTrackEx5(setOfVects);
}

void fillCurSetEx5(Vector<int> & curSet, int n){
    for (int i = 0; i < n; i++) {
        int randomValue = randomInteger(0,n);
        curSet.add(randomValue);
    }
}

Vector< Vector<int> > getSetOfVectsEx5() {
    Vector< Vector<int> > result;
    for (int i = 0; i < 9; i ++) {
        Vector<int> curSet;
        int curCount = 0;
        if (i == 0) curCount = 10;
        if (i == 1) curCount = 50;
        if (i == 2) curCount = 100;
        if (i == 3) curCount = 500;
        if (i == 4) curCount = 1000;
        if (i == 5) curCount = 5000;
        if (i == 6) curCount = 10000;
        if (i == 7) curCount = 50000;
        if (i == 8) curCount = 100000;
        fillCurSetEx5(curSet, curCount);
        result.add(curSet);
    }
    return result;
}



int findLinear(Vector<int> & vect, int number) {
    for (int i = 0; i < vect.size(); i++) {
        if (vect[i] == number) return i;
    }
    return -1;
}

double getElapsedTimeLinear(Vector<int> & vect) {
    int size = vect.size();
    if (size > 1000) {
        size = 1;
    } else {
       size = 10000;
    }
    double start = double(clock()) / CLOCKS_PER_SEC;
    for (int i = 0; i < size; i++) {
        int number = randomInteger(-999999,999999);
        Vector<int> copy = vect;
        findLinear(vect, number);
    }
    double finish = (double(clock()) / size) / CLOCKS_PER_SEC;
    double elapsed = finish - start;
    return elapsed;
}

int findBinary(Vector<int> & vect, int number, int pos1, int pos2) {
    if (pos1 > pos2) return -1;
    int mid = (pos1 + pos2) / 2;
    if (number == vect[mid]) return mid;
    if (number < mid) {
       return findBinary(vect, number, pos1, mid - 1);
    } else {
       return findBinary(vect, number, mid + 1, pos2);
    }
}

int findBinary(Vector<int> & vect, int number) {
    return findBinary(vect, number, 0, vect.size() - 1);
}

double getElapsedTimeBinary(Vector<int> & vect) {
    int size = vect.size();
    if (size > 1000) {
        size = 1;
    } else {
       size = 10000;
    }
    double start = double(clock()) / CLOCKS_PER_SEC;
    for (int i = 0; i < size; i++) {
        int number = randomInteger(-999999,999999);
        Vector<int> copy = vect;
        findBinary(vect, number);
    }
    double finish = (double(clock()) / size) / CLOCKS_PER_SEC;
    double elapsed = finish - start;
    return elapsed;
}

void getTrackEx5(Vector< Vector<int> > & setOfVects) {
    cout << setw(6) << "N" << setw(6) << "|" << setw(8) << "Linear" << setw(6) << "|" << setw(6) << "Binary" <<endl;
    cout << "-----------+-------------+------------" << endl;
    for (int i = 0; i < setOfVects.size(); i++) {
        Vector<int> vect = setOfVects[i];
        sortEx5(vect);
        double elapsedLinear = getElapsedTimeLinear(vect);
        double elapsedBinary = getElapsedTimeBinary(vect);
        cout << setw(6) << vect.size() << setw(6) << "|"
             << setw(12) << elapsedLinear << setw(2) << "|"
             << setw(2) << elapsedBinary << endl;
    }
}

void sortEx5(Vector<int> & vect) {
    for (int i = 0; i < vect.size(); i++) {
        for (int j = 1; j < vect.size(); j++) {
           // cout << "i = " << i << " j = " << j << endl;
            if (vect[j] < vect[j - 1]) {
                swapItemsEx5(vect, j, j - 1);
               //printVect(vect);
            }
        }
        //cout << i << endl;
    }
}

void swapItemsEx5(Vector<int> & vect, int posA, int posB) {
    int tmp = vect[posA];
    vect[posA] = vect[posB];
    vect[posB] = tmp;
}

