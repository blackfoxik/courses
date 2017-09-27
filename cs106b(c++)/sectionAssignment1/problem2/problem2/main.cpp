//
//  main.cpp
//  problem2
//
//  Created by Anton on 12.08.16.
//  Copyright © 2016 Anton. All rights reserved.
//

#include <iostream>
#include <fstream>
using std::cout;
using std::cin;
using std::string;
using std::ifstream;

struct stat {
    int max;
    int min;
    double average;
};

int main(int argc, const char * argv[]) {
    // insert code here...
    ifstream myFile;
    string line = "";
    stat myStat;
    myStat.max = 0;
    myStat.min = 100;
    myStat.average = 0;
    int sum = 0;
    int count = 0;
    myFile.open("/Users/anton/Documents/workspace/cs106b/sectionAssignment1/problem2/problem2/stat.txt");
    while(getline(myFile, line)){
        cout << line+"\n";
        int curValue = std::stoi(line);
        if(curValue > myStat.max){
            myStat.max = curValue;
        }
        if(curValue < myStat.min){
            myStat.min = curValue;
        }
        sum += curValue;
        count++;
    }
    myStat.average = (double)sum/(double)count;
    myFile.close();
    cout << "MAX: "+std::to_string(myStat.max)+" MIN: "+std::to_string(myStat.min)+" AVERAGE: "+std::to_string(myStat.average)+"\n";
    return 0;
}
