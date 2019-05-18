//
//  main.cpp
//  581. Shortest Unsorted Continuous Subarray
//
//  Created by Maoqi Li on 2019/5/18.
//  Copyright © 2019 Maoqi Li. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        if (nums.empty()) return 0;
        int left = 0;
        int right = (int)nums.size() - 1;
        while (left <= right && left + 1 < (int)nums.size()) {
            if (nums[left] > nums[left + 1]) break;
            left++;
        }
        while (left <= right && right - 1 >= 0) {
            if (nums[right] < nums[right - 1]) break;
            right--;
        }
        if (left == right) return 0;
        int minNum = nums[left], maxNum = nums[left];
        for (int i = left; i <= right; i++) {
            if (nums[i] < minNum) minNum = nums[i];
            if (nums[i] > maxNum) maxNum = nums[i];
        }
        int head = 0;
        int tail = (int)nums.size() - 1;
        while (head < left) {
            if (nums[head] > minNum) break;
            head++;
        }
        while (tail > right) {
            if (nums[tail] < maxNum) break;
            tail--;
        }
        return tail - head + 1;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    vector<int> nums = {1,3,2,2,2};
    cout << Solution().findUnsortedSubarray(nums) << endl;
    return 0;
}
