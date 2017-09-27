#include <string>
//#include <ostream>
#include "stringmapdynamicarray.h"
using namespace std;

StringMapDynamicArray::StringMapDynamicArray() {
    count = 0;
    //start = NULL;
    bindings = new KeyValuePair[DEFAULT_CAPACITY];
    capacity = DEFAULT_CAPACITY;
}

StringMapDynamicArray::~StringMapDynamicArray() {
    delete[] bindings;
}

string StringMapDynamicArray::get(const string & key) const {
    int index = findKey(key);
    return (index == -1) ? "":bindings[index].value;
}

void StringMapDynamicArray::put(const string & key, const string & value) {
    int index = findKey(key);
    if (index == -1) {
        if (count == capacity - 1) expandCapacity();
        KeyValuePair entry;
        entry.key = key;
        index = count;
        bindings[count] = entry;
        count++;
    }
    bindings[index].value = value;
}

int StringMapDynamicArray::findKey(const string & key) const {
    for (int i = 0; i < count; i++) {
        if (bindings[i].key == key) return i;
    }
    return -1;
}

void StringMapDynamicArray::expandCapacity() {
    capacity = capacity * 2;
    KeyValuePair *newArray = new KeyValuePair[capacity];
    for (int i = 0; i < count; i++) {
        newArray[i] = bindings[i];
    }
    delete[] bindings;
    bindings = newArray;
}



