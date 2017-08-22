//
//  HeapSort.hpp
//  Sort
//
//  Created by limaoqi on 17/08/2017.
//  Copyright © 2017 limaoqi. All rights reserved.
//

#ifndef HeapSort_hpp
#define HeapSort_hpp

#include <stdio.h>
#include <vector>

using namespace std;

class HeapSort {
public:
    HeapSort(vector<int> arr): _heap(arr) {}
    vector<int> sort();
private:
    vector<int> _heap;
    void heapSort();
    void maxHeap(int size);
    void maintain(int k, int size);
};

#endif /* HeapSort_hpp */
