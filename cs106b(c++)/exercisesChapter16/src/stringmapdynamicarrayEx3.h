// This header file doesn't do much, but it's good to demonstrate that it's
// possible to create and edit header files
#ifndef _stringmapdynamicarrayEx3_h
#define _stringmapdynamicarrayEx3_h
#include <string>
#include "vector.h"

class StringMapDynamicArrayEx3 {
public:
    StringMapDynamicArrayEx3();
    ~StringMapDynamicArrayEx3();
    std::string get(const std::string & key) const;
    void put(const std::string & key, const std::string & value);
    int size();
    bool containsKey(const std::string & key);
    void clear();
    bool isEmpty();

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
