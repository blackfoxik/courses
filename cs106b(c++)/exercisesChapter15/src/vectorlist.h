#ifndef _vectorlist_h
#define _vectorlist_h


#include <iostream>

#include <sstream>
#include <string>
#include <vector>
#include "compare.h"
#include "error.h"


#include "strlib.h"


template <typename ValueType>
class VectorList {
public:

    VectorList();
    VectorList(int n, ValueType value = ValueType());
    ~VectorList();

    int size() const;
    bool isEmpty() const;
    void clear();
    ValueType get(int index) const;
    void set(int index, ValueType value);
    void insert(int index, const ValueType value);
    void remove(int index);
    void add(ValueType value);



    /*
     * Operator: []
     * Usage: vec[index]
     * -----------------
     * Overloads <code>[]</code> to select elements from this vector.
     * This extension enables the use of traditional array notation to
     * get or set individual elements.  This method signals an error if
     * the index is outside the array range.  The file supports two
     * versions of this operator, one for <code>const</code> vectors and
     * one for mutable vectors.
     */
    ValueType& operator [](int index);
    VectorList(const VectorList<ValueType> &src);
    VectorList<ValueType> & operator=(const VectorList<ValueType> & src);
private:
    struct Cell {
        ValueType data;
        Cell *link;
    };

    /*
     * Implementation notes: Vector data structure
     * -------------------------------------------
     * The elements of the Vector are stored in a dynamic array of
     * the specified element type.  If the space in the array is ever
     * exhausted, the implementation doubles the array capacity.
     */

    /* Instance variables */
    Cell *head;
    Cell *tail;
    int count;

    //ValueType* elements;        /* A dynamic array of the elements   */
    //int capacity;               /* The allocated size of the array   */


    /* Private methods */

    /*
     * Throws an ErrorException if the given index is not within the range of
     * [min..max] inclusive.
     * This is a consolidated error handler for all various Vector members that
     * accept index parameters.
     * The prefix parameter represents a text string to place at the start of
     * the error message, generally to help indicate which member threw the error.
     */
    void deepCopy(const VectorList& src);


};


/* Implementation section */

/*
 * Implementation notes: Vector constructor and destructor
 * -------------------------------------------------------
 * The constructor allocates storage for the dynamic array
 * and initializes the other fields of the object.  The
 * destructor frees the memory used for the array.
 */
template <typename ValueType>
VectorList<ValueType>::VectorList() {
    count = 0;
    head = tail = NULL;
}

template <typename ValueType>
VectorList<ValueType>::VectorList(int n, ValueType value) {
    for (int i = 0; i < n; i++) {
        add(value);
    }
}


/*
 * Implementation notes: copy constructor and assignment operator
 * --------------------------------------------------------------
 * The constructor and assignment operators follow a standard paradigm,
 * as described in the associated textbook.
 */
template <typename ValueType>
VectorList<ValueType>::VectorList(const VectorList& src) {
    deepCopy(src);
}

template <typename ValueType>
VectorList<ValueType>::~VectorList() {
    if (head != NULL) {
        while (true) {
            if (head == tail) {
                delete head;
                break;
            }
            if (head->link == tail) {
                delete head;
                delete tail;
                break;
            }
            Cell *old = head->link;
            delete head;
            head = old;
        }
    }
}

/*
 * Implementation notes: Vector methods
 * ------------------------------------
 * The basic Vector methods are straightforward and should require
 * no detailed documentation.
 */
template <typename ValueType>
void VectorList<ValueType>::add(ValueType value) {
    Cell *cp = new Cell;
    cp->data = value;
    cp->link = NULL;

    if (head == NULL) {
        head = cp;
        tail = cp;
    } else {
        tail->link = cp;
        tail = cp;
    }
    count++;
}



template <typename ValueType>
void VectorList<ValueType>::clear() {
    if (head != NULL) {
        while (true) {
            if (head == tail) {
                delete head;
                break;
            }
            if (head->link == tail) {
                delete head;
                delete tail;
                break;
            }
            Cell *old = head->link;
            delete head;
            head = old;
        }
    }
    head = tail = NULL;
    count  = 0;
}






template <typename ValueType>
ValueType VectorList<ValueType>::get(int index) const {
    if (index >= count) {
       error("Index out of range");
    }
    Cell *cp = head;
    for (int i = 0; i < index; i++ ) {
         cp = cp->link;
    }
    return cp->data;
}

/*
 * Implementation notes: insert, remove, add
 * -----------------------------------------
 * These methods must shift the existing elements in the array to
 * make room for a new element or to close up the space left by a
 * deleted one.
 */
template <typename ValueType>
void VectorList<ValueType>::insert(int index, const ValueType value) {
    if (index >= count) {
       error("Index out of range");
    }
    Cell *cp = head;
    for (int i = 0; i < index; i++ ) {
        cp = head->link;
    }
    Cell *newCell = new Cell;
    newCell->data = value;
    newCell->link = cp->link;
    cp->link = newCell;
    count++;
}

template <typename ValueType>
bool VectorList<ValueType>::isEmpty() const {
    return count == 0;
}


template <typename ValueType>
void VectorList<ValueType>::remove(int index) {
    if (index >= count) {
       error("Index out of range");
    }
    if (index == 0) {
        Cell *oldHead = head;
        head = head->link;
        delete oldHead;
        count--;
        return;
    }

    Cell *cpBefore = head;
    for (int i = 0; i < index - 1; i++ ) {
        cpBefore = head->link;
    }
    Cell *target = cpBefore->link;
    cpBefore->link = target->link;
    delete target;
    count--;
}

template <typename ValueType>
void VectorList<ValueType>::set(int index, const ValueType value) {
    if (index >= count) {
       error("Index out of range");
    }
    if (index == 0) {
        head->data = value;
        return;
    }

    Cell *cp = head;
    for (int i = 0; i < index; i++ ) {
        cp = head->link;
    }
    cp->data = value;
}

template <typename ValueType>
int VectorList<ValueType>::size() const {
    return count;
}




/*
 * Implementation notes: Vector selection
 * --------------------------------------
 * The following code implements traditional array selection using
 * square brackets for the index.
 */
template <typename ValueType>
ValueType& VectorList<ValueType>::operator [](int index) {
    get(index);
}


template <typename ValueType>
VectorList<ValueType> & VectorList<ValueType>::operator =(const VectorList& src) {
    if (this != &src) {
        if (head != NULL) {
            clear();
        }
        deepCopy(src);
    }
    return *this;
}

template <typename ValueType>
void VectorList<ValueType>::deepCopy(const VectorList& src) {
    count = 0;
    for (int i = 0; i < src.count; i++) {
        //Cell *cp = new Cell;
        //cp
        //elements[i] = src.elements[i];
        add(src.get(i));
    }
}



#endif
