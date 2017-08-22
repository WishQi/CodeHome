//
//  QuickSort.cpp
//  Sort
//
//  Created by limaoqi on 16/08/2017.
//  Copyright © 2017 limaoqi. All rights reserved.
//

#include "QuickSort.hpp"

vector<int> QuickSort::sort() {
    _sort(0, (int)_arr.size() - 1);
    return _arr;
}

void QuickSort::_sort(int low, int high) {
    if (low >= high) {
        return;
    }
    int middle = _partition(low, high);
    _sort(low, middle - 1);
    _sort(middle + 1, high);
}

int QuickSort::_partition(int low, int high) {
    int k = random() % (high - low + 1) + low;
    int key = _arr[k];
    swap(_arr[k], _arr[high]);
    int left = low, right = high;
    while (left < right) {
        if (_arr[left] <= key) {
            ++left;
        } else if (_arr[right] >= key) {
            --right;
        } else {
            swap(_arr[left], _arr[right]);
        }
    }
    swap(_arr[right], _arr[high]);
    return left;
}
