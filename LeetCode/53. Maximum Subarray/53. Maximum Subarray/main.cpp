//
//  main.cpp
//  53. Maximum Subarray
//
//  Created by limaoqi on 27/09/2017.
//  Copyright © 2017 limaoqi. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // 9ms, AC, O(n)
    int maxSubArray(vector<int>& nums) {
        int n = (int)nums.size();
        if (n == 0) return 0;
        vector<int> sums(n, 0);
        sums[0] = nums[0];
        int maxSum = sums[0];
        for (int i = 1; i < n; ++i) {
            if (sums[i - 1] < 0) {
                sums[i] = nums[i];
            } else {
                sums[i] = sums[i - 1] + nums[i];
            }
            if (sums[i] > maxSum) maxSum = sums[i];
        }
        return maxSum;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> arr = {-2,1,-3,4,-1,2,1,-5,4};
    cout << Solution().maxSubArray(arr) << endl;
    return 0;
}
