
#include "console.h"
#include "simpio.h"  // for getLine
#include "exercise9.h"
#include "vector.h"
#include "assert.h"

//func prototypes


//general
void exercise9() {
    Vector<int> intSet;
    intSet.add(2);
    intSet.add(3);
    intSet.add(5);
    assert(intSet.size() == 3);
    assert(intSet.get(2) == 5);
    assert(!intSet.isEmpty());
    intSet.remove(0);
    assert(intSet.size() == 2);
    intSet.clear();
    assert(intSet.isEmpty());

    Vector<string> strSet;
    strSet.add("2");
    strSet.add("3");
    strSet.add("5");
    assert(strSet.size() == 3);
    assert(strSet.get(2) == "5");
    assert(!strSet.isEmpty());
    strSet.remove(0);
    assert(strSet.size() == 2);
    strSet.clear();
    assert(strSet.isEmpty());
}





