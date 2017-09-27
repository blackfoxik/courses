#include <iostream>
#include <fstream>
#include <vector>
using std::cout;
using std::cin;
using std::string;
using std::ifstream;

void countLetters(string fileName);


int main(int argc, const char * argv[]) {
    // insert code here...
    string fileName = "/Users/anton/Documents/workspace/cs106b/sectionAssignment1/problem3/problem3/text.txt";
    countLetters(fileName);
    return 0;
}

void countLetters(string fileName){
    string alphabet[] = {"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"};
    //int occurences[26];
    std::vector<int>occurences = {};
    for (int i=0;i<26;i++){
        occurences.push_back(0);
    }
    
    ifstream myFile;
    myFile.open(fileName);
    string line = "";
    while(getline(myFile, line)){
        std::transform(line.begin(), line.end(),line.begin(),::tolower);
        for(int i = 0;i<line.length();i++){
            for(int j = 0; j< 26;j++){
                if(line[i] == alphabet[j][0]){
                    occurences[j]++;
                    break;
                }
            }
        }
    }
    myFile.close();
    for(int i=0; i<26; i++){
        cout<< alphabet[i]+": "+std::to_string(occurences[i])+"\n";
    }
}