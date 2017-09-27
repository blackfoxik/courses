#ifndef _pqueueheap_h
#define _pqueueheap_h

#include "error.h"

#include "vector.h"



template <typename ValueType>
class PriorityQueueHeap {
public:

    PriorityQueueHeap();
    virtual ~PriorityQueueHeap();
    int size() const;
    bool isEmpty() const;
    void clear();
    ValueType dequeue();
    void enqueue(const ValueType& value, double priority);
    const ValueType& peek() const;
    void reverse();
    PriorityQueueHeap<ValueType> & operator=(const PriorityQueueHeap<ValueType> & src);
    PriorityQueueHeap(const PriorityQueueHeap<ValueType> & src);



private:
    struct Cell {
        ValueType data;
        double priority;
    };
    Vector<Cell> heap;

    /* Private functions */
    void deepCopy(const PriorityQueueHeap<ValueType> & src);
    void checkParent(int curN);
    void checkChildren(int curN);
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
PriorityQueueHeap<ValueType>::PriorityQueueHeap() {

}


/*
 * Implementation notes: ~Queue destructor
 * ---------------------------------------
 * All of the dynamic memory is allocated in the Vector class,
 * so no work is required at this level.
 */
template <typename ValueType>
PriorityQueueHeap<ValueType>::~PriorityQueueHeap() {
    // empty
    clear();
}





template <typename ValueType>
void PriorityQueueHeap<ValueType>::clear() {
   heap.clear();
}

/*
 * Implementation notes: dequeue, peek
 * -----------------------------------
 * These methods must check for an empty queue and report an error
 * if there is no first element.
 */


template <typename ValueType>
void PriorityQueueHeap<ValueType>::checkChildren(int curN) {
    if (curN > heap.size()) return;

    int leftChildIndex = 2 * curN + 1;
    int righChildIndex = 2 * curN + 2;
    if(heap[leftChildIndex].priority < heap[righChildIndex].priority) {
        if(heap[curN].priority > heap[leftChildIndex].priority) {
            Cell tmp = heap[curN];
            heap[curN] = heap[leftChildIndex];
            heap[leftChildIndex] = tmp;
        }
    } else {
        if(heap[curN].priority > heap[righChildIndex].priority) {
            Cell tmp = heap[curN];
            heap[curN] = heap[righChildIndex];
            heap[righChildIndex] = tmp;
        }
    }
    checkChildren(leftChildIndex);
    checkChildren(righChildIndex);
}

template <typename ValueType>
ValueType PriorityQueueHeap<ValueType>::dequeue() {
    if (isEmpty()) {
        error("Queue::dequeue: Attempting to dequeue an empty queue");
    }
    ValueType result = heap[0].data;
    heap[0] = heap[heap.size() - 1];
    heap.remove(heap.size() - 1);
    checkChildren(0);
    return result;
}

template <typename ValueType>
void PriorityQueueHeap<ValueType>::checkParent(int curN) {
    if (curN <= 0) return;
    int parentIndex = (curN - 1) / 2;
    if(heap[curN].priority < heap[parentIndex].priority) {
        Cell tmp = heap[curN];
        heap[curN] = heap[parentIndex];
        heap[parentIndex] = tmp;
    }
    checkParent(parentIndex);
}

template <typename ValueType>
void PriorityQueueHeap<ValueType>::enqueue(const ValueType& value, double priority) {
    Cell cp;
    cp.data = value;
    cp.priority = priority;
    heap.add(cp);
    int curN = heap.size() - 1;
    checkParent(curN);
}


template <typename ValueType>
bool PriorityQueueHeap<ValueType>::isEmpty() const {
    return heap.size() == 0;
}

template <typename ValueType>
const ValueType& PriorityQueueHeap<ValueType>::peek() const {
    if (isEmpty()) {
        error("Queue::peek: Attempting to peek at an empty queue");
    }
    return heap[0].data;
}


template <typename ValueType>
PriorityQueueHeap<ValueType> & PriorityQueueHeap<ValueType>::operator =(const PriorityQueueHeap<ValueType> & src) {
    if (this != &src) {
        clear();
        deepCopy(src);
    }
    return *this;
}

template <typename ValueType>
PriorityQueueHeap<ValueType>::PriorityQueueHeap(const PriorityQueueHeap<ValueType> & src) {
    deepCopy(src);
}

template <typename ValueType>
void PriorityQueueHeap<ValueType>::deepCopy(const PriorityQueueHeap<ValueType> & src) {
   heap.clear();
   for (int i = 0; i < src.size(); i++) {
       heap[i] = src.heap[i];
   }
}

template <typename ValueType>
int PriorityQueueHeap<ValueType>::size() const {
    return heap->size();
}



template <typename ValueType>
void PriorityQueueHeap<ValueType>::reverse() {

   Vector<ValueType> old = heap;
   heap.clear();
   for (int i = old.size() - 1; i >= 0; i--) {
       heap[old.size() - i] = old[i];
   }

}

#endif

