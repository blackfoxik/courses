
#include "console.h"
#include "simpio.h"  // for getLine
#include "exercise10.h"
#include "vectorlist.h"
#include "assert.h"

//func prototypes


//general
void exercise10() {
    VectorList<int> intSet;
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

    VectorList<string> strSet;
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





