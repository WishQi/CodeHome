//
//  QuickSort.hpp
//  Sort
//
//  Created by limaoqi on 16/08/2017.
//  Copyright © 2017 limaoqi. All rights reserved.
//

#ifndef QuickSort_hpp
#define QuickSort_hpp

#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;

class QuickSort {
public:
    QuickSort(vector<int> arr): _arr(arr) {}
    vector<int> sort();
private:
    vector<int> _arr;
    void _sort(int low, int high);
    int _partition(int low, int high);
};

#endif /* QuickSort_hpp */
