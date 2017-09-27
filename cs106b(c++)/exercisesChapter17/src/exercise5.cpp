#include "exercise5.h"
#include <iostream>
#include "console.h"
#include "simpio.h"
#include <cstdlib>
#include <hashset.h>
#include "error.h"

using namespace std;

void exercise5() {
    //hashset was implemented based on stringMapBucketExpandDynamically from chapter 16
    //which was edited to support template approach
    HashSet<string> s1;
    s1.add("a1");
    cout << s1.isEmpty() << endl;
}

