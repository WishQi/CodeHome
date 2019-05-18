//
//  main.cpp
//  39. Combination Sum
//
//  Created by 李茂琦 on 23/09/2017.
//  Copyright © 2017 李茂琦. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // 12ms, AC, 回溯法
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> combination;
        sort(candidates.begin(), candidates.end());
        solve(res, combination, candidates, target, 0);
        return res;
    }
    void solve(vector<vector<int>> &res, vector<int> &combination, vector<int> &candidates, int target, int begin) {
        if (target == 0) {
            res.push_back(combination);
            return;
        }
        for (int i = begin; i < (int)candidates.size(); ++i) {
            int num = candidates[i];
            if (num <= target) {
                combination.push_back(num);
                solve(res, combination, candidates, target - num, i);
                combination.pop_back();
            } else {
                break;
            }
        }
    }
};

int main(int argc, const char * argv[]) {
    int target;
    cin >> target;
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    Solution().combinationSum(arr, target);
    
    return 0;
}
