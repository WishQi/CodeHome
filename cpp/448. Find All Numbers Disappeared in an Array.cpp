//
//  main.cpp
//  448. Find All Numbers Disappeared in an Array
//
//  Created by limaoqi on 20/11/2017.
//  Copyright © 2017 limaoqi. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // 142ms, AC, 空间复杂度O(n), 时间复杂度O(n)
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = (int)nums.size();
        vector<bool> tags(n + 1, false);
        for (int i = 0; i <= n; i++) {
            if (nums[i] <= n && nums[i] >= 1) tags[nums[i]] = true;
        }
        vector<int> res;
        for (int i = 1; i <= n; i++) {
            if (!tags[i]) res.push_back(i);
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> arr = {4,3,2,7,8,2,3,1};
    vector<int> res = Solution().findDisappearedNumbers(arr);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    return 0;
}
