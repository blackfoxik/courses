#include "console.h"
#include "simpio.h"  // for getLine
#include <iomanip>
#include "exercise7.h"
#include "queueex7.h"
#include "queueex7List.h"

void exercise7() {
    QueueEx7List<int> q;
    for (int i = 0; i < 10; i++) {
        q.enqueue(i);
    }
    q.reverse();
    for (int i = 0; i < 10; i++) {
       std::cout << q.dequeue() << std::endl;
    }

    return;

    QueueEx7<int> q1;
    for (int i = 0; i < 110; i++) {
        q1.enqueue(i);
    }
    q1.reverse();
    for (int i = 0; i < 110; i++) {
       std::cout << q1.dequeue() << std::endl;
    }


}

