#include "console.h"
#include "simpio.h"  // for getLine
#include <iomanip>
#include "exercise6.h"
#include "queueex6.h"

void exercise6() {
    QueueEx6<int> q;
    for (int i = 0; i < 100; i++) {
        q.enqueue(i);
    }
    for (int i = 0; i < 100; i++) {
       std::cout << q.dequeue() << std::endl;
    }
    q.enqueue(0);
    q.enqueue(2);
    q.enqueue(100);
    std::cout << q.peek() << std::endl;
    q.dequeue();
    std::cout << q.peek() << std::endl;
}

