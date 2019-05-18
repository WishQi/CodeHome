//
//  main.cpp
//  169. Majority Element
//
//  Created by limaoqi on 16/10/2017.
//  Copyright © 2017 limaoqi. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    // 19ms, AC, O(n)
    int majorityElement(vector<int>& nums) {
        map<int, int> table;
        int n = (int)nums.size();
        for (int i = 0; i < n; i++) {
            if (++table[nums[i]] > n / 2) return nums[i];
        }
        return -1;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
