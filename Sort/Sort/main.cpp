//
//  main.cpp
//  Sort
//
//  Created by limaoqi on 15/08/2017.
//  Copyright © 2017 limaoqi. All rights reserved.
//

#include <iostream>
#include "ShellSort.hpp"
#include "MergeSort.hpp"
#include "QuickSort.hpp"
#include "HeapSort.hpp"

void printList(vector<int> arr) {
    for (int i = 0; i < arr.size(); ++i) {
        cout << arr[i] << ((i == arr.size() - 1) ? "\n" : " ");
    }
}

bool isSorted(vector<int> arr) {
    for (int i = 0; i < arr.size() - 1; ++i) {
        if (arr[i] > arr[i + 1]) {
            cout << "Sort failed" << endl;
            return false;
        }
    }
    cout << "Sort succeeds" << endl;
    return true;
}

int main(int argc, const char * argv[]) {
    
//    vector<int> arr = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    vector<int> arr;
    for (int i = 0; i < 1000000; ++i) {
        int element = rand();
        arr.push_back(element);
    }
    
    auto beginTime1 = clock();
    vector<int> arr1 = ShellSort(arr).sort();
    isSorted(arr1);
    cout << "Shell Sort: " << clock() - beginTime1 << endl;
//    printList(arr1);
    
    auto beginTime2 = clock();
    vector<int> arr2 = MergeSort(arr).sort();
    isSorted(arr2);
    cout << "Merge Sort: " << clock() - beginTime2 << endl;
//    printList(arr2);
    
    auto beginTime3 = clock();
    vector<int> arr3 = QuickSort(arr).sort();
    isSorted(arr3);
    cout << "Quick Sort: " << clock() - beginTime3 << endl;
//    printList(arr3);
    
    auto beginTime4 = clock();
    vector<int> arr4 = HeapSort(arr).sort();
    isSorted(arr4);
    cout << "Heap Sort: " << clock() - beginTime4 << endl;
//    printList(arr4);
    
    return 0;
}
