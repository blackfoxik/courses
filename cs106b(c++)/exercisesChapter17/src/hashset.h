#ifndef _hashset_h
#define _hashset_h

#include <iostream>
#include <set>
#include "compare.h"
#include "error.h"
#include "map.h"
#include "vector.h"
#include "mapBucketsExpandDynamically.h"

template <typename ValueType>
class HashSet {
public:
    /*
     * Constructor: Set
     * Usage: Set<ValueType> set;
     * --------------------------
     * Initializes an empty set of the specified element type.
     */
    HashSet();

   ~HashSet();
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
    void add(const ValueType& value);

    /*
     * Method: remove
     * Usage: set.remove(value);
     * -------------------------
     * Removes an element from this set.  If the value was not
     * contained in the set, no error is generated and the set
     * remains unchanged.
     */
    void remove(const ValueType& value);

    /*
     * Method: contains
     * Usage: if (set.contains(value)) ...
     * -----------------------------------
     * Returns <code>true</code> if the specified value is in this set.
     */
    bool contains(const ValueType& value) const;

    /*
     * Method: clear
     * Usage: set.clear();
     * -------------------
     * Removes all elements from this set.
     */
    void clear();
    bool isSubsetOf(const HashSet& set2) const;













    /*
     * Operator: ==
     * Usage: set1 == set2
     * -------------------
     * Returns <code>true</code> if <code>set1</code> and <code>set2</code>
     * contain the same elements.
     */
    bool operator ==(const HashSet& set2) const;

    /*
     * Operator: !=
     * Usage: set1 != set2
     * -------------------
     * Returns <code>true</code> if <code>set1</code> and <code>set2</code>
     * are different.
     */
    bool operator !=(const HashSet& set2) const;

    /*
     * Operators: <, >, <=, >=
     * Usage: if (set1 <= set2) ...
     * ...
     * ----------------------------
     * Relational operators to compare two sets.
     * The <, >, <=, >= operators require that the ValueType has a < operator
     * so that the elements can be compared pairwise.
     */
    bool operator <(const HashSet& set2) const;
    bool operator <=(const HashSet& set2) const;
    bool operator >(const HashSet& set2) const;
    bool operator >=(const HashSet& set2) const;

    /*
     * Operator: +
     * Usage: set1 + set2
     *        set1 + element
     * ---------------------
     * Returns the union of sets <code>set1</code> and <code>set2</code>, which
     * is the set of elements that appear in at least one of the two sets.
     * You can also pass an initializer list such as {1, 2, 3}.
     * The right hand set can be replaced by an element of the value type, in
     * which case the operator returns a new set formed by adding that element.
     */
    HashSet operator +(const HashSet& set2) const;
    HashSet operator +(const ValueType& element) const;

    /*
     * Operator: *
     * Usage: set1 * set2
     * ------------------
     * Returns the intersection of sets <code>set1</code> and <code>set2</code>,
     * which is the set of all elements that appear in both.
     * You can also pass an initializer list such as {1, 2, 3}.
     */
    HashSet operator *(const HashSet& set2) const;


    /*
     * Operator: -
     * Usage: set1 - set2
     *        set1 - element
     * ---------------------
     * Returns the difference of sets <code>set1</code> and <code>set2</code>,
     * which is all of the elements that appear in <code>set1</code> but
     * not <code>set2</code>.
     * You can also pass an initializer list such as {1, 2, 3}.
     * The right hand set can be replaced by an element of the value type, in
     * which case the operator returns a new set formed by removing that element.
     */
    HashSet operator -(const HashSet& set2) const;
    HashSet operator -(const ValueType& element) const;

    /*
     * Operator: +=
     * Usage: set1 += set2;
     *        set1 += value;
     * ---------------------
     * Adds all of the elements from <code>set2</code> (or the single
     * specified value) to <code>set1</code>.
     * You can also pass an initializer list such as {1, 2, 3}.
     * As a convenience, the <code>Set</code> package also overloads the comma
     * operator so that it is possible to initialize a set like this:
     *
     *<pre>
     *    Set&lt;int&gt; digits;
     *    digits += 0, 1, 2, 3, 4, 5, 6, 7, 8, 9;
     *</pre>
     */
    HashSet& operator +=(const HashSet& set2);
    HashSet& operator +=(const ValueType& value);

    /*
     * Operator: *=
     * Usage: set1 *= set2;
     * --------------------
     * Removes any elements from <code>set1</code> that are not present in
     * <code>set2</code>.
     * You can also pass an initializer list such as {1, 2, 3}.
     */
    HashSet& operator *=(const HashSet& set2);


    /*
     * Operator: -=
     * Usage: set1 -= set2;
     *        set1 -= value;
     * ---------------------
     * Removes the elements from <code>set2</code> (or the single
     * specified value) from <code>set1</code>.
     * You can also pass an initializer list such as {1, 2, 3}.
     * As a convenience, the <code>Set</code> package also overloads the comma
     * operator so that it is possible to remove multiple elements from a set
     * like this:
     *
     *<pre>
     *    digits -= 0, 2, 4, 6, 8;
     *</pre>
     *
     * which removes the values 0, 2, 4, 6, and 8 from the set
     * <code>digits</code>.
     */
    HashSet& operator -=(const HashSet& set2);
    HashSet& operator -=(const ValueType& value);

    /*
     * Additional Set operations
     * -------------------------
     * In addition to the methods listed in this interface, the Set
     * class supports the following operations:
     *
     *   - Stream I/O using the << and >> operators
     *   - Deep copying for the copy constructor and assignment operator
     *   - Iteration using the range-based for statement and STL iterators
     *
     * The iteration forms process the Set in ascending order.
     */

