#include "console.h"
#include "simpio.h"  // for getLine
#include <iomanip>
#include "set.h"
#include "grid.h"
#include "exercise6.h"
using namespace std;



//func prototypes
void printVectEx6(Vector<int> & vect);
int partition(Vector<int> & vect, int start, int finish);
void quickSortOriginal(Vector<int> & vect, int start, int finish);

//median first
void quickSortMedianFirst(Vector<int> & vect, int start, int finish);
int partitionMedianFirst(Vector<int> & vect, int start, int finish, int & pivot);
int getMedianFirstPivot(Vector<int> & vect, int start, int finish);
// middle
void quickSortMiddle(Vector<int> & vect, int start, int finish);
int partitionMiddle(Vector<int> & vect, int start, int finish, int & pivot);
int getMiddlePivot(Vector<int> & vect, int start, int finish);
int getIndexMiddlePivot(int start, int finish);
//last
void quickSortLast(Vector<int> & vect, int start, int finish);
int partitionLast(Vector<int> & vect, int start, int finish);
//int getLastPivot(Vector<int> & vect, int start, int finish);

void exercise6() {
    //Vector<int> vect {56,25,37,58,95,19,73,30};
    Vector<int> vect {56,25,37,58,95,19,73,30,22,5,78,33,55,76,90,21,33,54,99,100,11,27,43,67,9};
    //Vector<int> vect {56,25,37,58,95,19,73,30,22,5};
    printVectEx6(vect);
    //quickSortOriginal(vect, 0, vect.size() - 1);
    //quickSortMedianFirst(vect, 0, vect.size() - 1);
    //quickSortMiddle(vect, 0, vect.size() - 1);
    quickSortLast(vect, 0, vect.size() - 1);
    printVectEx6(vect);
}

void quickSortLast(Vector<int> & vect, int start, int finish) {
    printVectEx6(vect);
    if (start >= finish) return;
    int boundary = partitionLast(vect, start, finish);
    quickSortLast(vect, start, boundary);
    quickSortLast(vect, boundary + 1, finish);
}

int partitionLast(Vector<int> & vect, int start, int finish) {
    int pivot = vect[finish];
    int lh = start;
    int rh = finish - 1;
    while (true) {
        while (lh < rh && vect[rh] >= pivot) rh--;
        while (lh < rh && vect[lh] < pivot) lh++;
        if (lh == rh) break;
        int tmp = vect[lh];
        vect[lh] = vect[rh];
        vect[rh] = tmp;
    }
    if (vect[lh] > pivot) {
        int tmp = vect[lh];
        vect[lh] = pivot;
        vect[finish] = tmp;
        return lh;
    }
    return lh;
}

void quickSortMiddle(Vector<int> & vect, int start, int finish) {
    //printVectEx6(vect);
    if (start >= finish) return;
    int curPivot;
    int boundary = partitionMiddle(vect, start, finish, curPivot);
    if (curPivot >= vect[boundary]) {
        quickSortMiddle(vect, start, boundary);
        quickSortMiddle(vect, boundary + 1, finish);
    } else {
        quickSortMiddle(vect, start, boundary - 1);
        quickSortMiddle(vect, boundary, finish);
    }
}

int getIndexMiddlePivot(int start, int finish) {
    int size = (finish - start) + 1;
    int curPivotIndex;
    if (size % 2 == 0) {
        curPivotIndex = start + (size / 2 - 1);
    } else {
        curPivotIndex = start + ((size - 2) / 2 + 1);
    }
    return curPivotIndex;
}

int partitionMiddle(Vector<int> & vect, int start, int finish, int & pivot) {
    pivot = getMiddlePivot(vect, start, finish);
    int lh = start;
    int rh = finish;
    while (true) {
        while (lh < rh && vect[rh] >= pivot) rh--;
        while (lh < rh && vect[lh] < pivot) lh++;
        if (lh == rh) break;
        int tmp = vect[lh];
        vect[lh] = vect[rh];
        vect[rh] = tmp;
    }
    if (pivot < vect[lh]) {
       int pivotIndex = getIndexMiddlePivot(start, finish);
       int tmp = vect[lh];
       vect[lh] = pivot;
       vect[pivotIndex] = tmp;
       pivot = tmp;
    }

    return lh;
}

int getMiddlePivot(Vector<int> & vect, int start, int finish) {
    int curPivotIndex = getIndexMiddlePivot(start, finish);
    return vect[curPivotIndex];
}

void quickSortMedianFirst(Vector<int> & vect, int start, int finish) {
    if (start >= finish) return;
    int curPivot;
    int boundary = partitionMedianFirst(vect, start, finish, curPivot);
    if (curPivot >= vect[boundary]) {
        quickSortMedianFirst(vect, start, boundary);
        quickSortMedianFirst(vect, boundary + 1, finish);
    } else {
        quickSortMedianFirst(vect, start, boundary - 1);
        quickSortMedianFirst(vect, boundary, finish);
    }

}

int getMedianFirstPivot(Vector<int> & vect, int start, int finish) {
    //consider first 10 % of vector size
    int size = finish - start;
    int count = size / 10;
    if (count <= 1) return vect[start];
    int sum = 0;
    for (int i = 0; i < count; i++) {
       sum += vect[start + i];
    }
    return sum / count;
}

int partitionMedianFirst(Vector<int> & vect, int start, int finish, int & pivot) {
    pivot = getMedianFirstPivot(vect, start, finish);
    int lh = start;
    int rh = finish;
    while (true) {
        while (lh < rh && vect[rh] >= pivot) rh--;
        while (lh < rh && vect[lh] < pivot) lh++;
        if (lh == rh) break;
        int tmp = vect[lh];
        vect[lh] = vect[rh];
        vect[rh] = tmp;
    }
    //if (vect[lh] >= pivot) return lh;
    //vect[start] = vect[lh];
    //vect[lh] = pivot;
    return lh;
}

int partition(Vector<int> & vect, int start, int finish) {
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

void quickSortOriginal(Vector<int> & vect, int start, int finish) {
    if (start >= finish) return;
    int boundary = partition(vect, start, finish);
    quickSortOriginal(vect, start, boundary - 1);
    quickSortOriginal(vect, boundary + 1, finish);
}

void printVectEx6(Vector<int> & vect) {
    for (int tmp : vect) {
        cout << tmp << " ";
    }
    cout << endl;
}
