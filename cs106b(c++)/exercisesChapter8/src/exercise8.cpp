
#include "console.h"
#include "simpio.h"  // for getLine
#include "lexicon.h"
#include "set.h"
#include "exercise8.h"
#include <foreach.h>

using namespace std;

//func prototypes
Set<string> generatePermutations (string str);

//general
void exercise8() {
    string str = getLine("Enter a string: ");
    cout << "The permutations of \"" << str << "\" are:" << endl;
    string ch = str.substr(0, 1);
    str = str.substr(1);
    Set<string> newSet;

    foreach (string s in generatePermutations(str)) {
       // cout << " \"" << s << "\"" << endl;
        for (int i = 0; i <= s.length(); i++) {
            string start = s.substr(0, i);
            string finish = s.substr(i);
            string curStr = start + ch + finish;
            newSet.add(curStr);

        }

    }
    foreach (string s in newSet) {
        cout << " \"" << s << "\"" << endl;
    }

}

Set<string> generatePermutations (string str) {
    Set<string> result;
    if (str == "") {
        result += "";
    } else {
        for (int i = 0; i < str.length(); i++) {
            char ch = str[i];
            string rest = str.substr(0, i) + str.substr(i + 1);
            foreach (string s in generatePermutations(rest)) {
                result += ch + s;
            }
        }

    }
    return result;
}



