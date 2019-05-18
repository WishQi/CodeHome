//
//  main.cpp
//  33. Search in Rotated Sorted Array
//
//  Created by limaoqi on 08/09/2017.
//  Copyright © 2017 limaoqi. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // 9ms
    int search(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == target) {
                return i;
            }
        }
        return -1;
    }
    // 3ms
    int search1(vector<int>& nums, int target) {
        int n = (int)nums.size();
        if (n == 0) return -1;
        if (target >= nums[0]) {
            for (int i = 0; i < nums.size(); ++i) {
                if (nums[i] == target) {
                    return i;
                }
            }
        } else {
            for (int i = n - 1; i >= 0; --i) {
                if (nums[i] == target) {
                    return i;
                }
            }
        }
        return -1;
    }
    // 9 ms
    int search2(vector<int>& nums, int target) {
        int n = (int)nums.size();
        if (n == 0) return -1;
        if (target >= nums[0]) {
            for (int i = 0; i < n; ++i) {
                if (nums[i] == target) {
                    return i;
                } else if (nums[i] > target || (i + 1 < n && nums[i] < target && nums[i] > nums[i + 1])) {
                    break;
                }
            }
        } else {
            for (int i = n - 1; i >= 0; --i) {
                if (nums[i] == target) {
                    return i;
                } else if (nums[i] < target || (i - 1 >= 0 && nums[i] > target && nums[i] < nums[i - 1])) {
                    break;
                }
            }
        }
        return -1;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> arr = {4, 5, 6, 8, -1, 1, 2};
    cout << Solution().search2(arr, 0) << endl;
    return 0;
}
