#include <string>
//#include <ostream>
#include "stringmapdynamicarrayEx3.h"
using namespace std;

StringMapDynamicArrayEx3::StringMapDynamicArrayEx3() {
    count = 0;
    //start = NULL;
    bindings = new KeyValuePair[DEFAULT_CAPACITY];
    capacity = DEFAULT_CAPACITY;
}

StringMapDynamicArrayEx3::~StringMapDynamicArrayEx3() {
    delete[] bindings;
}

string StringMapDynamicArrayEx3::get(const string & key) const {
    int index = findKey(key);
    return (index == -1) ? "":bindings[index].value;
}

void StringMapDynamicArrayEx3::put(const string & key, const string & value) {
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

int StringMapDynamicArrayEx3::findKey(const string & key) const {
    for (int i = 0; i < count; i++) {
        if (bindings[i].key == key) return i;
    }
    return -1;
}

void StringMapDynamicArrayEx3::expandCapacity() {
    capacity = capacity * 2;
    KeyValuePair *newArray = new KeyValuePair[capacity];
    for (int i = 0; i < count; i++) {
        newArray[i] = bindings[i];
    }
    delete[] bindings;
    bindings = newArray;
}

int StringMapDynamicArrayEx3::size() {
    return count;
}

bool StringMapDynamicArrayEx3::containsKey(const std::string & key) {
    return (findKey(key) != -1) ? true : false;
}

void StringMapDynamicArrayEx3::clear() {
   KeyValuePair *newArray = new KeyValuePair[capacity];
   delete[] bindings;
   bindings = newArray;
   count = 0;
}

bool StringMapDynamicArrayEx3::isEmpty() {
    return count == 0;
}


