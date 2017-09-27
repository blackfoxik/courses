// This header file doesn't do much, but it's good to demonstrate that it's
// possible to create and edit header files
#ifndef _stringmapopenaddressingda_h
#define _stringmapopenaddressingda_h
#include <string>
#include "vector.h"

class StringMapOpenAddressingDA {
public:
    StringMapOpenAddressingDA();
    ~StringMapOpenAddressingDA();
    std::string get(const std::string & key) const;
    void put(const std::string & key, const std::string & value);


private:
    struct KeyValuePair {
        std::string key;
        std::string value;
    };
    KeyValuePair *bindings;
    int findKey(const std::string & key) const;
    int capacity;
    int nPairs;
    const int INITIAL_CAPACITY = 2;
    double loadFactor;
    void rehash();
};

#endif
