#include "exercise10.h"
#include <iostream>
#include "console.h"
#include "simpio.h"

#include "stringmapBST.h"

//using namespace std;

void exercise10() {
    std::cout << "ex10" << std::endl;
    StringMapBST s1;
    s1.put("t","myNameIs T");
    s1.put("r","myNameIs R");
    s1.put("z","myNameIs Z");
    s1.put("b","myNameIs B");
    s1.put("a","myNameIs A");
    s1.put("s","myNameIs S");
     s1.put("s1","myNameIs S1");
     s1.put("y","myNameIs Y");
     s1.put("z1","myNameIs Z1");
    s1.remove("z");
    std::cout << s1.get("t") << std::endl;
    std::cout << s1["t"] << std::endl;
    std::cout << s1.get("r") << std::endl;
    std::cout << s1.get("z") << std::endl;
    std::cout << s1.get("b") << std::endl;
    std::cout << s1.get("a") << std::endl;
    std::cout << s1.get("s") << std::endl;
    std::cout << s1.get("s1") << std::endl;
    std::cout << s1.get("y") << std::endl;
    std::cout << s1.get("z1") << std::endl;

    std::cout << s1.size() << std::endl;
    std::cout << s1.containsKey("a") << std::endl;
    s1.clear();
    std::cout << s1.isEmpty() << std::endl;
    std::cout << s1.containsKey("a") << std::endl;
    std::cout << s1.get("t") << std::endl;
    std::cout << s1.get("r") << std::endl;
    std::cout << s1.get("z") << std::endl;
    std::cout << s1.get("b") << std::endl;
    std::cout << s1.get("a") << std::endl;
    std::cout << s1.get("s") << std::endl;
    std::cout << s1.get("s1") << std::endl;
    std::cout << s1.get("y") << std::endl;
    std::cout << s1.get("z1") << std::endl;
}
