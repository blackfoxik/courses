#include "console.h"
#include "simpio.h"  // for getLine
#include <iomanip>

#include "setcharvector.h"

using namespace std;



extern void error(std::string msg);



SetCharVector<char>::SetCharVector() {
    items = new bool[256];
    clear();
}


SetCharVector<char>::~SetCharVector() {
    delete[] items;
}


void SetCharVector<char>::add(char value) {
    if (!items[value]) {
        items[value] = true;
        count++;
    }
}





void SetCharVector<char>::clear() {
    for (int i = 0; i < 256; i++) {
        items[i] = false;
    }
    count = 0;
}


bool SetCharVector<char>::contains(const char& value) const {
    return items[value];
}






bool SetCharVector<char>::isEmpty() const {
    return count == 0;
}





void SetCharVector<char>::remove(const char& value) {
    if (items[value]) {
        items[value] = false;
        count--;
    }
}


int SetCharVector<char>::size() const {
    return count;
}









