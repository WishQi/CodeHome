//
//  main.cpp
//  Two Sum
//
//  Created by limaoqi on 17/08/2017.
//  Copyright © 2017 limaoqi. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i + 1; j < nums.size(); ++j) {
                if (nums[i] + nums[j] == target) {
                    result.push_back(i);
                    result.push_back(j);
                    break;
                }
            }
            if (!result.empty()) break;
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> a = {2, 7, 11, 15};
    vector<int> b = Solution().twoSum(a, 9);
    return 0;
}
