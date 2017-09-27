//
//  main.cpp
//  Task1
//
//  Created by Anton on 15.08.16.
//  Copyright © 2016 Anton. All rights reserved.
//

#include <iostream>
using std::cout;

const int RANGE = 10000;

int main(int argc, const char * argv[]) {
    // insert code here...
    for(int i = 1; i<RANGE;i++){
        int sumOfDivisor = 0;
        for(int j=1; j<i-1;j++){
            if(i%j==0){
                sumOfDivisor+=j;
            }
        }
        if(sumOfDivisor==i){
            cout << std::to_string(i)+"\n";
        }
    }
    return 0;
}
