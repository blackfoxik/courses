#include "console.h"
#include "simpio.h"  // for getLine
#include <iomanip>
#include "exercise8.h"
#include "pqueue.h"


void exercise8() {
/*#include "hashcode.h"

static const int HASH_SEED = 5381;               // Starting point for first cycle
static const int HASH_MULTIPLIER = 33;           // Multiplier for each cycle
static const int HASH_MASK = unsigned(-1) >> 1;  // All 1 bits except the sign

int hashSeed() {
    return HASH_SEED;
}

int hashMultiplier() {
    return HASH_MULTIPLIER;
}

int hashMask() {
    return HASH_MASK;
}



int hashCode(bool key) {
    return (int) key;
}

int hashCode(char key) {
    return key;
}

int hashCode(double key) {
    char* byte = (char*) &key;
    unsigned hash = HASH_SEED;
    for (int i = 0; i < (int) sizeof(double); i++) {
        hash = HASH_MULTIPLIER * hash + (int) *byte++;
    }
    return hash & HASH_MASK;
}

int hashCode(float key) {
    char* byte = (char*) &key;
    unsigned hash = HASH_SEED;
    for (int i = 0; i < (int) sizeof(float); i++) {
        hash = HASH_MULTIPLIER * hash + (int) *byte++;
    }
    return hash & HASH_MASK;
}

int hashCode(int key) {
    return key & HASH_MASK;
}

int hashCode(long key) {
    return int(key) & HASH_MASK;
}

int hashCode(const char* str) {
    unsigned hash = HASH_SEED;
    for (int i = 0; str && str[i] != 0; i++) {
        hash = HASH_MULTIPLIER * hash + str[i];
    }
    return int(hash & HASH_MASK);
}

int hashCode(const std::string& str) {
    unsigned hash = HASH_SEED;
    int n = str.length();
    for (int i = 0; i < n; i++) {
        hash = HASH_MULTIPLIER * hash + str[i];
    }
    return int(hash & HASH_MASK);
}

int hashCode(void* key) {
    return hashCode(reinterpret_cast<long>(key));
}*/
}

