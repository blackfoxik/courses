#ifndef _mystringlist_h
#define _mystringlist_h
#include <iostream>

using namespace std;


class MyStringList {
public:
   MyStringList(string str);
  ~MyStringList();
   string toString() const;
   int length() const;
   MyStringList substr(int start, int n);
   MyStringList substr(int start);
   MyStringList & operator +(const MyStringList &str);
   MyStringList & operator +=(const MyStringList & str);
   MyStringList & operator +=(char str);

   char operator[](int index) const;
   bool operator == (const MyStringList & str);
   bool operator >= (const MyStringList & str);
   bool operator <= (const MyStringList & str);
   bool operator != (const MyStringList & str);
   bool operator > (const MyStringList & str);
   bool operator < (const MyStringList & str);
   MyStringList &operator =(const MyStringList &str);
   MyStringList (const MyStringList & src);

private:
   struct Cell {
       char data;
       Cell *link;
   };

   //char *array;
   Cell *head;
   Cell *tail;
   int count;
   //int capacity;
   void deepCopy(const MyStringList & src);

};

ostream & operator<<(ostream & os, MyStringList & src);
#endif

