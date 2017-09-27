#include <iostream>
#include "console.h"
#include "gwindow.h" // for GWindow
#include "simpio.h"  // for getLine
#include "vector.h"  // for Vector
#include "fstream"
#include "filelib.h"
#include "map.h"
#include "random.h"
using namespace std;

string getRandomLetterFromSet(Vector<string> setOfLetters);
string getKeyOfSetWithMaxCountOfLetters(Map<string, Vector<string> > &seeds);
void printMarkovModel(Map<string, Vector<string> > &seeds);
void fillSeedsFromFileByOrder(ifstream &file, Map<string, Vector<string> > &seeds, int order);


int main() {
    Map<string,Vector<string> > seeds;
    ifstream file;
    string fileName = promptUserForFile(file,"Input file name: ");
    int order = getInteger("What order of Markov model to use (1 to 10): ");
    fillSeedsFromFileByOrder(file,seeds,order);
    printMarkovModel(seeds);
    file.close();
    return 0;
}

void fillSeedsFromFileByOrder(ifstream &file, Map<string, Vector<string> > &seeds, int order){
    string curSeed = "";
    while(true){
        char curChar = file.get();
        if(curChar == EOF)break;
        if(!isprint(curChar))continue;

        string curLetter = charToString(curChar);
        if(order > curSeed.length()){
            curSeed = curSeed + curLetter;
        }
        else {
            if(seeds.containsKey(curSeed)){
               seeds[curSeed].add(curLetter);
            }
            else{
                Vector<string> letters;
                letters.add(curLetter);
                seeds.add(curSeed,letters);
            }
            curSeed = curSeed.substr(1)+curLetter;
        }
        //cout << "curSeed is: " << curSeed << " curChar is: " << curChar << endl;
    }
}

void printMarkovModel(Map<string, Vector<string> > &seeds){
    string keyMax = getKeyOfSetWithMaxCountOfLetters(seeds);
    int countLetters = 0;
    string curSeed = keyMax;
    cout << "Result of work:" << endl;
    while(countLetters < 2000){
        Vector<string> curSetOfLetters = seeds[curSeed];
        if(curSetOfLetters.size() == 0)break;

        string nextLetter = getRandomLetterFromSet(curSetOfLetters);
        curSeed = curSeed.substr(1) + nextLetter;
        cout << nextLetter;
        countLetters++;
    }
}

string getKeyOfSetWithMaxCountOfLetters(Map<string, Vector<string> > &seeds){
    string keyMax = "";
    int maxSize = 0;
    Vector<string> keys = seeds.keys();
    for(int i = 0; i< keys.size(); i++){
        string curKey = keys[i];
        Vector<string> curSetOfLetters = seeds[curKey];

        /*cout << "seed " << keys[i] << " has the following leters: {";
        for(int j = 0; j < curSetOfLetters.size(); j++){
            cout << "\'" << curSetOfLetters[j] << "\',";
        }
        cout << "}" << endl;*/

        if(curSetOfLetters.size() > maxSize){
            maxSize = curSetOfLetters.size();
            keyMax = curKey;
        }
    }
    cout << "Key of seed \'" << keyMax << "\' has max " << maxSize << " letters in set" << endl;
    return keyMax;
}

string getRandomLetterFromSet(Vector<string> setOfLetters){
    int max = setOfLetters.size() - 1;
    int randomNumber = randomInteger(0,max);
    string randomLetter = setOfLetters[randomNumber];
    return randomLetter;
}





