//
//  MergeSort.hpp
//  Sort
//
//  Created by limaoqi on 15/08/2017.
//  Copyright © 2017 limaoqi. All rights reserved.
//

#ifndef MergeSort_hpp
#define MergeSort_hpp

#include <stdio.h>
#include <vector>

using namespace std;

#endif /* MergeSort_hpp */

class MergeSort {
public:
    MergeSort(vector<int> arr): _arr(arr) {}
    vector<int> sort();
private:
    vector<int> _arr;
    void _sort(int low, int high);
    void _merge(int low, int high);
};
