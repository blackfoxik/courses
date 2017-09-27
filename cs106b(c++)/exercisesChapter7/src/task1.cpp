#include <iostream>
#include "console.h"
#include "gwindow.h" // for GWindow
#include "simpio.h"  // for getLine
#include "vector.h"  // for Vector
#include <iomanip>
using namespace std;

void task1();
void task2();
void task3();
void task4();
void task5();
void task6();
void task7();
void task8();
void task9();
void task10();
void task11();

double getTitiusBodeDistance(int k);
int raiseToPower(int n, int k);
int cannonball(int heightOfPyramid);
int cannonballCounter(int n, int p1, int p2, int sum);
//for task3
double getTitiusBodeDistance(int k);
int getB(int k);
//for task4
int gcd (int x, int y);
//for task 5
//for task6
int fib1(int n, int &k);
int fib2(int n, int &k);
int additiveSequence(int n, int t0, int t1, int &k);
//for task7
int digitSum(int number);
//for task8
int digitalRoot(int number);
//for task9
int c(int n, int k);
//for task10
string reverse (string word);
//for task11
string intToStr(int number);

int main() {
    //task1();
    //task2();
    //task3();
    //task4();
    //task5();
    //task6();
    //task7();
    //task8();
    //task9();
    //task10();
    task11();

    cout <<"Work";
    return 0;
}



void task11() {
    int number = getInteger("Input number: ");
    cout << intToStr(number) << endl;
}

void task10() {
    string word = getLine("Input word: ");
    cout << reverse(word) << endl;
}

void task9() {
    int n = getInteger("Input n: ");
    int k = getInteger("Input k: ");
    cout << c(n,k) << endl;
}

void task8() {
    int number = getInteger("Input number: ");
    cout << digitalRoot(number) << endl;
}

void task7() {
    int number = getInteger("Input number: ");
    cout << digitSum(number) << endl;
}

void task6() {
    cout << setw(5) << "n" << setw(6) << fib1 << setw(6) << fib2 << endl;
    cout << setw(5) << "--" << setw(6) << "----" << setw(6) << "----" << endl;
    for(int i = 0 ; i <= 12; i++) {
        int k1 = 1;
        int k2 = 1;
       fib1(i,k1);
       fib2(i,k2);
       cout << setw(5) << i << setw(6) << k1 << setw(6) << k2 << endl;
    }
}

void task5() {
    int n = getInteger("Input n: ");
    int a = 0;
    int b = 1;
    for (int i = 0; i <= n; i++) {
        if (i > 1) {
            int c = a;
            a = b;
            b = a + c;
        }
    }
    if (n >0) {
        cout << b << endl;
    } else {
        cout << a << endl;
    }
}

void task4() {
    int x = getInteger("Input x: ");
    int y = getInteger("Input y: ");
    cout << gcd(x,y);
}

void task3() {
    //int k = getInteger("Input number of planet:");
    for (int k = 1; k <= 8; k++){
        cout << right<< setw(2) << k << setw(6)  << getTitiusBodeDistance(k) << " AU" <<endl;
    }

}

void task2(){
    int n = getInteger("Input n:");
    int k = getInteger("Input k:");
    cout << raiseToPower(n,k) << endl;
}

void task1() {
    while(true) {
    int heightOfPyramid = getInteger("Input height of pyramid: ");
    if(heightOfPyramid == 0) break;
    cout << "Pyramid contains " << cannonball(heightOfPyramid) << " cannonballs" << endl;
    }
}
// for task1
int cannonball(int heightOfPyramid) {
    int sumCannonball = 0;
    return cannonballCounter(heightOfPyramid, 1, 4, sumCannonball);
}

int cannonballCounter(int n, int p1, int p2,int sum ) {
    if (n == 1) return p1 + sum;
    sum += p1;
    return cannonballCounter(n - 1, p2, p1 + p2 + p2, sum);
}

//for task2
int raiseToPower(int n, int k) {
    if (k == 0) return 1;
    return n*raiseToPower(n,k-1);
}

//for task3
int getB(int k) {
    if(k == 1) return 1;
    if(k == 2) return 3;
    return getB(k-1)*2;
}

double getTitiusBodeDistance(int k) {
    int b = getB(k);
    double res = (4 + double(b)) / 10;
    return res ;
}
// for task4
int gcd (int x, int y) {
    if (x % y == 0) return y;
    return gcd(y, x % y);
}
// for task 5
//for task6
int fib1(int n, int &k) {
   if (n < 2) {
       return n;
   } else {
      return fib1(n - 1, k = k + 1) + fib1(n - 2, k = k + 1);
   }
}

int additiveSequence(int n, int t0, int t1, int &k){
    if (n == 0) return t0;
    if (n == 1) return t1;

    return additiveSequence(n - 1, t1, t0 + t1, k = k + 1 );
}

int fib2(int n, int &k) {
   return additiveSequence(n, 0, 1,k = k + 1);
}

//for task7
int digitSum(int number) {
    if (number < 10) {
        return number % 10;
    } else {
        int reminder = number % 10;
        int rem = number / 10;
        return reminder + digitSum(rem);
    }
}

//for task 8
int digitalRoot(int number) {
    int ds = digitSum(number);
    if (ds >= 10) {
       return digitalRoot(ds);
    } else {
        return ds;
    }
}
//for task9
int c(int n, int k) {
    if(k == 0 || k == n) return 1;
    return c(n - 1, k - 1) + c(n - 1, k);
}

//for task10
string reverse (string word) {
    if (word.size() == 1) return word;
    return word.substr(word.size()-1) + reverse(word.substr(0,word.size() - 1));
}
//for task11
string intToStr(int number) {
    if (number < 10) {
        string s = to_string(number);
        return s;
    } else {
        int reminder = number % 10;
        int rem = number / 10;
        char s = reminder + '0';
        return intToStr(rem) + "" + s;
    }
}
