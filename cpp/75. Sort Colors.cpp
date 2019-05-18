//
//  main.cpp
//  75. Sort Colors
//
//  Created by Maoqi Li on 2019/2/24.
//  Copyright © 2019 Maoqi Li. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int two = (int)nums.size() - 1;
        int zero = 0;
        for (int i = 0; i <= two; i++) {
            while (nums[i] == 2 && two > i) swap(nums[i], nums[two--]);
            while (nums[i] == 0 && zero < i) swap(nums[i], nums[zero++]);
        }
    }
};

int main(int argc, const char * argv[]) {
    vector<int> a ={2, 1, 2};
    Solution().sortColors(a);
    return 0;
}
