#ifndef _bigint_h
#define _bigint_h
#include <iostream>

using namespace std;


class BigInt {
public:
   BigInt();
   BigInt(string str);
   BigInt(int number);
  ~BigInt();
   string toString() const;
   int length() const;


   BigInt & operator +=(const BigInt &str);
   //BigInt & operator *(const BigInt &str);
   int & operator [](int index) const;

   friend BigInt operator+(const BigInt &str1, const BigInt &str2);
   friend BigInt operator*(const BigInt &str1, const BigInt &str2);
   BigInt &operator =(const BigInt &str);
   BigInt (const BigInt & src);

private:
   struct Cell {
       int data;
       Cell *link;
   };

   Cell *head;
   Cell *tail;
   int count;
   void deepCopy(const BigInt & src);
   void clear();
};

ostream & operator<<(ostream & os, BigInt & src);
#endif

