

#include "exercise14.h"
//#include <iostream>
//#include "gwindow.h"
#include "vector.h"

template <typename ValueType>
void sort(Vector<ValueType> & vec);
template <typename ValueType>
void printV(Vector<ValueType> & vec);
//general
void exercise14() {
   Vector<int> m;
   m.add(10);
   m.add(5);
   m.add(9);
   m.add(2);
   sort(m);
   printV(m);
}

template <typename ValueType>
void printV(Vector<ValueType> & vec) {
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << endl;
    }
}

template <typename ValueType>
void sort(Vector<ValueType> & vec) {
    Vector<ValueType> sorted;
    for (int i = 0; i < vec.size(); i++) {
        enqueue(vec[i], sorted);
    }
    for (int i = 0; i < vec.size(); i++) {
        vec[i] = dequeue(sorted);
    }
}

template <typename ValueType>
void checkChildren(int curN, Vector<ValueType> &heap) {
    if (curN > heap.size()) return;

    int leftChildIndex = 2 * curN + 1;
    int righChildIndex = 2 * curN + 2;
    if (leftChildIndex > heap.size() - 1) return;
    if (righChildIndex > heap.size() - 1) return;
    if(heap[leftChildIndex] < heap[righChildIndex]) {
        if(heap[curN] > heap[leftChildIndex]) {
            ValueType tmp = heap[curN];
            heap[curN] = heap[leftChildIndex];
            heap[leftChildIndex] = tmp;
        }
    } else {
        if(heap[curN] > heap[righChildIndex]) {
            ValueType tmp = heap[curN];
            heap[curN] = heap[righChildIndex];
            heap[righChildIndex] = tmp;
        }
    }
    checkChildren(leftChildIndex, heap);
    checkChildren(righChildIndex, heap);
}

template <typename ValueType>
ValueType dequeue(Vector<ValueType> &heap) {
    if (heap.size() == 0) {
        error("Queue::dequeue: Attempting to dequeue an empty queue");
    }
    ValueType result = heap[0];
    heap[0] = heap[heap.size() - 1];
    heap.remove(heap.size() - 1);
    checkChildren(0, heap);
    return result;
}

template <typename ValueType>
void checkParent(int curN, Vector<ValueType> &heap) {
    if (curN <= 0) return;
    int parentIndex = (curN - 1) / 2;
    if(heap[curN] < heap[parentIndex]) {
        ValueType tmp = heap[curN];
        heap[curN] = heap[parentIndex];
        heap[parentIndex] = tmp;
    }
    checkParent(parentIndex, heap);
}

template <typename ValueType>
void enqueue(const ValueType& value, Vector<ValueType> &heap) {
    heap.add(value);
    int curN = heap.size() - 1;
    checkParent(curN, heap);
}
