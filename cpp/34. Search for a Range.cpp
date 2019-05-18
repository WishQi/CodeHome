//
//  main.cpp
//  34. Search for a Range
//
//  Created by limaoqi on 08/09/2017.
//  Copyright © 2017 limaoqi. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // 9ms
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2, -1);
        if (nums.empty()) return res;
        int lo = 0, hi = (int)nums.size() - 1, mid = 0;
        while (lo <= hi) {
            mid = (lo + hi) / 2;
            if (nums[mid] == target) {
                break;
            } else if (nums[mid] < target) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        if (lo > hi) return res;
        res[0] = mid, res[1] = mid;
        int hi1 = mid, lo1 = mid;
        while (lo <= hi1) {
            int midTmp = (lo + hi1) / 2;
            if (nums[midTmp] < target) {
                lo = midTmp + 1;
            } else {
                if (midTmp - 1 >= 0 && nums[midTmp - 1] < target) {
                    res[0] = midTmp;
                    break;
                }
                hi1 = midTmp - 1;
            }
        }
        if (lo > hi1) res[0] = lo;
        while (lo1 <= hi) {
            int midTmp = (lo1 + hi) / 2;
            if (nums[midTmp] > target) {
                hi = midTmp - 1;
            } else {
                if (midTmp + 1 < (int)nums.size() && nums[midTmp + 1] > target) {
                    res[1] = midTmp;
                    break;
                }
                lo1 = midTmp + 1;
            }
        }
        if (lo1 > hi) res[1] = hi;
        return res;
    }
    // 9ms
    vector<int> searchRange1(vector<int>& nums, int target) {
        vector<int> res(2, -1);
        if (nums.empty()) return res;
        int lo = 0, hi = (int)nums.size() - 1, mid = 0;
        while (lo <= hi) {
            mid = (lo + hi) / 2;
            if (nums[mid] == target) {
                break;
            } else if (nums[mid] < target) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        if (lo > hi) return res;
        res[0] = mid, res[1] = mid;
        while (lo < mid) {
            if (nums[lo] == target) {
                res[0] = lo;
                break;
            }
            lo++;
        }
        while (hi > mid) {
            if (nums[hi] == target) {
                res[1] = hi;
                break;
            }
            hi--;
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> arr = {1,2,3,3,3,3,4,5,9};
    Solution().searchRange1(arr, 3);
    return 0;
}

//[1,2,3,3,3,3,4,5,9]
//3
