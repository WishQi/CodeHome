//
//  main.cpp
//  136. Single Number
//
//  Created by limaoqi on 12/10/2017.
//  Copyright © 2017 limaoqi. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <numeric>

using namespace std;

class Solution {
public:
    // 23ms, AC, O(n),有辅助空间开销
    int singleNumber(vector<int>& nums) {
        int res = -1;
        map<int, int> table;
        for (int i = 0; i < (int)nums.size(); i++) {
            table[nums[i]]++;
        }
        for (auto itr = table.begin(); itr != table.end(); itr++) {
            if (itr->second == 1) {
                res = itr->first;
                break;
            }
        }
        return res;
    }
    // 异或：A XOR A = 0，并且异或操作可交换
    // 16ms, AC, O(n),无辅助空间开销
    int singleNumber1(vector<int>& nums) {
        int res = 0;
        for (int i = 0; i < (int)nums.size(); i++) {
            res ^= nums[i];
        }
        return res;
    }
    // 2 * (a + b + c) - (a + a + b + b + c) = c
    // 23ms, AC, O(n),有辅助空间开销
    int singleNumber2(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        set<int> se(nums.begin(), nums.end());
        return 2 * accumulate(se.begin(), se.end(), 0) - sum;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
