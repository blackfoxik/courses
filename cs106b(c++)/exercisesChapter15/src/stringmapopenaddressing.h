// This header file doesn't do much, but it's good to demonstrate that it's
// possible to create and edit header files
#ifndef _stringmapopenaddressing_h
#define _stringmapopenaddressing_h
#include <string>
#include "vector.h"

class StringMapOpenAddressing {
public:
    StringMapOpenAddressing();
    ~StringMapOpenAddressing();
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
    const int INITIAL_CAPACITY = 10;
};

#endif
