#include "exercise1.h"
#include <iostream>
#include "console.h"
#include "simpio.h"

#include "stringmapbinsearch.h"

//using namespace std;

void exercise1() {
    StringMapBinSearch s1;
    s1.put("t","myNameIs T");
    s1.put("r","myNameIs R");
    s1.put("z","myNameIs Z");
    s1.put("b","myNameIs B");
    s1.put("a","myNameIs A");
    std::cout << s1.get("a") << std::endl;
}
