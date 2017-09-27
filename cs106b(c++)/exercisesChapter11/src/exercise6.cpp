#include "console.h"
#include "simpio.h"  // for getLine
#include <iomanip>
#include "set.h"
#include "grid.h"
#include "exercise6.h"
using namespace std;

const int MAX_JUDGES = 100;
//func prototypes
void sort(double scores[], int size);
void mergeArrays(double scores[], double ar1[], double ar2[], int size1, int size2);
double getAverageWithoutMinAndMax(double scores[], int countOfJudges);
void copyArray(double source[], double receiver[], int start, int finish);
void printResult(double scores[], int countOfJudges);
void printAr(double scores[], int count);


void exercise6() {
   double scores[MAX_JUDGES];
   int countOfJudges = 0;
   while (true) {
       string strCurScore = getLine("Judge #"+integerToString(countOfJudges + 1));
       if (strCurScore == "" || countOfJudges == MAX_JUDGES) {
           break;
       }
       double curScore = stringToDouble(strCurScore);
       scores[countOfJudges] = curScore;
       countOfJudges++;
   }
   sort(scores, countOfJudges);
   printResult(scores, countOfJudges);
}

void sort(double scores[], int size) {
    if (size == 1) return;

    int mid = size / 2;

    int size1 = mid;
    double ar1[size1];
    copyArray(scores, ar1, 0, mid);

    int size2 = size - mid;
    double ar2[size2];
    copyArray(scores, ar2, mid, size);

    sort(ar1, size1);
    sort(ar2, size2);
    mergeArrays(scores, ar1, ar2, size1, size2);
}

void copyArray(double source[], double receiver[], int start, int finish) {
    for (int i = 0; i < finish - start; i++) {
        double a = source[start + i];
        receiver[i] = source[start + i];
    }
}

void mergeArrays(double scores[], double ar1[], double ar2[], int size1, int size2) {
    int c1 = 0;
    int c2 = 0;
    int counter = 0;
    while (c1 < size1 && c2 < size2) {
        if (ar1[c1] > ar2[c2]) {
            scores[counter] = ar2[c2];
            c2++;
            counter++;
            continue;
        }
        if (ar1[c1] <= ar2[c2]) {
            scores[counter] = ar1[c1];
            c1++;
            counter++;
            continue;
        }
    }
    while (c1 < size1) {
        scores[counter] = ar1[c1];
        counter++;
        c1++;
    }
    while (c2 < size2) {
        scores[counter] = ar2[c2];
        counter++;
        c2++;
    }
}

void printResult(double scores[], int countOfJudges) {
    double av = getAverageWithoutMinAndMax(scores, countOfJudges);
    cout << "The average after eliminating " << scores[0] << " and " << scores[countOfJudges - 1] << " is "<< av << endl;
}

double getAverageWithoutMinAndMax(double scores[], int countOfJudges) {
    double sum = 0;
    for (int i = 1; i < countOfJudges - 1; i++) {
        sum += scores[i];
    }
    return sum / (countOfJudges - 2);
}

void printAr(double scores[], int count) {
    for (int i = 0; i < count; i++) {
        cout << scores[i] << endl;
    }
    cout << endl;
}






