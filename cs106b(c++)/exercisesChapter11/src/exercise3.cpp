#include "exercise3.h"
#include <iostream>
#include "console.h"
#include "simpio.h"
#include "grid.h"
#include "vector.h"

using namespace std;

const string ALP = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const int MIN_BASE = 2;
const int MAX_BASE = 36;

string integerToStringEx3(int n, int base);
int stringToIntegerEx3(string n, int base);
string getSign(int number);
int getInt(char ch);
bool isIllegal(string str, int base);
int getPowerOfBase (int base, int power);
string getTwoComplement(string number, int base);
string addOne(string number, int base);


void exercise3() {
    while (true) {
        int choice = getInteger("which func do you want to use: \n 1 - integerToString \n 2 - stringToInt \n 0 - close the programm \n ->");
        if (choice == 0) break;
        if (choice == 1) {
            cout << "*Integer to string*" << endl;
            int n = getInteger("Input number: ");
            int base = getInteger("Input base (2 to 36): ");
            string numStr = integerToStringEx3(n,base);
            cout << numStr << endl;

        } else if (choice == 2) {
            cout << "*String to integer*" << endl;
            string str = getLine("input string number: ");
            int n = getInteger("input base: ");
            int res = stringToIntegerEx3(str, n);
            cout << res << endl;

        } else {
           continue;
        }
        cout << endl;
     }
}


string addOne(string number, int base) {
    int curValue = stringToIntegerEx3(number,base);
    curValue += 1;
    return integerToStringEx3(curValue, base);
}

string integerToStringEx3(int n, int base) {
    if (n > 0) {
        Vector<int> reminders;
        while (n != 0) {
            int rem = n % base;
            reminders.add(rem);
            n = n / base;
        }
        string result = "";
        for (int curItem = reminders.size() - 1; curItem >= 0; curItem--) {
            result += getSign(reminders[curItem]) ;
        }
        return result;
    } else {
        int positive = (-1) * n;
        string positiveInBase = integerToStringEx3(positive, base);
        string result = getTwoComplement(positiveInBase, base);
        return result;
    }

}

string getTwoComplement(string number, int base) {
    string result = "";
    for (int i = 0; i < number.length(); i++) {
        int oneComp = ((base - 1) - getInt(number[i]));
        result += getSign(oneComp);
    }
    string twoComp = addOne(result, base);
    return twoComp;
}

int getPowerOfBase (int base, int power) {
       if (power == 0) {
           return 1;
       }
       return base * getPowerOfBase(base, power - 1);
}

int stringToIntegerEx3(string strNumber, int base) {
    if (isIllegal(strNumber,base)) {
        throw ErrorException("Value is illegal!");
    }
    int power = 0;
    int result = 0;
    for (int i = strNumber.size() - 1; i >= 0; i--) {
        int curBase = getPowerOfBase (base, power);
        int curRank = getInt(strNumber[i]) * curBase;
        result += curRank;
        power++;
    }
    return result;
}

bool isIllegal(string str, int base) {
    int start = 0;
    if (str[0] == '-') {
       start = 1;
    }
    for (int i = start; i < str.length(); i++) {
        int valueOfSign = getInt(str[i]);
        if (valueOfSign > base || valueOfSign == -1) return true;
    }
    if (base < MIN_BASE || base > MAX_BASE) return true;
    return false;
}



string getSign(int number) {
    string result = charToString(ALP[number]);
    return result;
}

int getInt(char ch) {
    for (int i = 0; i < ALP.size(); i++) {
        if (ch == ALP[i]) return i;
    }
    return -1;
}
