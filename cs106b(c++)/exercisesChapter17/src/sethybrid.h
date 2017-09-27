#ifndef _setinthybrid_h
#define _setinthybrid_h

#include <iostream>
#include <set>
#include "compare.h"
#include "error.h"
#include "map.h"
#include "vector.h"
//#include "mapBucketsExpandDynamically.h"

const int TOP = 256;
template <typename T>
class SetHybrid
{
    //SetIntHybrid();
};

template <>
class SetHybrid<int> {
public:
    /*
     * Constructor: Set
     * Usage: Set<ValueType> set;
     * --------------------------
     * Initializes an empty set of the specified element type.
     */
    SetHybrid();

   ~SetHybrid();
    /*
     * Method: size
     * Usage: count = set.size();
     * --------------------------
     * Returns the number of elements in this set.
     */
    int size() const;


    /*
     * Method: isEmpty
     * Usage: if (set.isEmpty()) ...
     * -----------------------------
     * Returns <code>true</code> if this set contains no elements.
     */
    bool isEmpty() const;

    /*
     * Method: add
     * Usage: set.add(value);
     * ----------------------
     * Adds an element to this set, if it was not already there.  For
     * compatibility with the STL <code>set</code> class, this method
     * is also exported as <code>insert</code>.
     */
    void add(int value);

    /*
     * Method: remove
     * Usage: set.remove(value);
     * -------------------------
     * Removes an element from this set.  If the value was not
     * contained in the set, no error is generated and the set
     * remains unchanged.
     */
    void remove(const int& value);

    /*
     * Method: contains
     * Usage: if (set.contains(value)) ...
     * -----------------------------------
     * Returns <code>true</code> if the specified value is in this set.
     */
    bool contains(const int & value) const;

    /*
     * Method: clear
     * Usage: set.clear();
     * -------------------
     * Removes all elements from this set.
     */
    void clear();
    bool isSubsetOf(const SetHybrid& set2) const;


private:
    bool *items;
    Map<int,bool> *itemsInMap;
    int count;
};

SetHybrid<int>::SetHybrid() {
    items = new bool[256];
    itemsInMap = new Map<int,bool>;
    clear();
}


SetHybrid<int>::~SetHybrid() {
    //delete[] items;
}


void SetHybrid<int>::add(int value) {
   if(value < TOP) {
    if (!items[value]) {
        items[value] = true;
        count++;
    }
    return;
   }
   if(!itemsInMap->containsKey(value)) {
      itemsInMap->add(value,true);
      count++;
   }
}





void SetHybrid<int>::clear() {
    for (int i = 0; i < 256; i++) {
        items[i] = false;
    }

    itemsInMap->clear();
    count = 0;
}


bool SetHybrid<int>::contains(const int& value) const {
    if(value < TOP) {
     return items[value];
    }
    return itemsInMap->containsKey(value);
}






bool SetHybrid<int>::isEmpty() const {
    return count == 0;
}





void SetHybrid<int>::remove(const int& value) {
   if(value < TOP) {
    if (items[value]) {
        items[value] = false;
        count--;
    }
    return;
   }
   if (itemsInMap->containsKey(value)) {
      itemsInMap->remove(value);
      count--;
   }
}


int SetHybrid<int>::size() const {
    return count;
}

#endif
