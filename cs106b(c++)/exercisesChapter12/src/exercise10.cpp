#include "exercise10.h"
#include "mystring.h"
#include <string>
#include <cctype>

using namespace std;
//func prototype

MyString lineToPigLatin(MyString line);
MyString wordToPigLatin(MyString word);
int findFirstVowel(MyString word);
bool isVowel(char ch);

//general
void exercise10() {
    cout << "Transalte english to pig latin" << endl;
    string lineStr;
    cout << "Input english text: ";
    getline(cin, lineStr);
    MyString line(lineStr);
    MyString translation = lineToPigLatin(line);
    cout << "Pig Latin output: " << translation << endl;
}

MyString lineToPigLatin(MyString line) {
    MyString result("");
    int start = -1;
    for (int i = 0; i < line.length(); i++) {
        char ch = line[i];
        if (isalpha(ch)) {
            if (start == -1) start = i;
        } else {
            if (start >= 0) {
                result += wordToPigLatin(line.substr(start, i - start));
                start = -1;
            }
            result += ch;
        }
    }
    if (start >= 0) result +=wordToPigLatin(line.substr(start));
    return result;
}

MyString wordToPigLatin(MyString word) {
    int vp = findFirstVowel(word);
    if (vp == -1) {
        return word;
    } else if (vp == 0) {
        return MyString(word.toString() + "way");
    } else {
        MyString head = word.substr(0, vp);
        MyString tail = word.substr(vp);
        return MyString(tail.toString() + head.toString() + "ay");
    }
}

int findFirstVowel(MyString word) {
    for (int i = 0; i < word.length(); i++) {
        if (isVowel(word[i])) return i;
    }
    return -1;
}

bool isVowel(char ch) {
    switch (ch) {
        case 'A': case 'E': case 'I': case 'O': case 'U':
        case 'a': case 'e': case 'i': case 'o': case 'u':
            return true;
        default:
            return false;
    }
}

/*
//original code
string lineToPigLatin(string line);
string wordToPigLatin(string word);
int findFirstVowel(string word);
bool isVowel(char ch);

//general
void exercise10() {
    cout << "Transalte english to pig latin" << endl;
    string line;
    cout << "Input english text: ";
    getline(cin, line);
    string translation = lineToPigLatin(line);
    cout << "Pig Latin output: " << translation << endl;
}

string lineToPigLatin(string line) {
    string result;
    int start = -1;
    for (int i = 0; i < line.length(); i++) {
        char ch = line[i];
        if (isalpha(ch)) {
            if (start == -1) start = i;
        } else {
            if (start >= 0) {
                result += wordToPigLatin(line.substr(start, i - start));
                start = -1;
            }
            result += ch;
        }
    }
    if (start >= 0) result +=wordToPigLatin(line.substr(start));
    return result;
}

string wordToPigLatin(string word) {
    int vp = findFirstVowel(word);
    if (vp == -1) {
        return word;
    } else if (vp == 0) {
        return word + "way";
    } else {
        string head = word.substr(0, vp);
        string tail = word.substr(vp);
        return tail + head + "ay";
    }
}

int findFirstVowel(string word) {
    for (int i = 0; i < word.length(); i++) {
        if (isVowel(word[i])) return i;
    }
    return -1;
}

bool isVowel(char ch) {
    switch (ch) {
        case 'A': case 'E': case 'I': case 'O': case 'U':
        case 'a': case 'e': case 'i': case 'o': case 'u':
            return true;
        default:
            return false;
    }
}
*/


