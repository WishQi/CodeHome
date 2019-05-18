//
//  main.cpp
//  18. 4Sum
//
//  Created by limaoqi on 01/09/2017.
//  Copyright © 2017 limaoqi. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if (nums.size() < 4) return vector<vector<int>>();
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for (int lo1 = 0; lo1 < (int)nums.size() - 3; ++lo1) {
            if (lo1 > 0 && nums[lo1] == nums[lo1 - 1]) continue;
            for (int hi1 = (int)nums.size() - 1; hi1 >= lo1 + 3; --hi1) {
                if (hi1 < (int)nums.size() - 1 && nums[hi1] == nums[hi1 + 1]) continue;
                int a = nums[lo1] + nums[hi1];
                int b = target - a;
                int lo2 = lo1 + 1, hi2 = hi1 - 1;
                while (lo2 < hi2) {
                    if (nums[lo2] + nums[hi2] == b) {
                        res.push_back({nums[lo1], nums[lo2], nums[hi2], nums[hi1]});
                        while (nums[lo2] == nums[lo2 + 1]) ++lo2;
                        while (nums[hi2] == nums[hi2 - 1]) --hi2;
                        ++lo2, --hi2;
                    } else if (nums[lo2] + nums[hi2] < b) {
                        ++lo2;
                    } else {
                        --hi2;
                    }
                }
            }
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> arr = {1,-2,-5,-4,-3,3,3,5};
    Solution().fourSum(arr, -11);
    return 0;
}
