#include <string>
//#include <ostream>
#include "stringmapopenaddressing.h"
#include "hashcode.h"
using namespace std;

StringMapOpenAddressing::StringMapOpenAddressing() {
    bindings = new KeyValuePair[INITIAL_CAPACITY];
    capacity = INITIAL_CAPACITY;
    nPairs = 0;
    for (int i = 0; i < capacity; i++) {
        bindings[i].key = "";
    }
}

StringMapOpenAddressing::~StringMapOpenAddressing() {}

string StringMapOpenAddressing::get(const string & key) const {
    int index = findKey(key);
    return (index == -1) ? "":bindings[index].value;
}

void StringMapOpenAddressing::put(const string & key, const string & value) {
    int bucket = hashCode(key) % capacity;
    if (bindings[bucket].key == "") {
        KeyValuePair entry;
        entry.key = key;
        entry.value = value;
        bindings[bucket] = entry;
        nPairs++;
        return;
    } else if (bindings[bucket].key == key) {
        bindings[bucket].value = value;
        return;
    } else {
        //try to find room
        for (int i = 1; i <= 3; i++) {
            int index = (bucket + i) % capacity;
            if (bindings[index].key != "" || bindings[index].key != key) {
                continue;
            } else if (bindings[index].key == key) {
               bindings[bucket].value = value;
               return;
            } else if (bindings[index].key == "") {
                KeyValuePair entry;
                entry.key = key;
                entry.value = value;
                bindings[bucket] = entry;
                nPairs++;
                return;
            }
        }
    }
    error("Array is full");
   /* int index = findKey(key);
    if (index == -1) {
        KeyValuePair entry;
        entry.key = key;
        index = bindings.size();
        bindings.add(entry);
        nPairs++;
    }
    bindings[index].value = value;*/
}

int StringMapOpenAddressing::findKey(const string & key) const {
    for (int i = 0; i < capacity; i++) {
        if (bindings[i].key == key) return i;
    }
    return -1;
}


//int capacity;
//int nPairs;
//const int INITIAL_CAPACITY;



