#include "console.h"
#include "simpio.h"  // for getLine
#include <iomanip>
#include "set.h"
#include "grid.h"
#include "exercise6.h"
using namespace std;

//func prototype
unsigned short factor(unsigned short n);
unsigned short convertStringToUS(string str);
string convertUSToString(unsigned short us);

void exercise6() {
    //string xStr = getLine("Enter x:");
    //string yStr = getLine("Enter y:");
    string xStr = "0000000000101010"; // 42
    string yStr = "0000000000011011"; // 27
    //unsigned short x = 18505;
    //unsigned short y = 377;
    unsigned short x = convertStringToUS(xStr);
    unsigned short y = convertStringToUS(yStr);
    unsigned short z = x & y;
    unsigned short z1 = x | y;
    unsigned short z2 = x ^ y;
    unsigned short z3 = ~y;
    unsigned short z4 = x & ~y;
    cout << "x & y = " << convertUSToString(z) << endl;
    cout << "x | y = " << convertUSToString(z1) << endl;
    cout << "x ^ y = " << convertUSToString(z2) << endl;
    cout << "~y = " << convertUSToString(z3) << endl;
    cout << "x & ~y = " << convertUSToString(z4) << endl;
}

unsigned short factor(unsigned short n) {
    if (n == 0) {
        return 1;
    }
    return 2*factor(n - 1);
}

unsigned short convertStringToUS(string str) {
    if(str.size() > 16 || str.size() < 16) error("incorrect strig");
    unsigned short res = 0;
    for (int i = 0; i <= 15; i++) {
        char bit = str[15 - i];
        if (bit == '1') res += factor(i);
    }
    return res;
}

string convertUSToString(unsigned short us) {
    string res = "";
    unsigned short rem = us;
    while(rem > 0) {
       unsigned short reminder = rem % 2;
       if (reminder == 0) {
           res = '0' + res;
       } else {
           res = '1' + res;
       }
       rem = rem / 2;
    }
    for (int i = res.size(); i < 16; i++) {
        res = '0' + res;
    }
    return res;
}





