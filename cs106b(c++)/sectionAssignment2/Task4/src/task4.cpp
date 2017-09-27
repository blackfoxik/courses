#include <iostream>
#include "console.h"
#include "gwindow.h" // for GWindow
#include "simpio.h"  // for getLine
#include "vector.h"  // for Vector
#include "map.h"
#include "filelib.h"
#include "fstream"
using namespace std;

char MostFrequentCharacter(ifstream &file,int &numOccurrences){
    Map<char,int> occurs;
    while(true){
        char curChar = file.get();
        if(curChar == EOF) break;
        if(isalpha(curChar)){
            if(occurs.containsKey(curChar)){
                occurs[curChar]+=1;
            }
            else{
                occurs.add(curChar,1);
            }
        }
    }

    char chMax = '/0';
    Vector<char> keys = occurs.keys();
    for(int i = 0; i < occurs.size(); i++){
        cout << " key: "<< keys[i] << endl;
        if(occurs[keys[i]]>numOccurrences){
            numOccurrences = occurs[keys[i]];
            chMax = keys[i];
        }
    }
    return chMax;
}

int main() {
    ifstream file;
    string fileName = promptUserForFile(file,"Input file name: ");

    int numOccurrences = 0;
    char mostFrequentChar =  MostFrequentCharacter(file, numOccurrences);

    cout<< "char: " << mostFrequentChar << " occured: " << numOccurrences << " times" << endl;
    file.close();
    return 0;
}
