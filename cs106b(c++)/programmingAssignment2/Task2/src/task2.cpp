#include <iostream>
#include "console.h"
#include "gwindow.h" // for GWindow
#include "simpio.h"  // for getLine
#include "vector.h"  // for Vector
#include "set.h"
#include "queue.h"
#include "lexicon.h"
#include <fstream>
using namespace std;

void showLadder(string startWord, string destinationWord);
void addNewLaddersAndTryToFind(string word,string destinationWord, Vector<string> &curLadderFromQueue, Queue<Vector<string> > &queueOfLadders,Set<string> &checkedWords, Lexicon &english, bool &pathIsFind);
void printLadder(Vector<string> &curLadder);

int main() {
    string startWord = "";
    string destinationWord = "";
    while(true){
        startWord = getLine("Enter start word: ");
        if(startWord == "") break;
        destinationWord = getLine("Enter destination word: ");
        showLadder(startWord, destinationWord);
    }
    return 0;
}

void showLadder(string startWord, string destinationWord){
    Lexicon english("EnglishWords.dat");
    bool pathIsFind = false;
    Set<string> checkedWords;
    Queue<Vector<string> > queueOfLadders;
    Vector<string> firstLadder;
    firstLadder.add(startWord);
    queueOfLadders.enqueue(firstLadder);
    while(!queueOfLadders.isEmpty()){
        if(pathIsFind) break;
        Vector<string> curLadderFromQueue = queueOfLadders.dequeue();
        for(int i = 0; i < curLadderFromQueue.size(); i++){
           if(pathIsFind) break;
           string curWord = curLadderFromQueue[i];
           if(checkedWords.contains(curWord)) continue;
           addNewLaddersAndTryToFind(curWord, destinationWord, curLadderFromQueue, queueOfLadders, checkedWords, english, pathIsFind);
           checkedWords.add(curWord);
        }
    }
    if(!pathIsFind){
        cout << "No ladder found." << endl;
    }
}

void addNewLaddersAndTryToFind(string word,string destinationWord, Vector<string> &curLadderFromQueue, Queue<Vector<string> > &queueOfLadders,Set<string> &checkedWords, Lexicon &english, bool &pathIsFind){
    for(int i = 0; i < word.length(); i++){
        if(pathIsFind) break;
        for(int j = 0; j < 26; j++){
            char curLetter = 'a'+j;
            string curWord = word;
            curWord[i] = curLetter;
            if(curWord == word) continue;
            if(!checkedWords.contains(curWord)){
                if(english.contains(curWord)){
                    Vector<string> newLadder = curLadderFromQueue;
                    newLadder.add(curWord);

                    if(curWord == destinationWord){
                       printLadder(newLadder);
                       pathIsFind = true;
                       break;
                    }
                    else{
                       queueOfLadders.enqueue(newLadder);
                       //printLadder(newLadder);
                    }

                }
                //cout << curWord << endl;
            }
        }
    }
}

void printLadder(Vector<string> &curLadder){
    cout << "Found ladder: ";
    for(int i = 0; i < curLadder.size(); i++){
        cout << curLadder[i] << " ";
    }
    cout << endl;
}
