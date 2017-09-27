#include "exercise13.h"
#include "bigint.h"

using namespace std;
//func prototype
BigInt fact(int n);

//general
void exercise13() {

    for (int i = 1; i < 53; i++) {
        BigInt f = fact(i);
        cout << " fact(" << i << ") = " << f.toString() << endl;
    }

}

BigInt fact(int n) {
    if (n == 1) {
        return BigInt(1);
    }
    return BigInt(n)*fact(n - 1);
}
