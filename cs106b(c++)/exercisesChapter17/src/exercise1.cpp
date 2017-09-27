#include "exercise1.h"
#include <iostream>
#include "console.h"
#include "simpio.h"
#include "grid.h"
#include "vector.h"

using namespace std;



void exercise1() {
    /* we needed to implement overloading for >> and << opertors */
}

/*
template <typename ValueType>
std::ostream& operator <<(std::ostream& os, const Set<ValueType>& set) {
    os << "{";
    bool started = false;
    for (ValueType value : set) {
        if (started) {
            os << ", ";
        }
        writeGenericValue(os, value,  true);
        started = true;
    }
    os << "}";
    return os;
}

template <typename ValueType>
std::istream& operator >>(std::istream& is, Set<ValueType>& set) {
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
*/