    /* Private section */

    /**********************************************************************/
    /* Note: Everything below this point in the file is logically part    */
    /* of the implementation and should not be of interest to clients.    */
    /**********************************************************************/

private:
    //Map<ValueType, bool> map;            /* Map used to store the element     */
    bool removeFlag;                     /* Flag to differentiate += and -=   */
    MapBucketsExpandDynamically<ValueType,bool> map;

};

extern void error(std::string msg);


template <typename ValueType>
HashSet<ValueType>::HashSet() {
    /* Empty */
}

template <typename ValueType>
HashSet<ValueType>::~HashSet() {
    /* Empty */
}

template <typename ValueType>
void HashSet<ValueType>::add(const ValueType& value) {
    map.put(value, true);
}




template <typename ValueType>
void HashSet<ValueType>::clear() {
    map.clear();
}

template <typename ValueType>
bool HashSet<ValueType>::contains(const ValueType& value) const {
    return map.containsKey(value);
}







template <typename ValueType>
bool HashSet<ValueType>::isEmpty() const {
    return map.isEmpty();
}

template <typename ValueType>
bool HashSet<ValueType>::isSubsetOf(const HashSet& set2) const {
    return true;
}


template <typename ValueType>
void HashSet<ValueType>::remove(const ValueType& value) {
    map.remove(value);
}


template <typename ValueType>
int HashSet<ValueType>::size() const {
    return map.size();
}


/*
 * Implementation notes: set operators
 * -----------------------------------
 * The implementations for the set operators use iteration to walk
 * over the elements in one or both sets.
 */
template <typename ValueType>
bool HashSet<ValueType>::operator ==(const HashSet& set2) const {
    return equals(set2);
}

template <typename ValueType>
bool HashSet<ValueType>::operator !=(const HashSet& set2) const {
    return !equals(set2);
}

template <typename ValueType>
bool HashSet<ValueType>::operator <(const HashSet& set2) const {
    return compare::compare(*this, set2) < 0;
}

template <typename ValueType>
bool HashSet<ValueType>::operator <=(const HashSet& set2) const {
    return compare::compare(*this, set2) <= 0;
}

template <typename ValueType>
bool HashSet<ValueType>::operator >(const HashSet& set2) const {
    return compare::compare(*this, set2) > 0;
}

template <typename ValueType>
bool HashSet<ValueType>::operator >=(const HashSet& set2) const {
    return compare::compare(*this, set2) >= 0;
}

template <typename ValueType>
HashSet<ValueType> HashSet<ValueType>::operator +(const HashSet& set2) const {
    HashSet<ValueType> set = *this;
    set.addAll(set2);
    return set;
}


template <typename ValueType>
HashSet<ValueType> HashSet<ValueType>::operator +(const ValueType& element) const {
    HashSet<ValueType> set = *this;
    set.add(element);
    return set;
}

template <typename ValueType>
HashSet<ValueType> HashSet<ValueType>::operator *(const HashSet& set2) const {
    HashSet<ValueType> set = *this;
    return set.retainAll(set2);
}



template <typename ValueType>
HashSet<ValueType> HashSet<ValueType>::operator -(const HashSet& set2) const {
    HashSet<ValueType> set = *this;
    return set.removeAll(set2);
}


template <typename ValueType>
HashSet<ValueType> HashSet<ValueType>::operator -(const ValueType& element) const {
    HashSet<ValueType> set = *this;
    set.remove(element);
    return set;
}

template <typename ValueType>
HashSet<ValueType>& HashSet<ValueType>::operator +=(const HashSet& set2) {
    return addAll(set2);
}


template <typename ValueType>
HashSet<ValueType>& HashSet<ValueType>::operator +=(const ValueType& value) {
    add(value);
    removeFlag = false;
    return *this;
}

template <typename ValueType>
HashSet<ValueType>& HashSet<ValueType>::operator *=(const HashSet& set2) {
    return retainAll(set2);
}


template <typename ValueType>
HashSet<ValueType>& HashSet<ValueType>::operator -=(const HashSet& set2) {
    return removeAll(set2);
}


template <typename ValueType>
HashSet<ValueType>& HashSet<ValueType>::operator -=(const ValueType& value) {
    remove(value);
    removeFlag = true;
    return *this;
}

template <typename ValueType>
std::ostream& operator <<(std::ostream& os, const HashSet<ValueType>& set) {
    os << "{";
    bool started = false;
    for (ValueType value : set) {
        if (started) {
            os << ", ";
        }
        writeGenericValue(os, value, /* forceQuotes */ true);
        started = true;
    }
    os << "}";
    return os;
}

template <typename ValueType>
std::istream& operator >>(std::istream& is, HashSet<ValueType>& set) {
    char ch = '\0';
    is >> ch;
    if (ch != '{') {
#ifdef SPL_ERROR_ON_COLLECTION_PARSE
        error("Set::operator >>: Missing {");
#endif
        is.setstate(std::ios_base::failbit);
        return is;
    }
    set.clear();
    is >> ch;
    if (ch != '}') {
        is.unget();
        while (true) {
            ValueType value;
            if (!readGenericValue(is, value)) {
#ifdef SPL_ERROR_ON_COLLECTION_PARSE
                error("Set::operator >>: parse error");
#endif
                return is;
            }
            set += value;
            is >> ch;
            if (ch == '}') {
                break;
            }
            if (ch != ',') {
#ifdef SPL_ERROR_ON_COLLECTION_PARSE
                error(std::string("Set::operator >>: Unexpected character ") + ch);
#endif
                is.setstate(std::ios_base::failbit);
                return is;
            }
        }
    }
    return is;
}


#endif
