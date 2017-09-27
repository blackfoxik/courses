#include "exercise1.h"
#include <iostream>
#include "console.h"
#include "simpio.h"
#include "grid.h"
#include "vector.h"


#include "exercise2.h"

//func prototype
char *copyCString(char *str);
void printStr(char *str);

void exercise2() {
    char original[] = "original";
    char *copy = copyCString(original);
    printStr(copy);
    delete[] copy;
}

char *copyCString(char *str) {
    int n = 0;
    while (true) {
        if (str[n] == NULL) break;
        n++;
    }
    char *newStr = new char[n + 1];
    for (int i = 0; i < n; i++) {
        newStr[i] = str[i];
    }
    newStr[n + 1] = NULL;
    return newStr;
}

void printStr(char *str) {
    int n = 0;
    while (true) {
       if (str[n] == NULL) break;
       cout << str[n];
       n++;
    }
    cout << endl;
}
