//
//  ShellSort.hpp
//  Sort
//
//  Created by limaoqi on 14/08/2017.
//  Copyright © 2017 limaoqi. All rights reserved.
//

#ifndef ShellSort_hpp
#define ShellSort_hpp

#include <stdio.h>
#include <vector>

using namespace std;

#endif /* ShellSort_hpp */

class ShellSort {
public:
    ShellSort(vector<int> arr): _arr(arr) {}
    vector<int> sort();
private:
    vector<int> _arr;
    void _sort();
};
