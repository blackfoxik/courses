#ifndef _setmapcharvector_h
#define _setmapcharvector_h

#include <iostream>
#include <set>
#include "compare.h"
#include "error.h"
#include "map.h"
#include "vector.h"


template <typename T>
class SetCharVector
{
    //SetCharVector();
};

template <>
class SetCharVector<char> {
public:
    /*
     * Constructor: Set
     * Usage: Set<ValueType> set;
     * --------------------------
     * Initializes an empty set of the specified element type.
     */
    SetCharVector();

   ~SetCharVector();
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
    void add(char value);

    /*
     * Method: remove
     * Usage: set.remove(value);
     * -------------------------
     * Removes an element from this set.  If the value was not
     * contained in the set, no error is generated and the set
     * remains unchanged.
     */
    void remove(const char& value);

    /*
     * Method: contains
     * Usage: if (set.contains(value)) ...
     * -----------------------------------
     * Returns <code>true</code> if the specified value is in this set.
     */
    bool contains(const char & value) const;

    /*
     * Method: clear
     * Usage: set.clear();
     * -------------------
     * Removes all elements from this set.
     */
    void clear();
    bool isSubsetOf(const SetCharVector& set2) const;


private:
    bool *items;
    int count;
};



/*
SetCharVector<char>::SetCharVector() {
    items = new bool[256];
    clear();
}


SetCharVector<char>::~SetCharVector() {
    delete[] items;
}


void SetCharVector<char>::add(char value) {
    if (!items[value]) {
        items[value] = true;
        count++;
    }
}





void SetCharVector<char>::clear() {
    for (int i = 0; i < 256; i++) {
        items[i] = false;
    }
    count = 0;
}


bool SetCharVector<char>::contains(const char& value) const {
    return items[value];
}








bool SetCharVector<char>::isEmpty() const {
    return count == 0;
}






void SetCharVector<char>::remove(const char& value) {
    if (items[value]) {
        items[value] = false;
        count--;
    }
}



int SetCharVector<char>::size() const {
    return count;
}



*/

#endif
