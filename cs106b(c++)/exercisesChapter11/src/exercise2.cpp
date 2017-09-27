#include "exercise2.h"
#include <iostream>
#include "console.h"
#include "simpio.h"
#include "grid.h"
#include "vector.h"

using namespace std;

void generateGrayCode(int nBits);
void generateGrayCode(Vector<string> & list, int nBits);
void fillList(Vector<string> & list);
void printList( Vector<string> & list);

void exercise2() {
 int n = getInteger("Input n: ");
 generateGrayCode(n);
}

void generateGrayCode(int nBits) {
    Vector<string> list;
    fillList(list);
    generateGrayCode(list, nBits - 1);
}

void generateGrayCode(Vector<string> & list, int nBits) {
    if (nBits == 0) {
        printList(list);
        return;
    }
    int size = list.size();
    for (int i = size - 1; i >= 0; i--) {
        string revEl = list[i];
        revEl = "1" + revEl;
        list.add(revEl);
        list[i] = "0" + list[i];
    }
    generateGrayCode(list, nBits - 1);
}

void fillList(Vector<string> & list) {
    string el1 = "0";
    string el2 = "1";
    list.add(el1);
    list.add(el2);
}

void printList( Vector<string> & list) {
    for (string curItem : list) {
        cout << curItem << endl;
    }
}



