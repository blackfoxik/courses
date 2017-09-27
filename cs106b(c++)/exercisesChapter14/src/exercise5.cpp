
#include "console.h"
#include "simpio.h"  // for getLine
#include "queue.h"
#include "assert.h"
#include "exercise5.h"
//using namespace std;

void exercise5() {
    Queue<int> s1;
    s1.add(0);
    s1.add(5);
    s1.add(3);
    assert(s1.peek() == 0);
    assert(s1.dequeue() == 0);
    assert(s1.peek() == 5);
}
