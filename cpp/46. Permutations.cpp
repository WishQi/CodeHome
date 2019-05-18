//
//  main.cpp
//  46. Permutations
//
//  Created by limaoqi on 29/09/2017.
//  Copyright © 2017 limaoqi. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> tmpArr;
        backTrack(res, tmpArr, nums);
        return res;
    }
    // 9ms, AC, 回溯法
    void backTrack(vector<vector<int>>& res, vector<int>& tmpArr, vector<int>& nums) {
        if (tmpArr.size() == nums.size()) {
            res.push_back(tmpArr);
            return;
        }
        for (int i = 0; i < (int)nums.size(); ++i) {
            if (find(tmpArr.begin(), tmpArr.end(), nums[i]) != tmpArr.end()) continue;
            tmpArr.push_back(nums[i]);
            backTrack(res, tmpArr, nums);
            tmpArr.erase(tmpArr.end() - 1);
        }
    }
};

int main(int argc, const char * argv[]) {
    vector<int> arr = {1, 2, 3};
    Solution().permute(arr);
    return 0;
}
