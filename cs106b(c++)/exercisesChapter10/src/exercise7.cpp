#include "console.h"
#include "simpio.h"  // for getLine
#include <iomanip>
#include "set.h"
#include "grid.h"
#include "exercise7.h"
#include "random.h"
using namespace std;


const int CROSSOVER_POINT = 10;
//func prototypes
void printVectEx7(Vector<int> & vect);
int partitionEx7(Vector<int> & vect, int start, int finish);
void quickSortEx7(Vector<int> & vect, int start, int finish);
void selectionSort(Vector<int> & vect, int start, int finish);
void hybridSort(Vector<int> & vect);
void fillSetEx7(Vector<int> & curSet, int n);


void exercise7() {
    //Vector<int> vect {56,25,37,58,95,19,73,30};
    //Vector<int> vect {56,25,37,58,95,19,73,30,22,5,78,33,55,76,90,21,33,54,99,100,11,27,43,67,9};
    //Vector<int> vect {56,25,37,58,95,19,73,30,22,5};
    Vector<int> vect;
    fillSetEx7(vect,1000);
    printVectEx7(vect);
    quickSortEx7(vect, 0, vect.size() - 1);
    //selectionSort(vect, 0, vect.size() - 1);
    printVectEx7(vect);
}


void quickSortEx7(Vector<int> & vect, int start, int finish) {
    if (start >= finish) return;
    if (finish - start < CROSSOVER_POINT) {
       cout << "select" << endl;
       selectionSort(vect, start, finish);
       return;
    }
    cout << "quick" << endl;
    int boundary = partitionEx7(vect, start, finish);
    quickSortEx7(vect, start, boundary - 1);
    quickSortEx7(vect, boundary + 1, finish);
}


void selectionSort(Vector<int> & vect, int start, int finish) {
    for (int i = start; i < finish; i++) {
        int curMinItem = vect[i];
        int curMinIndex = i;
        for (int j = i + 1; j <= finish; j++) {
            if (vect[j] < curMinItem) {
                curMinIndex = j;
                curMinItem = vect[j];
            }
        }
        int tmp = vect[i];
        vect[i] = curMinItem;
        vect[curMinIndex] = tmp;
    }
}



int partitionEx7(Vector<int> & vect, int start, int finish) {
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



void printVectEx7(Vector<int> & vect) {
    for (int tmp : vect) {
        cout << tmp << " ";
    }
    cout << endl;
}

void fillSetEx7(Vector<int> & curSet, int n){
    for (int i = 0; i < n; i++) {
        int randomValue = randomInteger(0,n);
        curSet.add(randomValue);
    }
}
