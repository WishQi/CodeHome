//
//  HeapSort.cpp
//  Sort
//
//  Created by limaoqi on 17/08/2017.
//  Copyright © 2017 limaoqi. All rights reserved.
//

#include "HeapSort.hpp"

vector<int> HeapSort::sort() {
    maxHeap((int)_heap.size());
    heapSort();
    return _heap;
}

void HeapSort::maxHeap(int size) {
    for (int i = size / 2 - 1; i >= 0; --i) {
        maintain(i, size);
    }
}

void HeapSort::maintain(int k, int size) {
    if (k >= size) return;
    int left = k * 2 + 1, right = k * 2 + 2, maxP = k;
    if (left < size && _heap[left] > _heap[maxP]) maxP = left;
    if (right < size && _heap[right] > _heap[maxP]) maxP = right;
    if (maxP != k) {
        swap(_heap[k], _heap[maxP]);
        maintain(maxP, size);
    }
}

void HeapSort::heapSort() {
    int heapSize = (int)_heap.size();
    for (int i = 0; i < _heap.size(); ++i) {
        swap(_heap[0], _heap[heapSize - 1]);
        maintain(0, --heapSize);
    }
}
