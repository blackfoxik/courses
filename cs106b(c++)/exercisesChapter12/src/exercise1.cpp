#include "exercise1.h"
#include <iostream>
#include "console.h"
#include "simpio.h"
using namespace std;

//func prototypes
void printArray(int *ar, int size);
int * createIndexArray(int n);

void exercise1() {
 int n = getInteger("input n: ");
 int *array = createIndexArray(n);
 printArray(array, n);
 delete[] array;
}

int * createIndexArray(int n) {
   int *ar = new int[n];
   for (int i = 0; i < n; i++) {
       ar[i] = i;
   }
   return ar;
}

void printArray(int *ar, int size) {
    for (int i = 0; i < size; i++) {
        cout << ar[i] << endl;
    }
    cout << endl;
}
