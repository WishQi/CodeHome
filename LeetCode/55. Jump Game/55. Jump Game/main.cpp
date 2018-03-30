//
//  main.cpp
//  55. Jump Game
//
//  Created by 李茂琦 on 30/03/2018.
//  Copyright © 2018 李茂琦. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // Time Limit Exceeded
    bool back (vector<int>& nums, int index, int step) {
        if (index == nums.size() - 1) {
            return true;
        } else if (nums[index] < step) {
            return false;
        }
        if (back(nums, index + step, 1)) {
            return true;
        } else {
            return back(nums, index, ++step);
        }
    }
    // Time Limit Exceeded
    bool back1 (vector<int>& nums, int position) {
        if (position == (int)nums.size() - 1) {
            return true;
        }
        int range = (nums[position] + position) < (int)nums.size() - 1 ? nums[position] + position : (int)nums.size() - 1;
        for (int nextPosition = position + 1; nextPosition <= range; nextPosition++) {
            if (back1(nums, nextPosition)) {
                return true;
            }
        }
        return false;
    }
    // 14ms, AC
    bool greedy(vector<int>& nums) {
        int mostLeftGoodPosition = (int)nums.size() - 1;
        for (int position = (int)nums.size() - 1; position >= 0; position--) {
            if (position + nums[position] >= mostLeftGoodPosition) {
                mostLeftGoodPosition = position;
            }
        }
        return mostLeftGoodPosition == 0;
    }
    bool canJump(vector<int>& nums) {
//        return back(nums, 0, 1);
//        return back1(nums, 0);
        return greedy(nums);
    }
};

int main(int argc, const char * argv[]) {
    vector<int> arr = {2, 0, 0};
    cout << (Solution().canJump(arr) ? 1 : 0) << endl;
    return 0;
}
