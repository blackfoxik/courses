#include "exercise9.h"
#include "mystring.h"
#include <cassert>
using namespace std;

//general
void exercise9() {
    MyString myStr("string");
    cout << myStr.length() << endl;

    MyString mySec("sec");
    myStr += 'Z';
    cout << myStr << endl;
    MyString sum("");
    sum = myStr + mySec;
    cout << sum << endl;
    cout << sum[5] << endl;
    bool r = myStr > mySec;
    cout << r << endl;
    // as implementing of exercise 11 (there is mistype in reader 10 ,12 they misses exercise 11
    assert(myStr.length() > 0);
    assert(myStr[0] == 's');
    assert(sum > mySec);
}





