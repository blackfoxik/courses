#ifndef _vectorarray_h
#define _vectorarray_h

#include <initializer_list>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>
#include "compare.h"
#include "error.h"
#include "hashcode.h"
#include "random.h"
#include "strlib.h"

/*
 * Class: Vector<ValueType>
 * ------------------------
 * This class stores an ordered list of values similar to an array.
 * It supports traditional array selection using square brackets, but
 * also supports inserting and deleting elements.  It is similar in
 * function to the STL <code>vector</code> type, but is simpler both
 * to use and to implement.
 */
template <typename ValueType>
class VectorArray {
public:
    /*
     * Constructor: Vector
     * Usage: Vector<ValueType> vec;
     *        Vector<ValueType> vec(n, value);
     * ---------------------------------------
     * Initializes a new vector.  The default constructor creates an
     * empty vector.  The second form creates an array with <code>n</code>
     * elements, each of which is initialized to <code>value</code>;
     * if <code>value</code> is missing, the elements are initialized
     * to the default value for the type.
     */
    VectorArray();
    explicit VectorArray(int n, ValueType value = ValueType());

    /*
     * This constructor copies an STL vector.
     */
    /* implicit */ VectorArray(const std::vector<ValueType>& v);



    /*
     * Destructor: ~Vector
     * -------------------
     * Frees any heap storage allocated by this vector.
     */
    virtual ~VectorArray();

    /*
     * Method: add
     * Usage: vec.add(value);
     * ----------------------
     * Adds a new value to the end of this vector.
     */
    void add(const ValueType& value);



    /*
     * Method: clear
     * Usage: vec.clear();
     * -------------------
     * Removes all elements from this vector.
     */
    void clear();



    /*
     * Method: equals
     * Usage: if (vec.equals(v2)) ...
     * ------------------------------
     * Compares two vectors for equality.
     * Returns <code>true</code> if this vector contains exactly the same
     * values as the given other vector.
     * Identical in behavior to the == operator.
     */
    bool equals(const VectorArray<ValueType>& v) const;

    /*
     * Method: get
     * Usage: ValueType val = vec.get(index);
     * --------------------------------------
     * Returns the element at the specified index in this vector.  This
     * method signals an error if the index is not in the array range.
     */
    const ValueType& get(int index) const;

    /*
     * Method: insert
     * Usage: vec.insert(0, value);
     * ----------------------------
     * Inserts the element into this vector before the specified index.
     * All subsequent elements are shifted one position to the right.  This
     * method signals an error if the index is outside the range from 0
     * up to and including the length of the vector.
     */
    void insert(int index, const ValueType& value);

    /*
     * Method: isEmpty
     * Usage: if (vec.isEmpty()) ...
     * -----------------------------
     * Returns <code>true</code> if this vector contains no elements.
     */
    bool isEmpty() const;







    /*
     * Method: remove
     * Usage: vec.remove(index);
     * -------------------------
     * Removes the element at the specified index from this vector.
     * All subsequent elements are shifted one position to the left.  This
     * method signals an error if the index is outside the array range.
     */
    void remove(int index);

    /*
     * Method: set
     * Usage: vec.set(index, value);
     * -----------------------------
     * Replaces the element at the specified index in this vector with
     * a new value.  The previous value at that index is overwritten.
     * This method signals an error if the index is not in the array range.
     */
    void set(int index, const ValueType& value);

    /*
     * Method: size
     * Usage: int nElems = vec.size();
     * -------------------------------
     * Returns the number of elements in this vector.
     */
    int size() const;



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
    const ValueType& operator [](int index) const;

    /*
     * Operator: +
     * Usage: v1 + v2
     * --------------
     * Concatenates two vectors, or concatenates this vector with an
     * initializer list such as {1, 2, 3}.
     */



    /*
     * Additional Vector operations
     * ----------------------------
     * In addition to the methods listed in this interface, the Vector
     * class supports the following operations:
     *
     *   - Stream I/O using the << and >> operators
     *   - Deep copying for the copy constructor and assignment operator
     *   - Iteration using the range-based for statement or STL iterators
     *
     * The iteration forms process the Vector in index order.
     */

    /* Private section */

    /**********************************************************************/
    /* Note: Everything below this point in the file is logically part    */
    /* of the implementation and should not be of interest to clients.    */
    /**********************************************************************/

private:
    /*
     * Implementation notes: Vector data structure
     * -------------------------------------------
     * The elements of the Vector are stored in a dynamic array of
     * the specified element type.  If the space in the array is ever
     * exhausted, the implementation doubles the array capacity.
     */

    /* Instance variables */
    ValueType* elements;        /* A dynamic array of the elements   */
    int capacity;               /* The allocated size of the array   */
    int count;                  /* The number of elements in use     */

    /* Private methods */

    /*
     * Throws an ErrorException if the given index is not within the range of
     * [min..max] inclusive.
     * This is a consolidated error handler for all various Vector members that
     * accept index parameters.
     * The prefix parameter represents a text string to place at the start of
     * the error message, generally to help indicate which member threw the error.
     */
    void checkIndex(int index, int min, int max, std::string prefix) const;

    void expandCapacity();
    void deepCopy(const VectorArray& src);

