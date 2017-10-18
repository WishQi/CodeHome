//
//  main.cpp
//  198. House Robber
//
//  Created by limaoqi on 17/10/2017.
//  Copyright © 2017 limaoqi. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // 3ms, AC, O(n)
    int rob(vector<int>& nums) {
        int sum1 = 0, sum2 = 0;
        for (int i = 0; i < (int)nums.size(); i++) {
            if (i % 2 == 0) {
                sum1 = max(sum1 + nums[i], sum2);
            } else {
                sum2 = max(sum2 + nums[i], sum1);
            }
        }
        return max(sum1, sum2);
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
