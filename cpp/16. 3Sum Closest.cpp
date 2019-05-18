//
//  main.cpp
//  16. 3Sum Closest
//
//  Created by limaoqi on 31/08/2017.
//  Copyright © 2017 limaoqi. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int result = INT_MAX, diff = INT_MAX;
        for (int i = 0; i < nums.size(); ++i) {
            if (i == 0 || (i > 0 && nums[i] != nums[i - 1])) {
                int lo = i + 1, hi = (int)nums.size() - 1;
                while (lo < hi) {
                    int key = target - nums[i];
                    if (diff > abs(nums[lo] + nums[hi] - key)) {
                        diff = abs(nums[lo] + nums[hi] - key);
                        result = nums[i] + nums[lo] + nums[hi];
                    }
                    if (nums[lo] + nums[hi] == key) {
                        return target;
                    } else if (nums[lo] + nums[hi] < key) {
                        ++lo;
                    } else {
                        --hi;
                    }
                }
            }
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> arr = {-1, 3, 1, -4};
    cout << Solution().threeSumClosest(arr, 1) << endl;
    return 0;
}
