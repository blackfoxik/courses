#ifndef _mystring_h
#define _mystring_h
#include <iostream>

using namespace std;

class MyString {
public:
   MyString(string str);
  ~MyString();
   string toString() const;
   int length() const;
   MyString substr(int start, int n);
   MyString substr(int start);
   MyString & operator +(const MyString &str);
   MyString & operator +=(const MyString & str);
   MyString & operator +=(char str);

   char operator[](int index) const;
   bool operator == (const MyString & str);
   bool operator >= (const MyString & str);
   bool operator <= (const MyString & str);
   bool operator != (const MyString & str);
   bool operator > (const MyString & str);
   bool operator < (const MyString & str);
   MyString &operator =(const MyString &str);
   MyString (const MyString & src);

private:
   char *array;
   int count;
   int capacity;
   void deepCopy(const MyString & src);
   void expandString();
};

ostream & operator<<(ostream & os, MyString & src);
#endif

