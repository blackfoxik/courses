#include "exercise10.h"
#include <iostream>
#include "console.h"
#include "simpio.h"

#include "stringmapopenaddressingda.h"

//using namespace std;

void exercise10() {
    std::cout << "ex10" << std::endl;
    StringMapOpenAddressingDA s1;
    s1.put("t","myNameIs T");
    s1.put("r","myNameIs R");
    s1.put("z","myNameIs Z");
    s1.put("b","myNameIs B");
    s1.put("a","myNameIs A");
    //s1.add("r","Tempopary R");
    std::cout << s1.get("t") << std::endl;
    std::cout << s1.get("r") << std::endl;
    std::cout << s1.get("z") << std::endl;
    std::cout << s1.get("b") << std::endl;
    std::cout << s1.get("a") << std::endl;
    //std::cout << s1["z"] << std::endl;
    //s1.remove("r");
    //std::cout << s1.get("r") << std::endl;
    //std::cout << s1.size() << std::endl;
    //std::cout << s1.containsKey("a") << std::endl;
    //s1.clear();
    //std::cout << s1.isEmpty() << std::endl;

}
