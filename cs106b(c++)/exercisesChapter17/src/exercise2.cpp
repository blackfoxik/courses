#include "exercise2.h"
#include <iostream>
#include "console.h"
#include "simpio.h"
#include "set.h"

using namespace std;

void exercise2() {
 Set<char> s1;
 cout << "Enter s1: ";
 cin>>s1;
 cout << "Enter s2: ";
 Set<char> s2;
 cin>>s2;
 cout << "s1 + s2 = " << s1 + s2 << endl;
 cout << "s1 * s2 = " << s1 * s2 << endl;
 cout << "s1 - s2 = " << s1 - s2 << endl;
}



