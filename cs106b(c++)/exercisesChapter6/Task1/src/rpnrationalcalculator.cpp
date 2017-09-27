#include <iostream>
#include <string>
#include "rpnrationalcalculator.h"
#include "map.h"

#include <cctype>
#include "error.h"
#include "stack.h"
#include "strlib.h"
#include "rational.h"
#include "simpio.h"
using namespace std;



void helpCommand();
void applyOperator(char op, Stack<Rational> &operandStack);

    RPNRationalCalculator::RPNRationalCalculator() {

    }

    void RPNRationalCalculator::Run() {
        cout << "RPN Calculator Simulation (type H for help)" << endl;
        Stack<Rational> operandStack;
        while (true) {
            string line = getLine(">  ");
            if (line.length() == 0) line = "Q";
            char ch = toupper(line[0]);
            if (ch == 'Q') {
                break;
            } else if (ch == 'C') {
                operandStack.clear();
            } else if (ch == 'H') {
                helpCommand();
            }
            else if (isdigit(ch)) {
                operandStack.push(Rational(stringToInteger(line),1));
            } else {
                applyOperator(ch, operandStack);
            }
        }
        //return 0;
    }

    void applyOperator(char op, Stack<Rational> &operandStack) {
        Rational result;
        Rational rhs = operandStack.pop();
        Rational lhs = operandStack.pop();
        switch (op) {
            case '+': result = lhs + rhs; break;
            case '-': result = lhs - rhs; break;
            case '*': result = lhs * rhs; break;
            case '/': result = lhs / rhs; break;
            default: error("Illegal operator");
        }
        cout << result << endl;
        operandStack.push(result);
    }

    void helpCommand() {
        cout << "H - help, Q - quit, C - clear" << endl;
    }


