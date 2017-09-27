
#include "mystringlist.h"
#include <iostream>
#include "console.h"
#include "simpio.h"
#include "error.h"

using namespace std;

   MyStringList::MyStringList(string str) {
      if (str == "") {
          count = 0;
          head = tail = NULL;
          return;
      }
      head = tail = NULL;
      count = 0;
      int i = 0;
      while (true) {
          Cell *cp = new Cell;
          cp->data = str[i];
          cp->link = NULL;
          if (head == NULL) {
             head = cp;
             tail = cp;
             i++;
             count++;
             continue;
          }
          tail->link = cp;
          tail = cp;
          count++;
          i++;
          if (str[i] == NULL) {
              break;
          }
      }
   }

  MyStringList::~MyStringList() {
      while (true) {
        Cell *oldHead = head;
        head = head->link;
        delete oldHead;
        if(head->link == NULL) {
            delete head;
            break;
        }
      }
   }
   string MyStringList::toString() const {
       string result = "";
       Cell *cp = head;
       while (true) {
           result += cp->data;
           if (cp->link == NULL) {
               break;
           }
           cp = cp->link;
       }
       return result;
   }

   int MyStringList::length() const {
       return count;
   }

   MyStringList MyStringList::substr(int start, int n) {
      string subStr = "";
      Cell *cp = head;
      int curPos = 0;
      while (curPos < start) cp = cp ->link;
      for (int i = start; i < start + n; i++) {   
          subStr += cp->data;
          cp = cp->link;
      }
      MyStringList res(subStr);
      return res;
   }
   MyStringList MyStringList::substr(int start) {
       string subStr = "";
       Cell *cp = head;
       int curPos = 0;
       while (curPos < start) cp = cp ->link;
       for (int i = start; i < count; i++) {
           subStr += cp->data;
           cp = cp->link;
       }
       MyStringList res(subStr);
       return res;
   }
   MyStringList & MyStringList::operator +(const MyStringList &str) {
        for (int i = 0; i < str.length(); i++) {
            Cell *cp = new Cell;
            cp->data = str[i];
            cp->link = NULL;
            tail->link = cp;
            tail = cp;
            count++;
        }
        return *this;
   }

   MyStringList & MyStringList::operator +=(const MyStringList &str) {
       for (int i = 0; i < str.length(); i++) {
           Cell *cp = new Cell;
           cp->data = str[i];
           cp->link = NULL;
           tail->link = cp;
           tail = cp;
           count++;
       }
       return *this;
   }

   MyStringList & MyStringList::operator +=(char str) {
       Cell *cp = new Cell;
       cp->data = str;
       cp->link = NULL;
       tail->link = cp;
       tail = cp;
       count++;
       return *this;
   }

   ostream & operator<<(ostream & os,  MyStringList &src) {
       return os << src.toString();
   }

   char MyStringList::operator[](int index) const {
       if (index >= count ) error ("Out of bounds");
       Cell *cp = head;
       while(index > 0) {
           cp = cp->link;
           index--;
       }
       return cp->data;
   }

   bool MyStringList::operator == (const MyStringList & str) {
       if (str.length() == count) {
           int i = 0;
           Cell *cp = head;
           while(true) {
              if (i >= count) break;
              if (str[i] != cp->data) break;
              cp = cp->link;
              i++;
           }
           if (i != count) return false;
           return true;
       } else {
           return false;
       }

   }

   bool MyStringList::operator >= (const MyStringList &str) {
       if (str.length() <= count) {
           int i = 0;
           Cell *cp = head;
           while(true) {
              if (i >= count) break;
              if (str[i] > cp->data) break;
              cp = cp->link;
              i++;
           }
           if (i != count) return false;
           return true;
       } else {
           return false;
       }
   }

   bool MyStringList::operator <= (const MyStringList &str) {
       if (str.length() >= count) {
           int i = 0;
           Cell *cp = head;
           while(true) {
              if (i >= count) break;
              if (str[i] < cp->data) break;
              cp = cp->link;
              i++;
           }
           if (i != count) return false;
           return true;
       } else {
           return false;
       }
   }

   bool MyStringList::operator != (const MyStringList &str) {
       if (str.length() == count) {
           int i = 0;
           Cell *cp = head;
           while(true) {
              if (i >= count) break;
              if (str[i] != cp->data) break;
              cp = cp->link;
              i++;
           }
           if (i != count) return true;
           return false;
       } else {
           return true;
       }
   }

   bool MyStringList::operator> (const MyStringList &str) {
       if (str.length() <= count) {
           int i = 0;
           Cell *cp = head;
           while(true) {
              if (i >= count) break;
              if (i >=str.length()) break;
              if (str[i] > cp->data) break;
              cp = cp->link;
              i++;
           }
           if (i != count) return false;
           return true;
       } else {
           return false;
       }
   }

   bool MyStringList::operator< (const MyStringList &str) {
       int size = 0;
       if (str.length() <= count) {
           size = str.length();
       } else {
           size = count;
       }
       Cell *cp = head;
       for (int i = 0; i < size; i++) {
           if (cp->data >= str[i]) return false;
           cp = cp->link;
       }
       return true;
   }

   MyStringList & MyStringList::operator =(const MyStringList &str) {
       if (&str != this) {
        deepCopy(str);
       }
       return *this;
   }

   MyStringList::MyStringList (const MyStringList &src) {
       deepCopy(src);
   }

   void MyStringList::deepCopy(const MyStringList &src) {
       if (head != NULL) {
           while (true) {
               Cell *oldHead = head;
               head = head->link;
               delete oldHead;
               if (head->link == NULL) {
                   delete head;
                   delete tail;
                   break;
               }
              }
       }
       head = NULL;
       tail = NULL;
       count = 0;
       if (src.length() == 0) {
           return;
       }
       head = new Cell;
       tail = new Cell;
       count = src.count;
       if (src.count == 1) {
           head->data = src[0];
           head->link = tail;
           tail->data = src[0];
           tail->link = NULL;
           return;
       }

       head->data = src[0];
       head->link = tail;
       for (int i = 1; i < count; i++) {
           Cell *cp = new Cell;
           cp->data = src[i];
           cp->link = NULL;
           tail->link = cp;
           tail = cp;
       }
   }


