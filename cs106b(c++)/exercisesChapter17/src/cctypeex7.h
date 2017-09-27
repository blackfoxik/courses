#ifndef _cctypeex7_h
#define _cctypeex7_h

#include <iostream>
#include "compare.h"
#include "error.h"



class CctypeEx7 {
public:
    CctypeEx7();

   ~CctypeEx7();

    bool isdigit(int n) const;
    bool isalpha(int n) const;
    bool isalnum(int n) const;
    bool islower(int n) const;
    bool isupper(int n) const;

private:
    unsigned long *storage;
    void fillStorage();
};

#endif
