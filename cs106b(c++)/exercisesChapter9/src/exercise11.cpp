
#include "console.h"
#include "exercise11.h"


using namespace std;

//func prototypes
bool wildcardMatch(string filename, string pattern);
bool wildcardMatch(string filename, string pattern, string prevSignOfPattern);
//general
void exercise11() {
      cout << wildcardMatch("US.txt", "*.*") << endl;
      cout << wildcardMatch("test", "*.*") << endl;
      cout << wildcardMatch("test.h", "test.?") << endl;
      cout << wildcardMatch("test.cpp", "test.?") << endl;
      cout << wildcardMatch("x", "??*") << endl;
      cout << wildcardMatch("yy", "??*") << endl;
      cout << wildcardMatch("zzz", "??*") << endl;

      cout << wildcardMatch("xayz", "x?y*z") << endl;
      cout << wildcardMatch("xaybcz", "x?y*z") << endl;
      cout << wildcardMatch("xaylmnz", "x?y*z") << endl;

      cout << wildcardMatch("xyz", "x?y*z") << endl;
      cout << wildcardMatch("ayz", "x?y*z") << endl;
      cout << wildcardMatch("xaz", "x?y*z") << endl;

      cout << wildcardMatch("aab", "a?b") << endl;
      cout << wildcardMatch("abb", "a?b") << endl;
      cout << wildcardMatch("acb", "a?b") << endl;

      cout << wildcardMatch("ab", "a?b") << endl;
      cout << wildcardMatch("b", "a?b") << endl;
      cout << wildcardMatch("cb", "a?b") << endl;

      cout << wildcardMatch("ab", "a*b") << endl;
      cout << wildcardMatch("aab", "a*b") << endl;
      cout << wildcardMatch("acb", "a*b") << endl;
      cout << wildcardMatch("axyb", "a*b") << endl;

      cout << wildcardMatch("b", "a*b") << endl;
      cout << wildcardMatch("a", "a*b") << endl;
      cout << wildcardMatch("ac", "a*b") << endl;
      cout << wildcardMatch("abc", "a*b") << endl;
}

bool wildcardMatch(string filename, string pattern) {
    return wildcardMatch(filename, pattern, "");
}

bool wildcardMatch(string filename, string pattern, string prevSignOfPattern) {
    if (pattern == "") {
        if (prevSignOfPattern == "?" && filename.size() != 0) {
            return false;
        }
        if (prevSignOfPattern != "*" && filename.size() > 0) {
            return false;
        }
        return true;
    }
    string curSignOfPattern = pattern.substr(0,1);
    string restOfpattern = pattern.substr(1);

    //rules
    if (curSignOfPattern == "*") {
        //any or 0
        return wildcardMatch(filename,  restOfpattern, curSignOfPattern);
    }

    if (curSignOfPattern == "?") {
        // any single
        string curSignOfFilename = filename.substr(0,1);
        if (curSignOfFilename != "." && curSignOfFilename != "") {
            string restOfFilename = filename.substr(1);
            return wildcardMatch(restOfFilename,  restOfpattern, curSignOfPattern);
        } else {
            return false;
        }
    }

    if (curSignOfPattern == ".") {
        //
        int posPoint = filename.find(".");
        if (posPoint >= 0) {
            if (prevSignOfPattern == "*") {
                string restOfFilename = filename.substr(posPoint + 1);
                return wildcardMatch(restOfFilename,  restOfpattern, curSignOfPattern);
            } else if (posPoint > 0) {
                return false;
            } else {
                string restOfFilename = filename.substr(posPoint + 1);
                return wildcardMatch(restOfFilename,  restOfpattern, curSignOfPattern);
            }

        } else {
            return false;
        }
    }

        string curSignOfFilename = filename.substr(0,1);
        string restOfFilename = "";
        if (filename.size() > 1) {
             restOfFilename = filename.substr(1);
        }

        if (curSignOfFilename == curSignOfPattern) {
            return wildcardMatch(restOfFilename,  restOfpattern, curSignOfPattern);
        } else if (restOfFilename.size() != 0 && prevSignOfPattern == "*"){
            return wildcardMatch(restOfFilename,  restOfpattern, prevSignOfPattern);
        } else {
           return false;
        }

    return false;
}


