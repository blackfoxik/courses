#include "exercise12.h"
#include "mystringlist.h"
using namespace std;

//general
void exercise12() {
    MyStringList myStr("string");
    cout << myStr.length() << endl;

    MyStringList mySec("sec");
    myStr += 'Z';
    cout << myStr << endl;
    MyStringList sum("");
    sum = myStr + mySec;
    cout << sum << endl;
    cout << sum[5] << endl;
    bool r = myStr > mySec;
    cout << r << endl;
}

