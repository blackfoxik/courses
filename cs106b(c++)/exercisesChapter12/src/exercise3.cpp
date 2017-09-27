
#include "exercise3.h"
#include <iostream>
#include "console.h"
#include "simpio.h"
#include <fstream>
#include "tokenscanner.h"

using namespace std;

struct Tower {
    string name;
    Tower *link;
};

//func prototypes
Tower *readBeaconsFromFile(string filename);
Tower *createTower(string name, Tower *link);
void signal (Tower *start);
string *addCurToken(string *names, string curName, int curSize);
string *getNamesFromFile(string filename, int & countOfNames);

void exercise3() {
    string filename = "towers.txt";
    Tower *list = readBeaconsFromFile(filename);
    signal(list);
}

Tower *readBeaconsFromFile(string filename) {
    //first take all name from file, second make a Tower for each name;
    int countOfNames = 0;
    string *names = getNamesFromFile(filename, countOfNames);

    Tower *tp = createTower(names[countOfNames - 1],NULL);
    for (int i = countOfNames - 2; i >= 0; i--) {
        tp = createTower(names[i],tp);
    }
    return tp;
}

string *getNamesFromFile(string filename, int & countOfNames) {
    ifstream infile;
    infile.open(filename.c_str());
    TokenScanner scanner(infile);
    scanner.ignoreWhitespace();
    scanner.addWordCharacters(" ");
    scanner.addWordCharacters("-");
    string *names = new string[0];
         while(scanner.hasMoreTokens()) {
             string curToken = scanner.nextToken();
             names = addCurToken(names, curToken, countOfNames);
             countOfNames++;
         }
    infile.close();
    return names;
}

string *addCurToken(string *names, string curName, int curSize) {
    if (curName == "") return names;
    string *newNames = new string[curSize + 1];
    for (int i = 0; i < curSize; i++) {
        newNames[i] = names[i];
    }
    newNames[curSize] = curName;
    delete[] names;
    return newNames;
}

Tower *createTower(string name, Tower *link) {
    Tower *tp = new Tower;
    tp->name = name;
    tp->link = link;
    return tp;
}

void signal(Tower *start) {
    for (Tower *tp = start; tp != NULL; tp = tp->link) {
        cout << "Lighting " << tp->name << endl;
    }
}

