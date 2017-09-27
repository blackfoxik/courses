#include "exercise3.h"
#include <iostream>
#include "console.h"
#include "simpio.h"
#include "pair.h"

using namespace std;


void exercise3() {
    Pair<string, int> p1;
    Pair<int, string> p2(10, "avc");
    std::cout << p2.getFirst() << std::endl;
}

