#include "exercise5.h"
#include <iostream>
#include "console.h"
#include "simpio.h"

#include "stringmapBucketsExpandDynamically.h"

//using namespace std;

void exercise5() {
    StringMapBucketsExpandDynamically s1;
    s1.put("t","myNameIs T");
    s1.put("r","myNameIs R");
    s1.put("z","myNameIs Z");
    s1.put("b","myNameIs B");
    s1.put("a","myNameIs A");
    std::cout << s1.get("t") << std::endl;
    std::cout << s1.get("r") << std::endl;
    //std::cout << s1.size() << std::endl;
    //std::cout << s1.containsKey("a") << std::endl;
    //s1.clear();
    //std::cout << s1.isEmpty() << std::endl;
}
