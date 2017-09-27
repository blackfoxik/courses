#ifndef _queueex7_h
#define _queueex7_h

#include "error.h"

#include "vector.h"


template <typename ValueType>
class QueueEx7 {
public:

    QueueEx7();
    virtual ~QueueEx7();
    int size() const;
    bool isEmpty() const;
    void clear();
    ValueType dequeue();
    void enqueue(const ValueType& value);
    const ValueType& peek() const;


private:
    /* Instance variables */
    Vector<ValueType> ringBuffer;
    int count;
    int capacity;
    int head;
    int tail;

    /* Private functions */
    void expandRingBufferCapacity();
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
static const int INITIAL_CAPACITY = 10;

/*
 * Implementation notes: Queue constructor
 * ---------------------------------------
 * The constructor must allocate the array storage for the queue
 * elements and initialize the fields of the object.
 */
template <typename ValueType>
QueueEx7<ValueType>::QueueEx7() {
    clear();
}


/*
 * Implementation notes: ~Queue destructor
 * ---------------------------------------
 * All of the dynamic memory is allocated in the Vector class,
 * so no work is required at this level.
 */
template <typename ValueType>
QueueEx7<ValueType>::~QueueEx7() {
    // empty
}





template <typename ValueType>
void QueueEx7<ValueType>::clear() {
    capacity = INITIAL_CAPACITY;
    ringBuffer = Vector<ValueType>(capacity);
    head = 0;
    tail = 0;
    count = 0;
}

/*
 * Implementation notes: dequeue, peek
 * -----------------------------------
 * These methods must check for an empty queue and report an error
 * if there is no first element.
 */
template <typename ValueType>
ValueType QueueEx7<ValueType>::dequeue() {
    if (count == 0) {
        error("Queue::dequeue: Attempting to dequeue an empty queue");
    }
    ValueType result = ringBuffer[head];
    head = (head + 1) % capacity;
    count--;
    return result;
}

template <typename ValueType>
void QueueEx7<ValueType>::enqueue(const ValueType& value) {
    if (count >= capacity - 1) {
        expandRingBufferCapacity();
    }
    ringBuffer[tail] = value;
    tail = (tail + 1) % capacity;
    count++;
}


template <typename ValueType>
bool QueueEx7<ValueType>::isEmpty() const {
    return count == 0;
}

template <typename ValueType>
const ValueType& QueueEx7<ValueType>::peek() const {
    if (count == 0) {
        error("Queue::peek: Attempting to peek at an empty queue");
    }
    return ringBuffer.get(head);
}


template <typename ValueType>
int QueueEx7<ValueType>::size() const {
    return count;
}

/*
 * Implementation notes: expandRingBufferCapacity
 * ----------------------------------------------
 * This private method doubles the capacity of the ringBuffer vector.
 * Note that this implementation also shifts all the elements back to
 * the beginning of the vector.
 */
template <typename ValueType>
void QueueEx7<ValueType>::expandRingBufferCapacity() {
    Vector<ValueType> copy = ringBuffer;
    ringBuffer = Vector<ValueType>(2 * capacity);
    for (int i = 0; i < count; i++) {
        ringBuffer[i] = copy[(head + i) % capacity];
    }
    head = 0;
    tail = count;
    capacity *= 2;
}

#endif

