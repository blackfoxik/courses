#include "exercise2.h"
#include <iostream>
#include "console.h"
#include "simpio.h"

#include "stringmapdynamicarray.h"

//using namespace std;

void exercise2() {
    StringMapDynamicArray s1;
    s1.put("t","myNameIs T");
    s1.put("r","myNameIs R");
    s1.put("z","myNameIs Z");
    s1.put("b","myNameIs B");
    s1.put("a","myNameIs A");
    std::cout << s1.get("t") << std::endl;
}
