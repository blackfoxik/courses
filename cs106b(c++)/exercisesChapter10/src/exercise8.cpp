#include "console.h"
#include "simpio.h"  // for getLine
#include <iomanip>
#include "set.h"
#include "grid.h"
#include "exercise8.h"
#include "random.h"
using namespace std;


const int CROSSOVER_POINT = 10;
//func prototypes
void printVectEx8(Vector<int> & vect);
int partitionEx8(Vector<int> & vect, int start, int finish);
void quickSortEx8(Vector<int> & vect, int start, int finish);
void insertionSort(Vector<int> & vect, int start, int finish);
void hybridSort(Vector<int> & vect);
void fillSetEx8(Vector<int> & curSet, int n);


void exercise8() {
    //Vector<int> vect {56,25,37,58,95,19,73,30};
    //Vector<int> vect {56,25,37,58,95,19,73,30,22,5,78,33,55,76,90,21,33,54,99,100,11,27,43,67,9};
    //Vector<int> vect {56,25,37,58,95,19,73,30,22,5};
    Vector<int> vect;
    fillSetEx8(vect,50);
    printVectEx8(vect);
    quickSortEx8(vect, 0, vect.size() - 1);
    printVectEx8(vect);
    insertionSort(vect, 0, vect.size() - 1);
    printVectEx8(vect);
}


void quickSortEx8(Vector<int> & vect, int start, int finish) {
    if (start >= finish) return;
    if (finish - start < CROSSOVER_POINT) {
       return;
    }
    cout << "quick" << endl;
    int boundary = partitionEx8(vect, start, finish);
    quickSortEx8(vect, start, boundary - 1);
    quickSortEx8(vect, boundary + 1, finish);
}


void insertionSort(Vector<int> & vect, int start, int finish) {
    for (int i = start + 1; i <= finish; i++) {
        int curItem = vect[i];

        for (int j = i - 1; j >= 0 && vect[j] > curItem; j--) {
            vect[j + 1] = vect[j];
            vect[j] = curItem;
            //printVectEx8(vect);
        }
    }
}



int partitionEx8(Vector<int> & vect, int start, int finish) {
    int pivot = vect[start];
    int lh = start + 1;
    int rh = finish;
    while (true) {
        while (lh < rh && vect[rh] >= pivot) rh--;
        while (lh < rh && vect[lh] < pivot) lh++;
        if (lh == rh) break;
        int tmp = vect[lh];
        vect[lh] = vect[rh];
        vect[rh] = tmp;
    }
    if (vect[lh] >= pivot) return start;
    vect[start] = vect[lh];
    vect[lh] = pivot;
    return lh;
}



void printVectEx8(Vector<int> & vect) {
    for (int tmp : vect) {
        cout << tmp << " ";
    }
    cout << endl;
}

void fillSetEx8(Vector<int> & curSet, int n){
    for (int i = 0; i < n; i++) {
        int randomValue = randomInteger(0,n);
        curSet.add(randomValue);
    }
}
