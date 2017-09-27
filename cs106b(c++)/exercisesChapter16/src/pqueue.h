#ifndef _pqueue_h
#define _pqueue_h

#include "error.h"

#include "vector.h"



template <typename ValueType>
class PriorityQueue {
public:

    PriorityQueue();
    virtual ~PriorityQueue();
    int size() const;
    bool isEmpty() const;
    void clear();
    ValueType dequeue();
    void enqueue(const ValueType& value, double priority);
    const ValueType& peek() const;
    void reverse();
    PriorityQueue<ValueType> & operator=(const PriorityQueue<ValueType> & src);
    PriorityQueue(const PriorityQueue<ValueType> & src);



private:
    struct Cell {
        ValueType data;
        double priority;
        Cell *link;
    };

    /* Instance variables */

    Cell *head;
    Cell *tail;
    int count;

    /* Private functions */
    void deepCopy(const PriorityQueue<ValueType> & src);
    void setPrevTail(Cell *&src);
};

/*
 * Implementation notes: Queue data structure
 * ------------------------------------------
 * The array-based queue stores the elements in successive index
 * positions in a vector, just as a stack does.  What makes the
 * queue structure more complex is the need to avoid shifting
 * elements as the queue expands and contracts.  In the array
 * model, this goal is achieved by keeping track of both the
 * head and tail indices.  The tail index increases by one each
 * time an element is enqueued, and the head index increases by
 * one each time an element is dequeued.  Each index therefore
 * marches toward the end of the allocated vector and will
 * eventually reach the end.  Rather than allocate new memory,
 * this implementation lets each index wrap around back to the
 * beginning as if the ends of the array of elements were joined
 * to form a circle.  This representation is called a ring buffer.
 */


/*
 * Implementation notes: Queue constructor
 * ---------------------------------------
 * The constructor must allocate the array storage for the queue
 * elements and initialize the fields of the object.
 */
template <typename ValueType>
PriorityQueue<ValueType>::PriorityQueue() {
    head = tail = NULL;
    count = 0;
}


/*
 * Implementation notes: ~Queue destructor
 * ---------------------------------------
 * All of the dynamic memory is allocated in the Vector class,
 * so no work is required at this level.
 */
template <typename ValueType>
PriorityQueue<ValueType>::~PriorityQueue() {
    // empty
    clear();
}





template <typename ValueType>
void PriorityQueue<ValueType>::clear() {
    while (count > 0) {
        dequeue();
    }
}

/*
 * Implementation notes: dequeue, peek
 * -----------------------------------
 * These methods must check for an empty queue and report an error
 * if there is no first element.
 */
template <typename ValueType>
ValueType PriorityQueue<ValueType>::dequeue() {
    if (isEmpty()) {
        error("Queue::dequeue: Attempting to dequeue an empty queue");
    }
    Cell *cp = head;
    ValueType result = cp->data;
    head = cp->link;
    if (head == NULL) tail = NULL;
    delete cp;
    count--;
    return result;
}

template <typename ValueType>
void PriorityQueue<ValueType>::enqueue(const ValueType& value, double priority) {
    Cell *cp = new Cell;
    cp->data = value;
    cp->priority = priority;

    if (head == NULL) {
        head = cp;
    } else {
        if (head->priority > priority) {
            cp->link = head;
            head = cp;
        } else {
            Cell *curCell = head;
            while (curCell->priority <= priority) curCell = curCell->link;
            cp->link = curCell->link;
            curCell->link = cp;
        }
        //tail->link = cp;
    }
    //tail = cp;
    count++;
}


template <typename ValueType>
bool PriorityQueue<ValueType>::isEmpty() const {
    return count == 0;
}

template <typename ValueType>
const ValueType& PriorityQueue<ValueType>::peek() const {
    if (isEmpty()) {
        error("Queue::peek: Attempting to peek at an empty queue");
    }
    return head->data;
}


template <typename ValueType>
PriorityQueue<ValueType> & PriorityQueue<ValueType>::operator =(const PriorityQueue<ValueType> & src) {
    if (this != &src) {
        clear();
        deepCopy(src);
    }
    return *this;
}

template <typename ValueType>
PriorityQueue<ValueType>::PriorityQueue(const PriorityQueue<ValueType> & src) {
    deepCopy(src);
}

template <typename ValueType>
void PriorityQueue<ValueType>::deepCopy(const PriorityQueue<ValueType> & src) {
   head = NULL;
   tail = NULL;
   count = 0;
   for (Cell *cp = src.head; cp != NULL; cp = cp->link) {
       enqueue(cp->data);
   }
}

template <typename ValueType>
int PriorityQueue<ValueType>::size() const {
    return count;
}

template <typename ValueType>
void PriorityQueue<ValueType>::setPrevTail(Cell *&src) {
    std::cout << "src: " << src << " &src: "<< &src << std::endl;
    Cell *result = head;
    while (true) {
       if (result->link == src) break;
       result = result->link;
    }
    src = result;
}

template <typename ValueType>
void PriorityQueue<ValueType>::reverse() {
    Cell *sHead = head;
    Cell *sTail = tail;
   while (true) {
       ValueType tmp = sHead->data;
       sHead->data = sTail->data;
       sTail->data = tmp;
       setPrevTail(sTail);
       if (sHead == sTail) break;
       sHead = sHead->link;
   }
}

#endif
