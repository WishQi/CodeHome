//
//  main.cpp
//  283. Move Zeroes
//
//  Created by limaoqi on 03/11/2017.
//  Copyright © 2017 limaoqi. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // 26ms, AC, 时间复杂度：O(n * n), 空间复杂度：O(1)
    void moveZeroes(vector<int>& nums) {
        int count = 0;
        auto itr = nums.begin();
        while (itr != nums.end()) {
            if (*itr == 0) {
                itr = nums.erase(itr);
                count++;
                continue;
            }
            itr++;
        }
        for (int i = 0; i < count; i++) {
            nums.push_back(0);
        }
    }
    // 16ms, AC, 时间复杂度：O(n), 空间复杂度：O(1)
    void moveZeroes1(vector<int>& nums) {
        int lastNonZeroPos = 0;
        for (int i = 0; i < (int)nums.size(); i++) {
            if (nums[i] != 0) {
                nums[lastNonZeroPos] = nums[i];
                lastNonZeroPos++;
            }
        }
        for (int i = lastNonZeroPos; i < (int)nums.size(); i++) {
            nums[i] = 0;
        }
    }
    // 16ms, AC, 时间复杂度：O(n), 空间复杂度：O(1)
    void moveZeroes2(vector<int>& nums) {
        int lastNonZeroPos = 0;
        for (int i = 0; i < (int)nums.size(); i++) {
            if (nums[i] != 0) {
                swap(nums[lastNonZeroPos++], nums[i]);
            }
        }
    }
};

int main(int argc, const char * argv[]) {
    vector<int> arr = {0, 1, 2, 0, 0, 3};
    Solution().moveZeroes2(arr);
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
