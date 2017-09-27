
#include "cctypeex7.h"
#include <iostream>
#include "console.h"
#include "simpio.h"
#include "error.h"
#include "strlib.h"


using namespace std;
    CctypeEx7::CctypeEx7() {
      storage = new unsigned long[768];
      fillStorage();
    }

    CctypeEx7::~CctypeEx7() {
     delete[] storage;
    }

    bool CctypeEx7::isdigit(int n) const {
       return storage[n*3] == 1;
    }
    bool CctypeEx7::isalpha(int n) const {
       bool low = islower(n);
       bool up = isupper(n);
       return (low) ? true: up;
    }
    bool CctypeEx7::isalnum(int n) const {
        bool isAlp = isalpha(n);
        bool isDig = isdigit(n);
        return (isAlp) ? true: isDig;
    }
    bool CctypeEx7::islower(int n) const {
        return storage[n*3 + 1] == 1;
    }
    bool CctypeEx7::isupper(int n) const {
        return storage[n*3 + 2] == 1;
    }

    void CctypeEx7::fillStorage() {
        for (int i = 0; i < 768; i++) {
           storage[i] = 0;
        }
        //0-9 fill is digit
        for (int i = 148; i < 171; i = i+3) {
           storage[i] = 1;
        }
        //fill is lower
        for (int i = 195; i < 270; i = i+3) {
           storage[i + 1] = 1;
        }
        //fill is upper
        for (int i = 291; i < 366; i = i+3) {
           storage[i + 2] = 1;
        }
    }
