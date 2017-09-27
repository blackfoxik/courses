#include <string>
//#include <ostream>
#include "stringmapopenaddressingda.h"
#include "hashcode.h"
using namespace std;

static const double REHASH_THRESHOLD = 0.7;

StringMapOpenAddressingDA::StringMapOpenAddressingDA() {
    bindings = new KeyValuePair[INITIAL_CAPACITY];
    capacity = INITIAL_CAPACITY;
    nPairs = 0;
    for (int i = 0; i < capacity; i++) {
        bindings[i].key = "";
    }
}

StringMapOpenAddressingDA::~StringMapOpenAddressingDA() {}

string StringMapOpenAddressingDA::get(const string & key) const {
    int index = findKey(key);
    return (index == -1) ? "":bindings[index].value;
}

void StringMapOpenAddressingDA::put(const string & key, const string & value) {
    int bucket = hashCode(key) % capacity;
    if (bindings[bucket].key == "") {

        loadFactor = double(nPairs) / double(capacity);
        if (loadFactor > REHASH_THRESHOLD) {
            rehash();
            bucket = hashCode(key) % capacity;
        }
        KeyValuePair entry;
        entry.key = key;
        entry.value = value;
        bindings[bucket] = entry;
        nPairs++;
        loadFactor = double(nPairs) / double(capacity);
        return;
    } else if (bindings[bucket].key == key) {
        bindings[bucket].value = value;
        return;
    } else {
        //loadFactor = double(nPairs) / double(capacity);
        if (loadFactor > REHASH_THRESHOLD) {
            rehash();
            bucket = hashCode(key) % capacity;
        }
        //try to find room
        int index = bucket;
        int i = 0;
        while (bindings[index].key != "") {
            i++;
            index = (bucket + i) % capacity;
            string s = bindings[index].key;
            if (bindings[index].key == key) break;
            if (i > capacity && bindings[index].key == "") break;
        }
            if (bindings[index].key == key) {
               bindings[bucket].value = value;
               return;
            } else if (bindings[index].key == "") {
                loadFactor = double(nPairs) / double(capacity);
                if (loadFactor > REHASH_THRESHOLD) {
                    rehash();
                    bucket = hashCode(key) % capacity;
                }
                KeyValuePair entry;
                entry.key = key;
                entry.value = value;
                bindings[index] = entry;
                nPairs++;
                loadFactor = double(nPairs) / double(capacity);
                return;
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

int StringMapOpenAddressingDA::findKey(const string & key) const {
    for (int i = 0; i < capacity; i++) {
        if (bindings[i].key == key) return i;
    }
    return -1;
}

void StringMapOpenAddressingDA::rehash() {
    int newCapacity = capacity * 2;
    KeyValuePair *newBindings = new KeyValuePair[newCapacity];
    for (int i = 0; i < newCapacity; i++) {
        newBindings[i].key = "";
    }
    for (int i = 0; i < capacity; i++) {
        KeyValuePair cp = bindings[i];
        if (cp.key != "") {
           int newNbucket = hashCode(cp.key) % newCapacity;
           KeyValuePair newCell;
           newCell.key = cp.key;
           newCell.value = cp.value;
           int i = 0;
           int index = newNbucket;
           while (newBindings[index].key != "") {
               i++;
               index = (index + i) % newCapacity;
           }
           newBindings[index] = newCell;
           //KeyValuePair *old = cp;
           //cp = cp->link;
           //delete old;
        }
    }
    capacity = newCapacity;
    delete[] bindings;
    bindings = newBindings;
    loadFactor = double(nPairs) / double(capacity);
}

//int capacity;
//int nPairs;
//const int INITIAL_CAPACITY;



