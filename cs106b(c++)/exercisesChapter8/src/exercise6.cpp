
#include "console.h"
#include "simpio.h"  // for getLine
#include "lexicon.h"
#include "vector.h"
#include "exercise6.h"
#include <foreach.h>
using namespace std;

//func prototypes
bool isMeasurable(int target, Vector<int> &weights);

//general
void exercise6() {
    Vector<int> sampleWeights;
    //sampleWeights += 3, 4, 5;
    //sampleWeights += 4, 3, 5;
    //cout << isMeasurable(6, sampleWeights) << endl;
    sampleWeights += 1, 3;
    cout << isMeasurable(5, sampleWeights) << endl;
}

bool isMeasurable(int target, Vector<int> &weights) {
    if (weights.isEmpty()) {
        return target == 0;
    }
    int curItemFromWeights = weights.get(0);
    Vector<int> rest = weights;
    rest.remove(0);
    int curSumWeights = 0;
    foreach (int curItemRestSet in weights) {
        curSumWeights += curItemRestSet;
    }
    if ((curItemFromWeights == target)||(curSumWeights == target)) {
        return true;
    }
    else {
        return isMeasurable(target,rest)
               || isMeasurable(target + curItemFromWeights, rest)
               || isMeasurable(target - curItemFromWeights, rest);
    }

}



