#include <cstdlib>
#include <string>
#include "rational.h"
#include "strlib.h"
#include "error.h"
using namespace std;

int qcd(int x, int y);

Rational::Rational() {
    num = 0;
    den = 1;
}

Rational::Rational(const int n) {
    num = n;
    den = 1;
}

Rational::Rational(const int x, const int y) {
    if (y == 0) error("Rational: Division by zero");
    if (x == 0) {
        num = 0;
        den = 1;
    } else {
        int q = qcd(abs(x), abs(y));
        num = x / q;
        den = abs(y) / q;
        if (y < 0) num = -num;
    }
}

string Rational::toString() const {
    if (den == 1) {
        return integerToString(num);
    } else {
        return integerToString(num) + "/" + integerToString(den);
    }
}

ostream & operator<<(ostream & os, const Rational rat) {
    return os << rat.toString();
}

Rational operator+(const Rational r1, const Rational r2) {
    return Rational(r1.num * r2.den + r2.num * r1.den, r1.den * r2.den);
}

Rational operator-(const Rational r1, const Rational r2) {
    return Rational(r1.num * r2.den - r2.num * r1.den, r1.den * r2.den);
}

Rational operator*(const Rational r1, const Rational r2) {
    return Rational(r1.num * r2.num, r1.den * r2.den);
}

Rational operator/(const Rational r1, const Rational r2) {
    return Rational(r1.num * r2.den, r1.den * r2.num);
}

void operator+=(Rational &r1, const Rational r2) {
    r1 = r1 + r2;
}
void operator-=(Rational &r1, const Rational r2) {
    r1 = r1 - r2;
}

void operator*=(Rational &r1, const Rational r2) {
    r1 = r1 * r2;
}

void operator/=(Rational &r1, const Rational r2) {
    r1 = r1 / r2;
}


Rational operator++(Rational &r1, int i) {
    Rational old = r1;
    Rational rOne(1,1);
    r1+=rOne;
    return old;
}

Rational operator++(Rational &r1) {
    Rational rOne(1,1);
    r1+=rOne;
    return r1;
}

Rational operator--(Rational &r1, int i) {
    Rational old = r1;
    Rational rOne(1,1);
    r1-=rOne;
    return old;
}

Rational operator--(Rational &r1) {
    Rational rOne(1,1);
    r1-=rOne;
    return r1;
}



bool operator==(const Rational r1, const Rational r2) {
    if (r1.num == r2.num && r1.den == r2.den) {
        return true;
    } else {
        return false;
    }
}

bool operator!=(const Rational r1, const Rational r2) {
    return !(r1 == r2);
}

bool operator<(const Rational r1, const Rational r2) {
     int q = qcd (r1.den, r2.den);
     int r1CurNum = r1.num * q;
     int r2CurNum = r2.num * q;
     if (r1CurNum < r2CurNum) {
         return true;
     } else {
         return false;
     }
}

bool operator<=(const Rational r1, const Rational r2) {
    int q = qcd (r1.den, r2.den);
    int r1CurNum = r1.num * q;
    int r2CurNum = r2.num * q;
    if (r1CurNum <= r2CurNum) {
        return true;
    } else {
        return false;
    }
}

bool operator>(const Rational r1, const Rational r2) {
    int q = qcd (r1.den, r2.den);
    int r1CurNum = r1.num * q;
    int r2CurNum = r2.num * q;
    if (r1CurNum > r2CurNum) {
        return true;
    } else {
        return false;
    }
}

bool operator>=(const Rational r1, const Rational r2) {
    int q = qcd (r1.den, r2.den);
    int r1CurNum = r1.num * q;
    int r2CurNum = r2.num * q;
    if (r1CurNum >= r2CurNum) {
        return true;
    } else {
        return false;
    }
}


int qcd (int x, int y) {
    int r = x % y;
    while (r != 0) {
        x = y;
        y = r;
        r = x % y;
    }
    return y;
}



