//
//  main.cpp
//  Task2
//
//  Created by Anton on 18.08.16.
//  Copyright © 2016 Anton. All rights reserved.
//

#include <iostream>
#include "random.h"

using std::cout;
using std::cin;
using std::string;
//using std::double;
const int COUNT_TRIALS = 500;

int getCountOfVoters(){
    int countOfVoters = 0;
    
    while(countOfVoters<=0){
        cout<<"Enter number of voters:";
        cin>>countOfVoters;
        if(countOfVoters<=0){
            cout<<"Please try again. Number of voters must be more than 0.\n";
        }
    }
    return countOfVoters;
}
double getPercentage(string percentageName){
    double percentage = 0;
    while(true){
        cout<<"Enter "+percentageName;
        cin>>percentage;
        if(percentage<0||percentage>1.0){
            cout<<"Please try again, "+percentageName+" must be from 0 to 1.0.\n";
        }
        else{
            break;
        }
    }
    return percentage;
}


int getWrongVotes(int votesForCandidate, double voitingErrorPercentage){
    int wrongVotes = 0;
    for (int i=0; i<votesForCandidate;i++){
        if(randomChance(voitingErrorPercentage)){
            wrongVotes++;
        }
    }
    return wrongVotes;
}

bool processTrial(int voters, double percentageSpread, double voitingErrorPercentage){
    int votesForCandidateA = (0.5*voters)+(voters*percentageSpread);
    int votesForCandidateB = (0.5*voters)-(voters*percentageSpread);
    
    int wrongVotesA = getWrongVotes(votesForCandidateA,voitingErrorPercentage);
    int wrongVotesB = getWrongVotes(votesForCandidateB,voitingErrorPercentage);
    
    int recordsForA = votesForCandidateA - wrongVotesB + wrongVotesA;
    int recordsForB = votesForCandidateB - wrongVotesA + wrongVotesB;
    
    if(recordsForB>recordsForA){
        return true;
    }
    else{
        return false;
    }
}
void showChanceOfInvalidElection(int voters, double percentageSpread, double voitingErrorPercentage){
    int countOfInvalidResult = 0;
    for(int i=0; i< COUNT_TRIALS; i++){
        //body of process trial
        bool resultInvalid = processTrial(voters,percentageSpread,voitingErrorPercentage);
        if(resultInvalid){
            countOfInvalidResult++;
        }
    }
    double result = double(countOfInvalidResult)/double(COUNT_TRIALS)*100;
    cout<<"Chance of an invalid election result after 500 trials = "+std::to_string(result)+"%\n";
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int voters = getCountOfVoters();
    double percentageSpread = getPercentage("percentage spread between candidates:");
    double voitingErrorPercentage = getPercentage("voting error percentage:");
    showChanceOfInvalidElection(voters,percentageSpread,voitingErrorPercentage);
    
    return 0;
}
