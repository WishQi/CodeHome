//
//  main.cpp
//  152. Maximum Product Subarray
//
//  Created by Maoqi Li on 2019/7/15.
//  Copyright © 2019 Maoqi Li. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>

using namespace std;


class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.empty()) return 0;
        
        int maxherepre = nums[0];
        int minherepre = nums[0];
        int maxsofar = nums[0];
        int maxhere, minhere;
        
        for (int i = 1; i < nums.size(); i++) {
            maxhere = max(max(maxherepre * nums[i], minherepre * nums[i]), nums[i]);
            minhere = min(min(maxherepre * nums[i], minherepre * nums[i]), nums[i]);
            maxsofar = max(maxhere, maxsofar);
            maxherepre = maxhere;
            minherepre = minhere;
        }
        return maxsofar;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> test = {-3, 0, 1, -2};
    Solution().maxProduct(test);
    return 0;
}
