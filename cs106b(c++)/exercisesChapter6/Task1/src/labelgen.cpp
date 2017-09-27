#include <iostream>
#include <string>
#include "labelgen.h"

using namespace std;

LabelGenerator::LabelGenerator(string inputPrefix, int initialIndex) {
    prefix = inputPrefix;
    index = initialIndex;
}

string LabelGenerator::nextLabel() {
    return prefix + to_string(index++);
}



