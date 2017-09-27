#include <iostream>
#include "console.h"
#include "gwindow.h" // for GWindow
#include "simpio.h"  // for getLine
#include "vector.h"  // for Vector
#include "domino.h"
#include "card.h"
#include "gtypes.h"
#include "paintertask4.h"
#include "calendar.h"
#include "labelgen.h"
#include "rational.h"
//for task 9
#include "rpnrationalcalculator.h"

//task10
#include "checkerwords.h"

//task11
#include "simplecalculator.h"
using namespace std;

void task1();
void task2();
void task4();
void task5();
void task6();
void task8();
void task9();
void task10();
void task11();
void task12();
void task13();

int main() {
    //task1();
    //task2();
    //task3();// we had to just implement it

    //task4();
    //task5();
    //task6();
    //task8();
    //task9();
    //task10();
    //task11();
    task12();
    cout <<"Work";
    return 0;
}

void task1(){
   Vector<Domino> setOfDomino;
   for(int i = 0; i <= 6; i++){
       for(int j = 0; j <= 6; j++){
           if(j >= i){
               Domino curDomino(i,j);
               setOfDomino.add(curDomino);
           }
       }
   }
   for(int i = 0; i < setOfDomino.size(); i++){
       cout << setOfDomino[i] << endl;
   }
   cout << setOfDomino.size() <<endl;
}
void task2(){
    for(Suit suit = CLUBS; suit <= SPADES; suit++) {
        for(Rank rank = ACE; rank <= KING; rank++) {
            cout << " " << Card(rank, suit);
        }
        cout << endl;
    }
}

void task4() {
    PainterTask4 paint;
    paint.draw();
}

void task5() {
    Date electionDay(6, NOVEMBER, 2012);
    Date inaugurationDay(21, JANUARY, 2013);
    int dif = inaugurationDay - electionDay;
    cout << dif << endl;
    for (Date d = electionDay; d <= inaugurationDay; d++) {
        cout << d << endl;
    }
}

void task6() {
   LabelGenerator figureNumbers ("Figure ", 1);
   LabelGenerator pointNumbers ("P", 0);
   cout << "Figure numbers: ";
   for (int i = 0; i < 3; i++) {
       if(i > 0) cout << ", ";
       cout << figureNumbers.nextLabel();
   }
   cout << endl << "Point numbers: ";
   for (int i = 0; i < 5; i++) {
       if(i > 0) cout << ", ";
       cout << pointNumbers.nextLabel();
   }
   cout << endl << "More figures: ";
   for (int i = 0; i < 3; i++) {
       if(i > 0) cout << ", ";
       cout << figureNumbers.nextLabel();
   }
   cout << endl;
}

void task8(){
  Rational r1(1,2);
  Rational r2(1,2);
  Rational r3 = --r1;
  r1 /= r2;
  bool resLess = r1< r2;
  bool eqLess = r1 <= r2;
  bool more = r1 > r2;
  bool moreEq = r1 >= r2;
  cout <<  r1 << endl;
  cout << "r3 = " << r3 << endl;
}

void task9() {
    RPNRationalCalculator calculator;
    calculator.Run();
}

void task10() {
 CheckerWords checker;
 checker.Run();
}

void task11() {
    SimpleCalculator calc;
    calc.run();
}

void task12() {
    SimpleCalculator calc;
    calc.runWithAssignmentStatements();
}

void task13() {
    //this code only for presentation, because in lib we already have implementation of this method
   /* in interface we shold implement
            public saveToken(string curToken);
            private: Stack<string> tokens;
    in cpp
            void TokenScanner::saveToken(string curToken) {
                tokens.push(curToken);
            }
            string void TokenScanner::nextToken() {
                return tokens.pop();
            } */
}

void task14() {
     //this code only for presentation, because in lib we already have implementation of this method
    /*in nextToken method we should use the code:
        if (scanStrings) {
          if (curToken == '"' || curToken =='\'' && startPosition == 0) {
               while(true) {
                   curToken = getNextToken();
                   if( curToken == '"'|| curToken == '\'') {
                       curString = "\""+curString+"\"";
                       startPosition = 1;
                       break;
                   } else {
                       curString += curString;
                   }
               }

          }
          else {
              return curToken;
          }
          if (startPosition == 1) {
              startPosition = 0;
              return curString;
          }
          else {
              return error("There is not close quote sign in text");
          }
        }
    else {
        //usual code
    }*/
}

void task15() {
     //this code only for presentation, because in lib we already have implementation of this method
    /*if(scanNumbers) {
        string token = "";
        while(true){
            char curChar = getChar();
            if( isdigit(curChar)){
                token_=curChar;
            }
            if(curChar == '.' && !pointState && !exponentState && isdigit(nextChar)){
                token += curChar;
                pointState = true;
                continue;
            }
            if(curChar == 'E' && pointState && (nextChar == '+' || nextChar == '-') ) {
                token += curChar;
                exponentState = true;
                continue;
            }
            if(!isdigit(curChar) && exponentState && pointState) {
                break;
            }
        }
        return token;*/
    }


