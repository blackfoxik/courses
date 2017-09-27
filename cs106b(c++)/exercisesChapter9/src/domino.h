// This header file doesn't do much, but it's good to demonstrate that it's
// possible to create and edit header files
#ifndef _domino_h
#define _domino_h
#include <string>
#include <ostream>

class Domino {
public:
    Domino();
    Domino(int inputLeftDots, int inputRightDots);

    int getLeftDots();
    int getRightDots();

    std::string toString();

private:
    int leftDots;
    int rightDots;
};
std::ostream & operator<<(std::ostream & os, Domino domino);
#endif
