
#include "cctypeex7mask.h"
#include <iostream>
#include "console.h"
#include "simpio.h"
#include "error.h"
#include "strlib.h"


using namespace std;
    const int SIZE_OF_LONG = sizeof(long);
    const int BIT_PER_BYTE = 8;
    const int BIT_PER_LONG = SIZE_OF_LONG * BIT_PER_BYTE;
    const int RANGE_SIZE = 256;
    const int CPROPERTIES = 3;
    const int CWORDS = (CPROPERTIES * RANGE_SIZE ) / BIT_PER_LONG;
    CctypeEx7Mask::CctypeEx7Mask() {
      storage = new unsigned long[CWORDS];
      fillStorage();
    }

    CctypeEx7Mask::~CctypeEx7Mask() {
     delete[] storage;
    }

    bool CctypeEx7Mask::isdigit(int n) {
       int nWord = n * CPROPERTIES / BIT_PER_LONG;
       int nPos = n * CPROPERTIES % BIT_PER_LONG;
       unsigned long mask = createMask(nPos);
       unsigned long res = storage[nWord] & mask;
       return res > 0;
    }
    bool CctypeEx7Mask::isalpha(int n) const {
        int nWord = n * CPROPERTIES / BIT_PER_LONG;
        int nPos = n * CPROPERTIES % BIT_PER_LONG;
        unsigned long mask = createMaskForItemBase6(nPos);
        unsigned long res = storage[nWord] & mask;
        return res > 0;
    }
    bool CctypeEx7Mask::isalnum(int n) const {
        int nWord = n * CPROPERTIES / BIT_PER_LONG;
        int nPos = n * CPROPERTIES % BIT_PER_LONG;
        unsigned long mask = createMaskForItem(nPos);
        unsigned long res = storage[nWord] & mask;
        return res > 0;
    }
    bool CctypeEx7Mask::islower(int n) const {
        int nWord = n * CPROPERTIES / BIT_PER_LONG;
        int nPos = n * CPROPERTIES % BIT_PER_LONG;
        unsigned long mask = createMask(nPos + 1);
        unsigned long res = storage[nWord] & mask;
        return res > 0;
    }
    bool CctypeEx7Mask::isupper(int n) const {
        int nWord = n * CPROPERTIES / BIT_PER_LONG;
        int nPos = n * CPROPERTIES % BIT_PER_LONG;
        unsigned long mask = createMask(nPos + 2);
        unsigned long res = storage[nWord] & mask;
        return res > 0;
    }

    void CctypeEx7Mask::fillStorage() {

        for (int i = 0; i < CWORDS; i++) {
           storage[i] = 0;
        }
        //0-9 fill is digit
        for (int i = 48; i < 57; i++) {
           setDigit(i);
        }
        //fill is lower
        for (int i = 97; i < 122; i++) {
           setLower(i);
        }
        //fill is upper
        for (int i = 65; i < 90; i++) {
           setUpper(i);
        }

        //for (int i = 0; i < CWORDS; i++) {
        //    cout << convertUSToString(storage[i]) << endl;
        //}

    }

    void CctypeEx7Mask::setDigit(int n) {
        int nWord = n * CPROPERTIES / BIT_PER_LONG;
        int nPos = n * CPROPERTIES % BIT_PER_LONG;
        unsigned long mask = createMask(nPos);
        storage[nWord] |= mask;
    }

    void CctypeEx7Mask::setLower(int n) {
        int nWord = n * CPROPERTIES / BIT_PER_LONG;
        int nPos = n * CPROPERTIES % BIT_PER_LONG;
        unsigned long mask = createMask(nPos + 1);
        storage[nWord] |= mask;
    }

    void CctypeEx7Mask::setUpper(int n) {
        int nWord = n * CPROPERTIES / BIT_PER_LONG;
        int nPos = n * CPROPERTIES % BIT_PER_LONG;
        unsigned long mask = createMask(nPos + 2);
        storage[nWord] |= mask;
    }

    unsigned long CctypeEx7Mask::createMask(int k) const {

              unsigned long mask = long(1) << k;
              return mask;
    }

    unsigned long CctypeEx7Mask::createMaskForItem(int k) const {
              unsigned long mask = long(7) << k ;
              return mask;
    }

    unsigned long CctypeEx7Mask::createMaskForItemBase6(int k) const {
              unsigned long mask = long(6) << k ;
              return mask;
    }

    string CctypeEx7Mask::convertUSToString(unsigned long us) {
        string res = "";
        unsigned long rem = us;
        while(rem > 0) {
           unsigned long reminder = rem % 2;
           if (reminder == 0) {
               res = '0' + res;
           } else {
               res = '1' + res;
           }
           rem = rem / 2;
        }
        for (int i = res.size(); i < 64; i++) {
            res = '0' + res;
        }
        return res;
    }
