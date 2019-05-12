//
//  main.cpp
//  78. Subsets
//
//  Created by Maoqi Li on 2019/3/10.
//  Copyright © 2019 Maoqi Li. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> results = vector<vector<int>>();
        if (nums.empty()) {
            results.push_back({});
            return results;
        }
        for (int i = 0; i < (int)nums.size(); i++) {
            vector<vector<int>> new_results(results);
            for (int j = 0; j < new_results.size(); j++) {
                new_results[j].push_back(nums[i]);
            }
            new_results.push_back({nums[i]});
            results.insert(results.end(), new_results.begin(), new_results.end());
        }
        results.push_back({});
        return results;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> nums = {1, 2, 3, 4};
    Solution().subsets(nums);
    return 0;
}
