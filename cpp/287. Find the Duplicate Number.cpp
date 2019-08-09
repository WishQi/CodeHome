//
//  main.cpp
//  287. Find the Duplicate Number
//
//  Created by Maoqi Li on 2019/8/9.
//  Copyright © 2019 Maoqi Li. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        if (nums.empty()) return 0;
        sort(nums.begin(), nums.end());
        int last = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == last) {
                break;
            }
            last = nums[i];
        }
        return last;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> test = {1,3,4,2,2};
    Solution().findDuplicate(test);
    return 0;
}