    /*
     * Hidden features
     * ---------------
     * The remainder of this file consists of the code required to
     * support deep copying and iteration.  Including these methods
     * in the public interface would make that interface more
     * difficult to understand for the average client.
     */

public:
    /*
     * Deep copying support
     * --------------------
     * This copy constructor and operator= are defined to make a deep copy,
     * making it possible to pass or return vectors by value and assign
     * from one vector to another.
     */
    VectorArray(const VectorArray& src);
    VectorArray& operator =(const VectorArray& src);

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
VectorArray<ValueType>::VectorArray() {
    count = capacity = 0;
    elements = NULL;
}

template <typename ValueType>
VectorArray<ValueType>::VectorArray(int n, ValueType value) {
    count = capacity = n;
    elements = (n == 0) ? NULL : new ValueType[n];
    for (int i = 0; i < n; i++) {
        elements[i] = value;
    }
}





/*
 * Implementation notes: copy constructor and assignment operator
 * --------------------------------------------------------------
 * The constructor and assignment operators follow a standard paradigm,
 * as described in the associated textbook.
 */
template <typename ValueType>
VectorArray<ValueType>::VectorArray(const VectorArray& src) {
    deepCopy(src);
}

template <typename ValueType>
VectorArray<ValueType>::~VectorArray() {
    if (elements != NULL) {
        delete[] elements;
        elements = NULL;
    }
}

/*
 * Implementation notes: Vector methods
 * ------------------------------------
 * The basic Vector methods are straightforward and should require
 * no detailed documentation.
 */
template <typename ValueType>
void VectorArray<ValueType>::add(const ValueType& value) {
    insert(count, value);
}


template <typename ValueType>
void VectorArray<ValueType>::clear() {
    if (elements != NULL) {
        delete[] elements;
    }
    count = capacity = 0;
    elements = NULL;
}




/*
 * Implementation notes: expandCapacity
 * ------------------------------------
 * This function doubles the array capacity, copies the old elements
 * into the new array, and then frees the old one.
 * See also: ensureCapacity
 */
template <typename ValueType>
void VectorArray<ValueType>::expandCapacity() {
    capacity = std::max(1, capacity * 2);
    ValueType *array = new ValueType[capacity];
    if (elements != NULL) {
        for (int i = 0; i < count; i++) {
            array[i] = elements[i];
        }
        delete[] elements;
    }
    elements = array;
}

template <typename ValueType>
const ValueType& VectorArray<ValueType>::get(int index) const {
    checkIndex(index, 0, count-1, "get");
    return elements[index];
}

/*
 * Implementation notes: insert, remove, add
 * -----------------------------------------
 * These methods must shift the existing elements in the array to
 * make room for a new element or to close up the space left by a
 * deleted one.
 */
template <typename ValueType>
void VectorArray<ValueType>::insert(int index, const ValueType& value) {
    checkIndex(index, 0, count, "insert");
    if (count == capacity) {
        expandCapacity();
    }
    for (int i = count; i > index; i--) {
        elements[i] = elements[i - 1];
    }
    elements[index] = value;
    count++;
}

template <typename ValueType>
bool VectorArray<ValueType>::isEmpty() const {
    return count == 0;
}





template <typename ValueType>
void VectorArray<ValueType>::remove(int index) {
    checkIndex(index, 0, count-1, "remove");
    for (int i = index; i < count - 1; i++) {
        elements[i] = elements[i + 1];
    }
    count--;
}

template <typename ValueType>
void VectorArray<ValueType>::set(int index, const ValueType& value) {
    checkIndex(index, 0, count-1, "set");
    elements[index] = value;
}

template <typename ValueType>
int VectorArray<ValueType>::size() const {
    return count;
}




/*
 * Implementation notes: Vector selection
 * --------------------------------------
 * The following code implements traditional array selection using
 * square brackets for the index.
 */
template <typename ValueType>
ValueType& VectorArray<ValueType>::operator [](int index) {
    checkIndex(index, 0, count-1, "operator []");
    return elements[index];
}
template <typename ValueType>
const ValueType& VectorArray<ValueType>::operator [](int index) const {
    checkIndex(index, 0, count-1, "operator []");
    return elements[index];
}



template <typename ValueType>
VectorArray<ValueType> & VectorArray<ValueType>::operator =(const VectorArray& src) {
    if (this != &src) {
        if (elements != NULL) {
            delete[] elements;
        }
        deepCopy(src);
    }
    return *this;
}

template <typename ValueType>
void VectorArray<ValueType>::checkIndex(int index, int min, int max, std::string prefix) const {
    if (index < min || index > max) {
        std::ostringstream out;
        out << "Vector::" << prefix << ": index of " << index
            << " is outside of valid range ";
        if (isEmpty()) {
            out << " (empty vector)";
        } else {
            out << "[";
            if (min < max) {
                out << min << ".." << max;
            } else if (min == max) {
                out << min;
            } // else min > max, no range, empty vector
            out << "]";
        }
        error(out.str());
    }
}

template <typename ValueType>
void VectorArray<ValueType>::deepCopy(const VectorArray& src) {
    count = capacity = src.count;
    elements = (capacity == 0) ? NULL : new ValueType[capacity];
    for (int i = 0; i < count; i++) {
        elements[i] = src.elements[i];
    }
}



#endif
