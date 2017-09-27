
#include "console.h"
#include "simpio.h"  // for getLine
#include "lexicon.h"
#include "set.h"
#include "exercise10.h"
#include <foreach.h>
#include "vector.h"

using namespace std;

//func prototypes
Vector<int> initRequests();
int getSum(Vector<int> curSet);
int cutStock(Vector<int> & requests, int stockLength);
int cutStock(Vector<int> & requests, int sumOfRequests, int stockLength, Vector< Vector< Vector<int> > > & setOfSets);
void printSetOfSet(Vector< Vector< Vector<int> > > & setOfSets);
void printSet(Vector< Vector<int> > & resultSet);
int getSumOfSets(Vector< Vector<int> > &setOfSets);
Vector< Vector<int> > getMinSet(Vector< Vector< Vector<int> > > &setOfSets, int sumOfRequests);

//general
void exercise10() {
    Vector<int> requests = initRequests();
    int stockLength = 10;
    int countOfStocks = cutStock(requests, stockLength);
    cout << "you need " << countOfStocks << " stock(s)" << endl;
}

int cutStock(Vector<int> & requests, int stockLength) {
    Vector< Vector< Vector<int> > > setOfSets;
    int sumOfRequests = getSum(requests);
    return cutStock(requests, sumOfRequests, stockLength, setOfSets);
}

int cutStock(Vector<int> & requests, int sumOfRequests, int stockLength, Vector< Vector< Vector<int> > > & setOfSets) {
    if (requests.size() == 0 && setOfSets.size() != 0) {
        Vector< Vector<int> > minSet = getMinSet(setOfSets, sumOfRequests);

        cout << "****all possible sets is :*****" << endl;
        printSetOfSet(setOfSets);
        cout << "*********" << endl;
        cout << "the result is: ";
        printSet(minSet);
        return minSet.size();
    }

    //printSet(setOfSets);
    for (int i = 0; i < requests.size(); i++) {
        int curStock = requests.get(i);
        Vector<int> rest = requests;
        rest.remove(i);

        int countOfSets = setOfSets.size();
        for (int set = 0; set < countOfSets; set++) {

            //add curStock as subset to curSet
            Vector<int> newSubset;
            newSubset.add(curStock);
            Vector< Vector<int> > copySet = setOfSets.get(set);
            copySet.add(newSubset);
            setOfSets.add(copySet);

            int countOfSubsets = setOfSets.get(set).size();
            for (int subset = 0; subset < countOfSubsets; subset++) {
                int sumOfCurSet = curStock + getSum(setOfSets.get(set).get(subset));
                if (sumOfCurSet <= stockLength) {
                   Vector<int> copySubset =  setOfSets.get(set).get(subset);
                   copySubset.add(curStock);
                   Vector< Vector<int> > copySet = setOfSets.get(set);
                   copySet.set(subset,copySubset);
                   //setOfSets.set(set, copySet);
                   setOfSets.add(copySet);
                }
            }
        }
        if (setOfSets.size() == 0) {
            Vector< Vector<int> > newSet;
            Vector<int> newSubset;
            newSubset.add(curStock);
            newSet.add(newSubset);
            setOfSets.add(newSet);
        }
        return cutStock(rest, sumOfRequests, stockLength, setOfSets);
    }
    return 0;
}

Vector< Vector<int> > getMinSet(Vector< Vector< Vector<int> > > &setOfSets, int sumOfRequests) {
    Vector< Vector<int> > result;
    result = setOfSets.get(0);
    for (int set = 0; set < setOfSets.size(); set++) {
        Vector< Vector<int> > curset = setOfSets.get(set);
        int sumOfCurSet = getSumOfSets(curset);
        if (curset.size() < result.size() && sumOfCurSet == sumOfRequests) {
            result = setOfSets.get(set);
        }
        if (sumOfCurSet == sumOfRequests && getSumOfSets(result) != sumOfRequests) {
            result = curset;
        }
    }
    return result;
}

int getSumOfSets(Vector< Vector<int> > &setOfSets) {
   int sum = 0;
   for (int i = 0; i < setOfSets.size(); i++) {
       sum += getSum(setOfSets.get(i));
   }
   return sum;
}

void printSet(Vector< Vector<int> > & resultSet) {

        for (int i = 0; i < resultSet.size(); i++) {
            cout << "[";
            for (int j = 0; j < resultSet.get(i).size(); j++) {
                cout << resultSet.get(i).get(j);
            }
            cout << "] ";
        }
        cout << endl;

}

void printSetOfSet(Vector< Vector< Vector<int> > > & setOfSets) {
    for (int s = 0; s < setOfSets.size(); s++) {
        for (int i = 0; i < setOfSets.get(s).size(); i++) {
            cout << "[";
            for (int j = 0; j < setOfSets.get(s).get(i).size(); j++) {
                cout << setOfSets.get(s).get(i).get(j);
            }
            cout << "] ";
        }
        cout << endl;
    }
}

int getSum(Vector<int> curSet) {
    int sum = 0;
    for (int i = 0; i < curSet.size(); i++) {
        sum += curSet.get(i);
    }
    return sum;
}

Vector<int> initRequests() {
    Vector<int>  requests;
    requests.add(4);
    requests.add(3);
    requests.add(4);
    requests.add(1);
    requests.add(7);
    requests.add(8);
    return requests;
}

