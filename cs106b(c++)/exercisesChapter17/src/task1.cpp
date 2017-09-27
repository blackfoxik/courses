#include <iostream>
#include "console.h"
#include "gwindow.h" // for GWindow
#include "simpio.h"  // for getLine
#include "vector.h"  // for Vector
#include "exercise1.h"
#include "exercise2.h"
#include "exercise3.h"
#include "exercise4.h"
#include "exercise5.h"
#include "exercise6.h"
#include "exercise7.h"
#include "exercise8.h"
#include "exercise9.h"


using namespace std;

int main() {
    int number = getInteger("Input exercise number: ");
    switch (number) {
    case 1:
        exercise1();
        break;
    case 2:
        exercise2();
        break;
    case 3:
        exercise3();
        break;
    case 4:
        exercise4();
        break;
    case 5:
        exercise5();
        break;
    case 6:
        exercise6();
        break;
    case 7:
        exercise7();
        break;
    case 8:
        exercise8();
        break;
    case 9:
        exercise9();
        break;
    default:
        break;
    }
    //exercise1();
    //exercise2();
    //exercise3();
    //exercise4();
    //exercise5();
    //exercise6();
    //exercise7();
    //exercise8();
    //exercise9();
    cout <<"Work";
    return 0;
}


