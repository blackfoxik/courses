#include <string>
//#include <ostream>
#include "stringmapbinsearch.h"
using namespace std;

StringMapBinSearch::StringMapBinSearch() { }

StringMapBinSearch::~StringMapBinSearch() {}

string StringMapBinSearch::get(const string & key) const {
    int index = findKey(key);
    return (index == -1) ? "":bindings.get(index).value;
}

void StringMapBinSearch::printKeys() {
    //use insertion sort because elements was sorted before
    for (int i = 0; i < bindings.size(); i++) {
        std::cout << bindings[i].key << std::endl;
    }
    std::cout << std::endl;
}

void StringMapBinSearch::sortKeys() {
    //use insertion sort because elements was sorted before
    int i = bindings.size() - 1;
    KeyValuePair tmp = bindings[i];
    while (i >= 1 && (tmp.key < bindings[i - 1].key)) {
        bindings[i] = bindings[i - 1];
        i--;
    }
    bindings[i] = tmp;
    printKeys();
}

void StringMapBinSearch::put(const string & key, const string & value) {
    int index = findKey(key);
    bool needToSort = false;
    if (index == -1) {
        KeyValuePair entry;
        entry.key = key;
        index = bindings.size();
        bindings.add(entry);
        needToSort = true;
    }
    bindings[index].value = value;
    if(needToSort) sortKeys();
}

int StringMapBinSearch::findKey(const string & key, int start, int finish) const {

    if (start > finish) return -1;
    int mid = (finish + start) / 2;
    if (bindings[mid].key < key) {
        return findKey(key, mid + 1, finish);
    } else if (bindings[mid].key > key) {
        return findKey(key, start, mid - 1);
    } else if (bindings[mid].key == key) {
        return mid;
    } else {
        return -1;
    }
}

int StringMapBinSearch::findKey(const string & key) const {

    //for (int i = 0; i < bindings.size(); i++) {
    //    if (bindings.get(i).key == key) return i;
    //}
    if (bindings.size() == 0) return -1;
    return findKey(key, 0, bindings.size() - 1);
    //return -1;
}




