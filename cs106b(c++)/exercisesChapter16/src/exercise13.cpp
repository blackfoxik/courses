#include "exercise13.h"
#include "pqueueheap.h"

using namespace std;
//func prototype


//general
void exercise13() {
PriorityQueueHeap<string> q;
q.enqueue("la",1.0);
q.enqueue("lala",2.0);
q.enqueue("l",0.5);
cout<< q.peek() << endl;

}


