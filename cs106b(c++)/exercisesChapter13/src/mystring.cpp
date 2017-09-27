
#include "mystring.h"
#include <iostream>
#include "console.h"
#include "simpio.h"
#include "error.h"

using namespace std;

const int DEFAULT_CAPACITY = 10;


   MyString::MyString(string str) {
      array = new char[DEFAULT_CAPACITY];
      capacity = DEFAULT_CAPACITY;
      count = 0;
      int i = 0;
      while (true) { 
          if (i >= capacity) expandString();
          if (str[i] == NULL) {
              array[i] = str[i];
              break;
          }
          array[i] = str[i];
          count++;
          i++;
      }
   }

  MyString::~MyString() {
       delete[] array;
   }
   string MyString::toString() const {
       string result = "";
       for (int i = 0; i < count; i++) {
           result += array[i];
       }
       return result;
   }

   int MyString::length() const {
       return count;
   }

   MyString MyString::substr(int start, int n) {
      string subStr = "";
      for (int i = start; i < start + n; i++) {
          subStr += array[i];
      }
      MyString res(subStr);
      return res;
   }
   MyString MyString::substr(int start) {
       string subStr = "";
       for (int i = start; i < count; i++) {
           subStr +=array[i];
       }
       MyString res(subStr);
       return res;
   }
   MyString & MyString::operator +(const MyString &str) {
        int summarySize = count + str.length();
        while (summarySize < capacity) {
            expandString();
        }
        for (int i = 0; i < str.length(); i++) {
            array[count] = str.array[i];
            count++;
        }
        return *this;
   }

   MyString & MyString::operator +=(const MyString &str) {
       int summarySize = count + str.length();
       while (summarySize > capacity) {
           expandString();
       }
       for (int i = 0; i < str.length(); i++) {
           array[count] = str.array[i];
           count++;
       }
       return *this;
   }

   MyString & MyString::operator +=(char str) {
       int summarySize = count + 1;
       while (summarySize > capacity) {
           expandString();
       }
       array[count] = str;
       count++;
       return *this;
   }

   ostream & operator<<(ostream & os,  MyString &src) {
       return os << src.toString();
   }

   char MyString::operator[](int index) const {
       if (index >= count ) error ("Out of bounds");
       return array[index];
   }

   bool MyString::operator == (const MyString & str) {
       if (str.length() == count) {
           int i = 0;
           while(true) {
              if (i >= count) break;
              if (str.array[i] != array[i]) break;
              i++;
           }
           if (i != count) return false;
           return true;
       } else {
           return false;
       }

   }

   bool MyString::operator >= (const MyString &str) {
       if (str.length() <= count) {
           int i = 0;
           while(true) {
              if (i >= count) break;
              if (str.array[i] > array[i]) break;
              i++;
           }
           if (i != count) return false;
           return true;
       } else {
           return false;
       }
   }

   bool MyString::operator <= (const MyString &str) {
       if (str.length() >= count) {
           int i = 0;
           while(true) {
              if (i >= count) break;
              if (str.array[i] < array[i]) break;
              i++;
           }
           if (i != count) return false;
           return true;
       } else {
           return false;
       }
   }

   bool MyString::operator != (const MyString &str) {
       if (str.length() == count) {
           int i = 0;
           while(true) {
              if (i >= count) break;
              if (str.array[i] != array[i]) break;
              i++;
           }
           if (i != count) return true;
           return false;
       } else {
           return true;
       }
   }

   bool MyString::operator> (const MyString &str) {
       if (str.length() <= count) {
           int i = 0;
           while(true) {
              if (i >= count) break;
              if (str.array[i] > array[i]) break;
              i++;
           }
           if (i != count) return false;
           return true;
       } else {
           return false;
       }
   }

   bool MyString::operator< (const MyString &str) {
       int size = 0;
       if (str.length() <= count) {
           size = str.length();
       } else {
           size = count;
       }
       for (int i = 0; i < size; i++) {
           if (array[i] >= str[i]) return false;
       }
       return true;
   }

   MyString & MyString::operator =(const MyString &str) {
       if (&str != this) {
        deepCopy(str);
       }
       return *this;
   }

   MyString::MyString (const MyString &src) {
       deepCopy(src);
   }

   void MyString::deepCopy(const MyString &src) {
       array = new char[src.capacity];
       capacity = src.capacity;
       count = src.count;
       for (int i = 0; i < count; i++) {
           array[i] = src.array[i];
       }
   }

   void MyString::expandString() {
       char *oldAr = array;
       capacity *= 2;
       char *newAr = new char[capacity];
       for (int i = 0; i < capacity; i++) {
           if (oldAr[i] == NULL) {
               newAr[i] = oldAr[i];
               break;
           }
           newAr[i] = oldAr[i];
       }
       array = newAr;
       delete[] oldAr;
   }
