#include <iostream>
#include <string>
#include "card.h"
#include "map.h"
#include "simplecalculator.h"
#include "tokenscanner.h"
#include "simpio.h"
using namespace std;




    void applyOperator(string curOperator, Stack<double> &items);
    void compute(string line);
    string getResultLine(string line, Map<string,string> &values);

    SimpleCalculator::SimpleCalculator() {

    }

    void SimpleCalculator::run() {
        while (true) {
            string line = getLine(">  ");
            if (line.length() == 0) break;
            compute(line);
        }
    }

    void SimpleCalculator::runWithAssignmentStatements() {

        Map<string,string> values;
        string resultLine = "";
        while (true) {
            string line = getLine(">  ");
            if (line.length() == 0) break;

            if (line.find("=") != string::npos) {
               string key = line.substr(0, line.find("="));
               string value = line.substr(line.find("=") + 1);
               values.add(key,value);
            } else {
                resultLine  = getResultLine(line,values);
                break;
            }
        }
        compute(resultLine);
    }


    void compute(string line) {
        TokenScanner scanner(line);
        scanner.ignoreWhitespace();
        scanner.addWordCharacters(".");
        double result = 0;
        double argument = 0;
        string curOperator = "";
        Stack<double> items;
        while(scanner.hasMoreTokens()) {
            string curToken = scanner.nextToken();
            if (curToken.find(".") != string::npos) {
                argument = stringToDouble(curToken);
                items.push(argument);
            } else if (curToken == "+" || curToken == "-" || curToken == "*" || curToken == "/") {
                curOperator = curToken;

            } else {
                argument = stringToDouble(curToken);
                items.push(argument);
            }
            if (curOperator != "" && items.size() == 2) {
                applyOperator(curOperator, items);
                curOperator = "";
            }

        }
    cout << items.peek() << endl;
    }

    void applyOperator(string curOperator, Stack<double> &items) {
        double argument = items.pop();
        double result = items.pop();
        char op = curOperator[0];
        switch (op) {
            case '+': result = result + argument; break;
            case '-': result = result - argument; break;
            case '*': result = result * argument; break;
            case '/': result = result / argument; break;
            default: error("Illegal operator");
        }
        items.push(result);
    }
    string getResultLine(string line, Map<string,string> &values) {
        string resultLine = "";

        TokenScanner scanner(line);
        scanner.ignoreWhitespace();
        scanner.addWordCharacters(".");
        while(scanner.hasMoreTokens()) {
            string curToken = scanner.nextToken();
            if (values.containsKey(curToken)) {
                curToken = getResultLine(values.get(curToken),values);
            }
            resultLine += curToken;
        }
        return resultLine;
    }
