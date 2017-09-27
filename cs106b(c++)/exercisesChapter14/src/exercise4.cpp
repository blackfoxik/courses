
#include "console.h"
#include "simpio.h"  // for getLine
#include "stack.h"
#include "assert.h"
#include "exercise4.h"
//using namespace std;

void exercise4() {
    Stack<int> s1;
    s1.add(0);
    s1.add(5);
    s1.add(3);
    assert(s1.peek() == 3);
    assert(s1.pop() == 3);
    assert(s1.peek() == 5);
}

