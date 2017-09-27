#include <string>
//#include <ostream>
#include "stringmapBucketsExpandDynamically.h"
#include "hashcode.h"
using namespace std;

static const double REHASH_THRESHOLD = 0.7;

StringMapBucketsExpandDynamically::StringMapBucketsExpandDynamically() {
    loadFactor = 0;
    nCells = 0;
    nBuckets = INITIAL_BUCKET_COUNT;
    buckets = new Cell*[nBuckets];
    for (int i = 0; i < nBuckets; i++) {
        buckets[i] = NULL;
    }
}

StringMapBucketsExpandDynamically::~StringMapBucketsExpandDynamically() {
    for (int i = 0; i < nBuckets; i++) {
        Cell *cp = buckets[i];
        while (cp != NULL) {
            Cell *oldCell = cp;
            cp = cp->link;
            delete oldCell;
        }
    }
}

string StringMapBucketsExpandDynamically::get(const string & key) const {
    int bucket = hashCode(key) % nBuckets;
    Cell *cp = findCell(bucket, key);
    return (cp ==NULL) ? "" : cp->value;
}

void StringMapBucketsExpandDynamically::put(const string & key, const string & value) {
    int hashC = hashCode(key);
    int bucket = hashCode(key) % nBuckets;
    Cell *cp = findCell(bucket, key);
    if (cp == NULL) {

        loadFactor = double(nCells) / double(nBuckets);
        if (loadFactor > REHASH_THRESHOLD) {
            rehash();
            bucket = hashCode(key) % nBuckets;
        }
        cp = new Cell;
        cp->key = key;
        cp->link = buckets[bucket];
        buckets[bucket] = cp;
        nCells++;
    }
    cp->value = value;
}

StringMapBucketsExpandDynamically::Cell *StringMapBucketsExpandDynamically::findCell(int bucket, const std::string & key) const {
    Cell *cp = buckets[bucket];
    while (cp != NULL && key != cp->key) {
        cp = cp->link;
    }
    return cp;
}

void StringMapBucketsExpandDynamically::rehash() {
    int newNBuckets = nBuckets * 2;
    Cell **newBuckets = new Cell*[newNBuckets];
    for (int i = 0; i < newNBuckets; i++) {
        newBuckets[i] = NULL;
    }
    for (int i = 0; i < nBuckets; i++) {
        Cell *cp = buckets[i];
        while (cp != NULL) {
           int newNbucket = hashCode(cp->key) % newNBuckets;
           Cell *newCell = new Cell;
           newCell->key = cp->key;
           newCell->value = cp->value;
           newCell->link = newBuckets[newNbucket];
           newBuckets[newNbucket] = newCell;
           Cell *old = cp;
           cp = cp->link;
           delete old;
        }
    }
    nBuckets = newNBuckets;
    delete[] buckets;
    buckets = newBuckets;
    loadFactor = double(nCells) / double(nBuckets);
}

/*const int HASH_SEED = 5381;
const int HASH_MULTIPLIER = 33;
const int HASH_MASK = unsigned(-1) >> 1;

int hashCode(const string &str) {
    unsigned hash = HASH_SEED;
    int n = str.length();
    for (int i = 0 ; i < n; i++) {
        hash = HASH_MULTIPLIER * hash + str[i];
    }
    return int(hash & HASH_MASK);
}*/



