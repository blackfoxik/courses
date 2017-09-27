#include <string>
//#include <ostream>
#include "stringmap.h"
using namespace std;

StringMap::StringMap() { }

StringMap::~StringMap() {}

string StringMap::get(const string & key) const {
    int index = findKey(key);
    return (index == -1) ? "":bindings.get(index).value;
}

void StringMap::put(const string & key, const string & value) {
    int index = findKey(key);
    if (index == -1) {
        KeyValuePair entry;
        entry.key = key;
        index = bindings.size();
        bindings.add(entry);
    }
    bindings[index].value = value;
}

int StringMap::findKey(const string & key) const {
    for (int i = 0; i < bindings.size(); i++) {
        if (bindings.get(i).key == key) return i;
    }
    return -1;
}




