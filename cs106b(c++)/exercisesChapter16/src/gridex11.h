#ifndef _gridex11_h
#define _gridex11_h

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


template <typename ValueType>
class GridEx11 {
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
    GridEx11();
    GridEx11(int nRow, int nCol);
    explicit GridEx11(int nRow, int nCol, ValueType value = ValueType());

    /*
     * This constructor copies an STL vector.
     */
    /* implicit */ GridEx11(const std::vector<ValueType>& v);



    /*
     * Destructor: ~Vector
     * -------------------
     * Frees any heap storage allocated by this vector.
     */
    virtual ~GridEx11();

    void set(int nRow, int nCol, ValueType value);



    /*
     * Method: clear
     * Usage: vec.clear();
     * -------------------
     * Removes all elements from this vector.
     */
    void clear();


    /*
     * Method: get
     * Usage: ValueType val = vec.get(index);
     * --------------------------------------
     * Returns the element at the specified index in this vector.  This
     * method signals an error if the index is not in the array range.
     */

    const ValueType& get(int nRow, int nCol) const;
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
    //ValueType& operator [](int nRow, int nCol);
    ValueType& operator ()(int nRow, int nCol);






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
    int nRow;
    int nCol;

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
    void deepCopy(const GridEx11& src);

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
    GridEx11(const GridEx11& src);
    GridEx11& operator =(const GridEx11& src);

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
GridEx11<ValueType>::GridEx11() {
    count = capacity = 0;
    elements = NULL;
    nRow = nCol = 0;
}

template <typename ValueType>
GridEx11<ValueType>::GridEx11(int nRow, int nCol) {
    count = 0;
    capacity = nRow * nCol;
    elements = NULL;
    this->nRow = nRow;
    this->nCol = nCol;
}

template <typename ValueType>
GridEx11<ValueType>::GridEx11(int nRow, int nCol, ValueType value) {
    count = nRow * nCol;
    capacity = nRow * nCol;
    elements = (count == 0) ? NULL : new ValueType[count];
    for (int i = 0; i < count; i++) {
        elements[i] = value;
    }
    this->nRow = nRow;
    this->nCol = nCol;
}





/*
 * Implementation notes: copy constructor and assignment operator
 * --------------------------------------------------------------
 * The constructor and assignment operators follow a standard paradigm,
 * as described in the associated textbook.
 */
template <typename ValueType>
GridEx11<ValueType>::GridEx11(const GridEx11& src) {
    deepCopy(src);
}

template <typename ValueType>
GridEx11<ValueType>::~GridEx11() {
    if (elements != NULL) {
        delete[] elements;
        elements = NULL;
    }
}

template <typename ValueType>
void GridEx11<ValueType>::clear() {
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
void GridEx11<ValueType>::expandCapacity() {
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
const ValueType& GridEx11<ValueType>::get(int nRow, int nCol) const {
    int index = this->nRow * nRow + nCol;
    checkIndex(index, 0, count-1, "get");
    return elements[index];
}



template <typename ValueType>
bool GridEx11<ValueType>::isEmpty() const {
    return count == 0;
}





template <typename ValueType>
void GridEx11<ValueType>::remove(int index) {
    checkIndex(index, 0, count-1, "remove");
    for (int i = index; i < count - 1; i++) {
        elements[i] = elements[i + 1];
    }
    count--;
}

template <typename ValueType>
void GridEx11<ValueType>::set(int nRow, int nCol, ValueType value) {
    //checkIndex(index, 0, count-1, "set");
    int index = nRow * this->nRow + nCol;
    elements[index] = value;
}



template <typename ValueType>
int GridEx11<ValueType>::size() const {
    return count;
}




/*
 * Implementation notes: Vector selection
 * --------------------------------------
 * The following code implements traditional array selection using
 * square brackets for the index.
 */
template <typename ValueType>
ValueType& GridEx11<ValueType>::operator [](int index) {
    checkIndex(index, 0, count-1, "operator []");
    return elements[index];
}
template <typename ValueType>
const ValueType& GridEx11<ValueType>::operator [](int index) const {
    checkIndex(index, 0, count-1, "operator []");
    return elements[index];
}


template <typename ValueType>
//ValueType& GridEx11<ValueType>::operator [](int nRow, int nCol) {
ValueType& GridEx11<ValueType>::operator ()(int nRow, int nCol) {
    int index = this->nRow * nRow + nCol;
    checkIndex(index, 0, count-1, "operator []");
    return elements[index];
}

template <typename ValueType>
GridEx11<ValueType> & GridEx11<ValueType>::operator =(const GridEx11& src) {
    if (this != &src) {
        if (elements != NULL) {
            delete[] elements;
        }
        deepCopy(src);
    }
    return *this;
}

template <typename ValueType>
void GridEx11<ValueType>::checkIndex(int index, int min, int max, std::string prefix) const {
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
void GridEx11<ValueType>::deepCopy(const GridEx11& src) {
    count = capacity = src.count;
    elements = (capacity == 0) ? NULL : new ValueType[capacity];
    for (int i = 0; i < count; i++) {
        elements[i] = src.elements[i];
    }
}



#endif
