
#include "console.h"
#include "simpio.h"  // for getLine
#include "set.h"

#include "exercise4.h"
using namespace std;

/*void subsetSumExists(Set<int> &set, int target) {
    if (set.isEmpty()) {
        return target == 0;
    } else {
        int element = set.first();
        Set<int> rest = set - element;
        return subsetSumExists(rest, target, countWays)
             ||subsetSumExists(rest, target - element, countWays);
    }
}*/

void subsetSumExists(Set<int> &set, int target, int &countWays) {
    if (set.isEmpty()) {
        if (target == 0) countWays++;
    } else {
        int element = set.first();
        Set<int> rest = set - element;
        subsetSumExists(rest, target, countWays);
        subsetSumExists(rest, target - element, countWays);
    }
}

int countSubsetSumWays(Set<int> sampleSet, int target) {
    int countWays = 0;
    subsetSumExists(sampleSet, target, countWays);
    return countWays;
}

void exercise4() {
    int n = getInteger("Input n:");
    Set<int> sampleSet;
    sampleSet += 1, 3, 4, 5;
    cout << countSubsetSumWays (sampleSet, n) << endl;

}
