//
//  main.cpp
//  sectionAssignment1
//
//  Created by Anton on 12.08.16.
//  Copyright © 2016 Anton. All rights reserved.
//

#include <iostream>
using std::cout;
using std::cin;
using std::string;

string censorString(string text, string pattern){
    string result = text;
    for(int i = 0; i<pattern.length();i++){
        char curSignPattern = pattern[i];
        string curResult = "";
        for(int j = 0; j<result.length();j++){
            char curSignText = result[j];
            if(curSignPattern != curSignText){
                curResult += curSignText;
            }
        }
        result = curResult;
    }
    return result+"\n";
}
int censorString2(string &text,string pattern){
    for(int i = 0; i<pattern.length();i++){
        for( int j=0; j<text.length();j++){
            if(pattern[i]==text[j]){
                text.erase(j,1);
            }
        }
    }
    return 0;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    cout << "Input text: ";
    string text = "";
    getline(cin, text);
 
    
    cout << "Input remove pattern: ";
    string pattern = "";
    cin >> pattern;
    cout << censorString(text,pattern);
    cout << "-----------second function---------\n";
    censorString2(text,pattern);
    cout << " text: "+text+"\n";
    
    
    
    
    return 0;
}

