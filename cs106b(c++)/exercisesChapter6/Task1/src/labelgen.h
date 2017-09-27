#ifndef _labelgen_h
#define _labelgen_h
#include <iostream>
#include <string>
using namespace std;

class LabelGenerator {
public:
    LabelGenerator(string inputPrefix, int initialIndex);
    string nextLabel();
private:
    string prefix;
    int index;
};

#endif
