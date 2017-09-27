#include "console.h"
#include "simpio.h"  // for getLine
#include <iomanip>
#include "exercise8.h"
#include "pqueue.h"


void exercise8() {
    PriorityQueue<int> q;
    for (int i = 0; i < 10; i++) {
        q.enqueue(i, 10 - i);
    }
    q.enqueue(1000, 5);
    //q.reverse();
    for (int i = 0; i < 11; i++) {
       std::cout << q.dequeue() << std::endl;
    }

  /*  return;

    QueueEx7<int> q1;
    for (int i = 0; i < 110; i++) {
        q1.enqueue(i);
    }
    q1.reverse();
    for (int i = 0; i < 110; i++) {
       std::cout << q1.dequeue() << std::endl;
    }
    */


}

