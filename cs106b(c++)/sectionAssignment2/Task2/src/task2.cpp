#include <iostream>
#include "console.h"
#include "gwindow.h" // for GWindow
#include "simpio.h"  // for getLine
#include "vector.h"  // for Vector
#include "queue.h"
#include "stack.h"
using namespace std;

void ReverseQueue(Queue<int> &q){
    Stack<int> curStack;
    while(!q.isEmpty()){
        curStack.push(q.dequeue());
    }
    while(!curStack.isEmpty()){
        q.enqueue(curStack.pop());
    }
}

void showQueue(Queue<int> &q){
    while(!q.isEmpty()){
        cout<< q.dequeue() << endl;
    }
}

int main() {
    Queue<int> myNumbers;
    myNumbers.enqueue(1);
    myNumbers.enqueue(2);
    myNumbers.enqueue(3);
    ReverseQueue(myNumbers);
    showQueue(myNumbers);
    return 0;

}
