
#include "exercise4.h"
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

//const
const int LOW = 0;
const int TOP = 9999;

//prototypes

void sortEx4(Vector<int> & vect);
double getElapsedTimeEx4(Vector<int> & vect);
void getTrackEx4(Vector< Vector<int> > & setOfVects);
void printVectEx4(Vector<int> & vect);

void exercise4() {
    //Vector< Vector<int> > setOfVects = getSetOfVects();
    Vector< Vector<int> > setOfVects;
    Vector<int> curSet {99, 103, 789, 4567, 0, 5, 12, 454, 900, 567};
    Vector<int> copy = curSet;
    printVectEx4(copy);
    sortEx4(copy);
    printVectEx4(copy);
    setOfVects.add(curSet);
    getTrackEx4(setOfVects);
}

void getTrackEx4(Vector< Vector<int> > & setOfVects) {
    cout << setw(6) << " N" << setw(6) << "|" << setw(6) << "Time (msec)" << endl;
    cout << "-----------+-----------" << endl;
    for (int i = 0; i < setOfVects.size(); i++) {
        Vector<int> vect = setOfVects[i];
        double elapsed = getElapsedTimeEx4(vect);
        cout << setw(6) << vect.size() << setw(6) << "|" << setw(6) << elapsed << endl;
    }
}

double getElapsedTimeEx4(Vector<int> & vect) {
    int size = vect.size();
    if (size > 50) {
        size = 1;
    } else {
       size = 1000;
    }
    double start = double(clock()) / CLOCKS_PER_SEC;
    for (int i = 0; i < size; i++) {
        Vector<int> copy = vect;
        sortEx4(copy);
    }
    double finish = (double(clock()) / size) / CLOCKS_PER_SEC;
    double elapsed = finish - start;
    return elapsed;
}

void sortEx4(Vector<int> & vect) {
    Vector<int> templateSet(TOP + 1, -1);
    for (int i = 0; i < vect.size(); i++) {
        int curVal = vect[i];
        templateSet[curVal] = curVal;
    }
    Vector<int> result;
    for (int i = 0; i < templateSet.size(); i++) {
        int curVal = templateSet[i];
        if (curVal != -1) result.add(curVal);
    }
    vect = result;
}

void printVectEx4(Vector<int> & vect) {
    for (int tmp : vect) {
        cout << tmp << " ";
    }
    cout << endl;
}

