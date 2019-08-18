//
//  main.cpp
//  239. Sliding Window Maximum
//
//  Created by Maoqi Li on 2019/8/18.
//  Copyright © 2019 Maoqi Li. All rights reserved.
//

#include <iostream>
#include <vector>
#include <deque>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (k < 0) return vector<int>();
        if (k == 1 && nums.empty()) return nums;
        vector<int> results = vector<int>();
        deque<int> dq;
        for (int i = 0; i < nums.size(); i++) {
            while (!dq.empty() && dq.front() < i - k + 1) {
                dq.pop_front();
            }
            while (!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
            if (i >= k - 1) {
                results.push_back(nums[dq.front()]);
            }
        }
        return results;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> arr = {1,3,-1,-3,5,3,6,7};
    Solution().maxSlidingWindow(arr, 3);
    return 0;
}
