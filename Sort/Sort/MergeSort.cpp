//
//  MergeSort.cpp
//  Sort
//
//  Created by limaoqi on 15/08/2017.
//  Copyright © 2017 limaoqi. All rights reserved.
//

#include "MergeSort.hpp"

vector<int> MergeSort::sort() {
    _sort(0, (int)_arr.size() - 1);
    return _arr;
}

void MergeSort::_sort(int low, int high) {
    if (low >= high) {
        return;
    }
    int middle = (low + high) / 2;
    _sort(low, middle);
    _sort(middle + 1, high);
    _merge(low, high);
//    vector<int> left(&_arr[low], &_arr[middle + 1]);
//    vector<int> right(&_arr[middle + 1], &_arr[high + 1]);
//    int i = low, m = 0, n = 0;
//    while (i <= high && m < left.size() && n < right.size()) {
//        if (left[m] <= right[n]) {
//            _arr[i] = left[m];
//            ++m;
//        } else {
//            _arr[i] = right[n];
//            ++n;
//        }
//        ++i;
//    }
//    if (m == left.size() && n < right.size()) {
//        while (i <= high) {
//            _arr[i] = right[n];
//            ++n;
//            ++i;
//        }
//    } else if (n == right.size() && m < left.size()) {
//        while (i <= high) {
//            _arr[i] = left[m];
//            ++m;
//            ++i;
//        }
//    }
}

void MergeSort::_merge(int low, int high) {
    vector<int> arrCopy(&_arr[low], &_arr[high + 1]);
    int n = (int)arrCopy.size() - 1;
    int left = 0, mid = (high - low) / 2, right = mid + 1;
    for (int k = low; k <= high; ++k) {
        if (left > mid) {
            _arr[k] = arrCopy[right++];
        } else if (right > n) {
            _arr[k] = arrCopy[left++];
        } else if (arrCopy[left] <= arrCopy[right]) {
            _arr[k] = arrCopy[left++];
        } else {
            _arr[k] = arrCopy[right++];
        }
    }
}
