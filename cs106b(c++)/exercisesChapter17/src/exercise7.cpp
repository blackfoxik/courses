#include "console.h"
#include "exercise7.h"
#include "cctypeex7mask.h"

using namespace std;

void printProperties (CctypeEx7Mask & t, char sign);

void exercise7() {
    CctypeEx7Mask t;
    char A = 'A';
    char a = 'a';
    char n1 = '1';
    char nP = '+';
    printProperties(t,A);
    printProperties(t,a);
    printProperties(t,n1);
    printProperties(t,nP);
}

void printProperties (CctypeEx7Mask & t, char sign) {
    cout << sign << " isalnum: " << t.isalnum(sign) << endl;
    cout << sign << " isdigit: " << t.isdigit(sign) << endl;
    cout << sign << " isalpha: " << t.isalpha(sign) << endl;
    cout << sign << " islower: " << t.islower(sign) << endl;
    cout << sign << " isupper: " << t.isupper(sign) << endl;
    cout <<  endl;
}
