#ifndef _cctypeex7mask_h
#define _cctypeex7mask_h

#include <iostream>
#include "compare.h"
#include "error.h"



class CctypeEx7Mask {
public:
    CctypeEx7Mask();

   ~CctypeEx7Mask();

    bool isdigit(int n);
    bool isalpha(int n) const;
    bool isalnum(int n) const;
    bool islower(int n) const;
    bool isupper(int n) const;

private:
    unsigned long *storage;
    void fillStorage();
    unsigned long createMask(int k) const;
    unsigned long createMaskForItem(int k) const;
    unsigned long createMaskForItemBase6(int k) const;
    void setUpper(int n);
    void setLower(int n);
    void setDigit(int n);
    std::string convertUSToString(unsigned long us);
};

#endif
