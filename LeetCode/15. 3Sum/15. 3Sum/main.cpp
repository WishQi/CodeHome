//
//  main.cpp
//  15. 3Sum
//
//  Created by limaoqi on 30/08/2017.
//  Copyright © 2017 limaoqi. All rights reserved.
//

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> results;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i + 1; j < nums.size(); ++j) {
                for (int k = j + 1; k < nums.size(); ++k) {
                    if (nums[i] + nums[j] + nums[k] == 0) {
                        vector<int> v = {nums[i], nums[j], nums[k]};
                        sort(v.begin(), v.end());
                        results.insert(v);
                    }
                }
            }
        }
        vector<vector<int>> r;
        for (auto itr = results.begin(); itr != results.end(); ++itr) r.push_back(*itr);
        return r;
    }
    vector<vector<int>> threeSum1(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        for (int i = 0; i < (int)nums.size() - 2; ++i) {
            if ((i > 0 && nums[i] != nums[i - 1]) || i == 0) {
                int lo = i + 1, hi = (int)nums.size() - 1;
                while (lo < hi) {
                    if (nums[lo] + nums[hi] == -nums[i]) {
                        vector<int> v = {nums[i], nums[lo], nums[hi]};
                        result.push_back(v);
                        while (lo < hi && nums[lo] == nums[lo + 1]) ++lo;
                        while (lo < hi && nums[hi] == nums[hi - 1]) --hi;
                        ++lo, --hi;
                    } else if (nums[lo] + nums[hi] < -nums[i]) {
                        ++lo;
                    } else {
                        --hi;
                    }
                }
            }
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> arr = {};
    vector<vector<int>> re = Solution().threeSum1(arr);
    for (int i = 0; i < re.size(); ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << re[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
