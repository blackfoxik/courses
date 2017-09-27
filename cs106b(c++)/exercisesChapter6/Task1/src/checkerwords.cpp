#include <iostream>
#include <string>
#include "checkerwords.h"
#include <fstream>
#include "lexicon.h"
#include "tokenscanner.h"
#include "simpio.h"
using namespace std;


void chooseFile(ifstream &infile);



    CheckerWords::CheckerWords() {

    }

  void CheckerWords::Run() {
      ifstream infile;
      chooseFile(infile);
      Lexicon english("EnglishWords.dat");
      TokenScanner scanner(infile);
      while(scanner.hasMoreTokens()) {
          string curToken = scanner.nextToken();
          if ( (curToken != "," && curToken != "." && curToken != ";" && curToken != " " && curToken != ":" )&&(!isdigit(curToken[0]))){
          if ( !english.contains(curToken)) {
              cout << "\"" << curToken << "\""<< "is not in the dictionary" << endl;
          }
          }
      }

      infile.close();
      //return 0;
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
