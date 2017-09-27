#include <iostream>
#include "console.h"
#include "gwindow.h" // for GWindow
#include "simpio.h"  // for getLine
#include "vector.h"  // for Vector
#include "strlib.h"
#include <fstream>
using namespace std;

void chooseFile(ifstream &infile);
int getCurrentIndex(Vector<int> numbers, int curStep);
string getLineWithX(int curIndex);
void getNumbersFromFile(ifstream &infile,Vector<int> &numbers);
void showHistogram(ifstream &infile);

int main() {
    ifstream infile;
    chooseFile(infile);
    showHistogram(infile);
    infile.close();
    return 0;
}

void chooseFile(ifstream &infile){
    string fileName="";
    //cout<<"Input file name:";
    //cin>>fileName;
    fileName = getLine("Input file name:");
    while(true){
        infile.open(fileName.c_str());
        if(!infile.fail()) break;
        cout<<"Incorrect file name, try again"<<endl;
        fileName = getLine("Input file name:");
        infile.clear();
    }
}

void showHistogram(ifstream &infile){
    string line = "";
    Vector<int> numbers;
    getNumbersFromFile(infile,numbers);

    for(int i = 0; i < 100; i+=10){
        int curIndex = getCurrentIndex(numbers,i);
        string curIndexAsLineWithX = getLineWithX(curIndex);
        cout<< i << "-" << i+9 << ": " << curIndexAsLineWithX << endl;
    }

}

int getCurrentIndex(Vector<int> numbers, int curStep){
    int curIndex = 0;
    for(int j = 0; j < numbers.size(); j++){
       int curNumber = numbers.get(j);
       if(curNumber<=(curStep+9)&&curNumber>=(curStep))curIndex++;
    }
    return curIndex;
}

string getLineWithX(int curIndex){
    string curIndexAsLineWithX = "";
    for(int j = 0; j< curIndex; j++){
        curIndexAsLineWithX +="X";
    }
    return curIndexAsLineWithX;
}

void getNumbersFromFile(ifstream &infile,Vector<int> &numbers){
    string line = "";
    while(getline(infile,line)){
        if(infile.eof())break;
        int curNumber = stringToInteger(line);
        numbers.push_back(curNumber);
    }
}

