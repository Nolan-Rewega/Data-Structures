#include "Heap.h"

Heap::Heap(HEAPTYPE _type) {
    size = 0;
    type = _type;
}


void Heap::insert(int value){
    heap.push_back(value);
    size++;

    int idx = size - 1;

    // -- Swap up
    do {
        if ( (heap[idx] < heap[idx / 2] && type == MIN) || (heap[idx] > heap[idx / 2] && type == MAX) ) {
            std::swap(heap[idx], heap[idx / 2]);
            idx = idx / 2;
        }
        else { break; } // -- ends on non swap
    } while (idx > 0); // -- ends on root swap

}

void Heap::pop(){
    // -- Dont pop on empty.
    if (heap.empty()) { return; }

    std::swap(heap[0], heap[size - 1]);
    heap.pop_back();
    size--;

    int idx = 0;
    int childIdx;
    int height = (int)log(size);
    int first = (int)pow(2, height);

    // -- Swap down
    while (idx < first) {
        if (type == MIN) {
            // -- both children exist
            if (2 * idx + 1 < size && 2 * idx + 2 < size) {
                childIdx = (heap[2 * idx + 1] < heap[2 * idx + 2]) ? (2 * idx + 1) : (2 * idx + 2);
            }
            // -- or we are missing the right child. so check the left child.
            else if (heap[idx] > heap[2 * idx + 1]) {
                childIdx = 2 * idx + 1;
            }
        }
        else {
            // -- both children exist
            if (2 * idx < size && 2 * idx + 1 < size) {
                childIdx = (heap[2 * idx + 1] > heap[2 * idx + 2]) ? (2 * idx + 1) : (2 * idx + 2);
            }
            // -- or we are missing the right child. so check the left child.
            else if (heap[idx] < heap[2 * idx + 1]) {
                childIdx = 2 * idx + 1;
            }
        }
        std::swap(heap[idx], heap[childIdx]);
        idx = childIdx;
    }

}

bool Heap::search(int value){
    for (int i = 0; i < size; i++) {
        if (heap[i] == value) { return true; }
    }
    return false;
}

int Heap::peak(){
    return heap.front();
}

void Heap::printHeap(){

    for (int i = 0; i < size; i++) {
        std::cout << heap[i] << std::endl;
    }
}
