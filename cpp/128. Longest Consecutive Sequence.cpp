//
//  main.cpp
//  128. Longest Consecutive Sequence
//
//  Created by Maoqi Li on 2019/6/10.
//  Copyright © 2019 Maoqi Li. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        map<int, bool> record = map<int, bool>();
        for (int i = 0; i < nums.size(); i++) {
            record[nums[i]] = true;
        }
        int res = 1;
        int curRes = 1;
        auto itr1 = record.begin();
        auto itr2 = ++record.begin();
        while (itr2 != record.end()) {
            if (itr1->first == itr2->first - 1) {
                curRes++;
            } else {
                res = max(res, curRes);
                curRes = 1;
            }
            itr1++;
            itr2++;
        }
        return max(res, curRes);
    }
};

int main(int argc, const char * argv[]) {
    vector<int> test = {1, 2, 3};
    cout << Solution().longestConsecutive(test) << endl;
    return 0;
}
