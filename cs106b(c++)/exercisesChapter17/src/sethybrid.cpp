#include "console.h"
#include "simpio.h"  // for getLine
#include <iomanip>

//#include "sethybrid.h"

using namespace std;



extern void error(std::string msg);


/*
SetHybrid<int>::SetHybrid() {
    items = new bool[256];
    clear();
}


SetHybrid<int>::~SetHybrid() {
    delete[] items;
}


void SetHybrid<int>::add(int value) {
    if (!items[value]) {
        items[value] = true;
        count++;
    }
}





void SetHybrid<int>::clear() {
    for (int i = 0; i < 256; i++) {
        items[i] = false;
    }
    count = 0;
    itemsInMap.clear();
}


bool SetHybrid<int>::contains(const int& value) const {
    return items[value];
}






bool SetHybrid<int>::isEmpty() const {
    return count == 0;
}





void SetHybrid<int>::remove(const int& value) {
    if (items[value]) {
        items[value] = false;
        count--;
    }
}


int SetHybrid<int>::size() const {
    return count;
}


*/






