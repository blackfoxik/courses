
#include "exercise5.h"
#include <iostream>
#include "console.h"
#include "simpio.h"
#include <cstdlib>
#include <cmath>
#include "error.h"

using namespace std;

//func prototype
void getCoefficients(double & a, double & b, double & c);
void getCoefficients(double *a, double *b, double *c);
void solveQuadratic(double a, double b, double c, double & x1, double & x2);
void solveQuadratic(double a, double b, double c, double *x1, double *x2);
void printRoots(double x1, double x2);
void printRoots(double *x1, double *x2);
//void error(string msg);



void exercise5() {
    double a,  b, c, r1, r2;
    //double *pa, *pb, *pc, *pr1, *pr2;
    //pa = &a;
    //*pa = 120;
    //cout << " a = " << a  << " &a = " << &a << endl;
    //cout << " pa = " << pa << " *pa = " << *pa << " &pa = " << &pa << endl;
    //getCoefficients(a, b, c);
    getCoefficients(&a, &b, &c);
    //solveQuadratic(a, b, c, r1, r2);
    solveQuadratic(a, b, c, &r1, &r2);
    //printRoots(r1, r2);
    printRoots(&r1, &r2);
}

void getCoefficients(double *a, double *b, double *c) {
    cout << "Enter coefficients for the quadratic equation:" << endl;
    cout << "a: ";
    cin >> *a;
    cout << "b: ";
    cin >> *b;
    cout << "c: ";
    cin >> *c;
}

void getCoefficients(double & a, double & b, double & c) {
    cout << "Enter coefficients for the quadratic equation:" << endl;
    cout << "a: ";
    cin >> a;
    cout << "b: ";
    cin >> b;
    cout << "c: ";
    cin >> c;
}

void solveQuadratic(double a, double b, double c, double *x1, double *x2) {
    if (a == 0) error ("The coefficient a must be nonzero.");
    double disc = b * b - 4 * a * c;
    if (disc < 0) error ("This equation has no real roots.");
    double sqrtDisc = sqrt(disc);
    *x1 = (-b + sqrtDisc) / (2 * a);
    *x2 = (-b - sqrtDisc) / (2 * a);
}

void solveQuadratic(double a, double b, double c, double & x1, double & x2) {
    if (a == 0) error ("The coefficient a must be nonzero.");
    double disc = b * b - 4 * a * c;
    if (disc < 0) error ("This equation has no real roots.");
    double sqrtDisc = sqrt(disc);
    x1 = (-b + sqrtDisc) / (2 * a);
    x2 = (-b - sqrtDisc) / (2 * a);
}

void printRoots(double *x1, double *x2) {
    //cout << " x1 = " << x1 << " *x1 = " << *x1 << " &x1 = " << &x1 << endl;
    if (*x1 == *x2) {
        cout << "There is a double root at " << *x1 << endl;
    } else {
        cout << "The root are " << *x1 << " and " << *x2 << endl;
    }
}

void printRoots(double x1, double x2) {
    if (x1 == x2) {
        cout << "There is a double root at " << x1 << endl;
    } else {
        cout << "The root are " << x1 << " and " << x2 << endl;
    }
}

