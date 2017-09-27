#ifndef _rational_h
#define _rational_h
#include <iostream>
#include <string>
using namespace std;

class Rational {
public:
   Rational();
   Rational(int n);
   Rational(int x, int y);
   string toString();


 /*  Rational operator+(Rational r1, Rational r2);
   Rational operator-(Rational r1, Rational r2);
   Rational operator*(Rational r1, Rational r2);
   Rational operator/(Rational r1, Rational r2);*/
   friend Rational operator+(Rational r1, Rational r2);
   friend Rational operator-(Rational r1, Rational r2);
   friend Rational operator*(Rational r1, Rational r2);
   friend Rational operator/(Rational r1, Rational r2);

   friend void operator+=(Rational &r1, Rational r2);
   friend void operator-=(Rational &r1, Rational r2);
   friend void operator*=(Rational &r1, Rational r2);
   friend void operator/=(Rational &r1, Rational r2);

   friend Rational operator++(Rational &r1, int i);
   friend Rational operator++(Rational &r1);
   friend Rational operator--(Rational &r1, int i);
   friend Rational operator--(Rational &r1);

   friend bool operator==(Rational r1, Rational r2);
   friend bool operator!=(Rational r1, Rational r2);
   friend bool operator<(Rational r1, Rational r2);

   friend bool operator<=(Rational r1, Rational r2);
   friend bool operator>(Rational r1, Rational r2);
   friend bool operator>=(Rational r1, Rational r2);

private:
    //int qcd(int x, int y);
    int num;
    int den;
};



std::ostream & operator<<(ostream & os, Rational rat);

#endif
