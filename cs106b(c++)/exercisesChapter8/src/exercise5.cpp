
#include "console.h"
#include "simpio.h"  // for getLine
#include "lexicon.h"
#include "set.h"
#include "exercise5.h"
#include <foreach.h>
using namespace std;

//func prototypes
void printEmbeddedWords(Set<string> &setOfEmbeddedWords);
void EmbeddedWords(Lexicon &english, string word, Set<string> &setOfEmbeddedWords);
void findEmbeddedWords(string word);

//general
void exercise5() {
    string word = getLine("Input word:");
    findEmbeddedWords(word);
}

void findEmbeddedWords(string word) {
    Lexicon english("EnglishWords.dat");
    Set<string> setOfEmbeddedWords;
    EmbeddedWords(english,word,setOfEmbeddedWords);
    printEmbeddedWords(setOfEmbeddedWords);
}

void EmbeddedWords(Lexicon &english, string word, Set<string> &setOfEmbeddedWords) {
    if (word == "") return;

    for (int i = 0; i < word.length(); i ++) {
        string subword = word.substr(0, i + 1);
        if (english.contains(subword)) setOfEmbeddedWords.add(subword);

        string restword = word.substr(i + 1, word.length());
        EmbeddedWords(english, restword, setOfEmbeddedWords);

        for (int j = i; j < word.length(); j ++) {
            string wordInDeep = subword + word.substr(j + 1, 1);
            if (english.contains(wordInDeep)) setOfEmbeddedWords.add(wordInDeep);
        }
    }
}

void printEmbeddedWords(Set<string> &setOfEmbeddedWords) {
    cout << "***********" << endl;
    foreach (string curWord in setOfEmbeddedWords) {
        cout << curWord << endl;
    }
    cout << setOfEmbeddedWords.size() << endl;
}



