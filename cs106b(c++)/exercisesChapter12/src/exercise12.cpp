

#include "exercise12.h"
#include "rational.h"
#include "cassert"

using namespace std;

//func prototypes

//general
void exercise12() {
    Rational a1(3, 2);
    Rational a2(2, 3);
    Rational a3  = a1 + a2;
    cout << a1.toString() << endl;
    cout << a2.toString() << endl;
    cout << a3.toString() << endl;
    assert(a1 > a2);
    assert(a3 > a1);
    a1++;
    a2--;
    a3 *= 2;
    cout << a1.toString() << endl;
    cout << a2.toString() << endl;
    cout << a3.toString() << endl;
    assert(a3 != 0);
}

