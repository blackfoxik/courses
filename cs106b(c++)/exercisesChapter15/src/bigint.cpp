
#include "bigint.h"
#include <iostream>
#include "console.h"
#include "simpio.h"
#include "error.h"
#include "strlib.h"


using namespace std;
    BigInt::BigInt() {
      head = tail = NULL;
      count = 0;
    }

   BigInt::BigInt(string str) {
      head = tail = NULL;
      count = 0;
      if (str == "") {
          return;
      }

      int i = 0;
      while (true) {
          Cell *cp = new Cell;
          cp->data = charToInteger(str[i]);
          cp->link = head;
          if (head == NULL) {
             head = cp;
             tail = cp;
             tail->link = NULL;
             i++;
             count++;
             if (str[i] == NULL) break;
             continue;
          }
          cp->link = head;
          head = cp;

          count++;
          i++;
          if (str[i] == NULL) {
              break;
          }
      }
   }

  BigInt::BigInt(int number) {
      head = tail = NULL;
      count = 0;
      int curNumber = number;
      while (true) {
          Cell *cp = new Cell;
          int reminder = curNumber % 10;
          curNumber = curNumber / 10;
          cp->data = reminder;
          cp->link = NULL;
          if (head == NULL) {
              head = cp;
              tail = cp;
              count++;
              if (curNumber == 0) {
                  break;
              }
              continue;
          }
          tail->link = cp;
          tail = cp;
          count++;
          if (curNumber == 0) break;
      }
  }

  BigInt::~BigInt() {
      while (true) {
        Cell *oldHead = head;
        head = head->link;
        delete oldHead;
        if(head == NULL) {
            //delete head;
            break;
        }
      }
   }

   void reverse(string &str) {
       if (str.length() == 1 || str == "") return;
       int mid = str.length() / 2;
       int i = 0;
       while(i < mid) {
           char tmp = str[i];
           str[i] = str[str.length() - 1 - i];
           str[str.length() - 1 - i] = tmp;
           i++;
       }
   }

   string BigInt::toString() const {
       string result = "";
       Cell *cp = head;
       int i = 0;
       while (i < count) {
           result += integerToChar(cp->data);
           if (cp->link == NULL) {
               break;
           }
           cp = cp->link;
           i++;
       }
       reverse(result);
       return result;
   }

   int BigInt::length() const {
       return count;
   }

   BigInt operator+(const BigInt &str1, const BigInt &str2) {
       int i = 0;
       int prevEx = 0;
       string res = "";
       while (true) {

           int v1 = 0;
           if(i < str1.length()) v1 = str1[i];


           int v2 = 0;
           if(i < str2.length()) v2 = str2[i];
           i++;

           int curSum = v1 + v2 + prevEx;
           if (curSum >= 10) {
               prevEx = 1;
               curSum = curSum % 10;
           } else {
              prevEx = 0;
           }

           if (i >= str1.length() && i >= str2.length() && prevEx != 0) {
              //curSum += prevEx;
           }

           res += integerToString(curSum);


           if (i >= str1.length() && i >= str2.length() && prevEx == 0) break;
       }
       reverse(res);
       BigInt *copy = new BigInt(res);
       return *copy;
   }

   void BigInt::clear() {
       while (head != NULL) {
         Cell *nextCell = head->link;
         delete head;
         head = nextCell;
       }
       tail = head = NULL;
       count = 0;
   }

   BigInt & BigInt::operator +=(const BigInt &str) {

        Cell *hA = head;
        int i = 0;
        int prevEx = 0;
        string res = "";
        while (true) {

            int v1 = 0;
            if(hA != NULL) {
                v1 = hA->data;
                hA = hA->link;
            }

            int v2 = 0;
            if(i < str.length()) v2 = str[i];
            i++;

            int curSum = v1 + v2 + prevEx;
            if (curSum >= 10) {
                prevEx = 1;
                curSum = curSum % 10;
            } else {
               prevEx = 0;
            }
            if (hA == NULL && i >= str.length() && prevEx != 0) {
               //curSum += prevEx;
            }
            res += integerToString(curSum);

            if (hA == NULL && i >= str.length() && prevEx == 0) break;
        }
        reverse(res);
        clear();
        BigInt *copy = new BigInt(res);
        *this = *copy;
        return *this;

   }

   BigInt operator*(const BigInt &str1, const BigInt &str2) {

       int i = 0;
       int prevEx = 0;
       string curRes = "";
       string res = "";
       BigInt result;

          for (int j = 0; j < str2.length(); j++) {
           for (int i = 0; i < str1.length(); i++) {
             int v1 = 1;
             if(i < str1.length()) v1 = str1[i];
             int v2 = 1;
             if(j < str2.length()) v2 = str2[j];
             int curSum = v1 * v2 + prevEx;
             if (curSum >= 10) {
                 prevEx = curSum / 10;
                 curSum = curSum % 10;
             } else {
                prevEx = 0;
             }
             curRes += integerToString(curSum);
           }
           if(prevEx != 0) {
               curRes += integerToString(prevEx);
               prevEx = 0;
           }
           for (int k = j; k > 0; k--) {
               curRes = "0" + curRes;
           }
            reverse(curRes);
            BigInt tmpRes(curRes);
            result += tmpRes;
            curRes = "";
       }

       return result;

   }

   ostream & operator<<(ostream & os,  BigInt &src) {
       return os << src.toString();
   }

   int &BigInt::operator[](int index) const {
       if (index >= count ) error ("Out of bounds");
       Cell *cp = head;
       while(index > 0) {
           cp = cp->link;
           index--;
       }
       return cp->data;
   }

   BigInt & BigInt::operator =(const BigInt &str) {
       if (&str != this) {
        clear();
        deepCopy(str);
       }
       return *this;
   }

   BigInt::BigInt (const BigInt &src) {
       deepCopy(src);
   }

   void BigInt::deepCopy(const BigInt &src) {
       head = tail = NULL;
       count = 0;
       if (src.length() == 0) {
           return;
       }
       head = new Cell;
       count = src.count;
       if (src.count == 1) {
           tail = new Cell;
           head->data = src[0];
           head->link = tail;
           tail->data = src[0];
           tail->link = NULL;
           return;
       }

       head->data = src[0];
       for (int i = 1; i < count; i++) {
           if (tail == NULL) {
               tail = new Cell;
               tail->data = src[i];
               tail->link = NULL;
               head->link = tail;
               continue;
           }
           Cell *cp = new Cell;
           cp->data = src[i];
           cp->link = NULL;
           tail->link = cp;
           tail = cp;
       }
   }


