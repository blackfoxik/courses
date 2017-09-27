// This header file doesn't do much, but it's good to demonstrate that it's
// possible to create and edit header files
#ifndef _stringmapdynamicarray_h
#define _stringmapdynamicarray_h
#include <string>
#include "vector.h"

class StringMapDynamicArray {
public:
    StringMapDynamicArray();
    ~StringMapDynamicArray();
    std::string get(const std::string & key) const;
    void put(const std::string & key, const std::string & value);


private:
    const int DEFAULT_CAPACITY = 3;
    struct KeyValuePair {
        std::string key;
        std::string value;
    };
    KeyValuePair *bindings;
    int capacity;
    //KeyValuePair start;
    int count;
    int findKey(const std::string & key) const;
    void expandCapacity();
};

#endif
