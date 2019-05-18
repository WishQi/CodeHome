//
//  main.cpp
//  42. Trapping Rain Water
//
//  Created by limaoqi on 28/09/2017.
//  Copyright © 2017 limaoqi. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    // 672ms, AC, O(n * n)
    int trap(vector<int>& height) {
        int res = 0;
        int n = (int)height.size();
        for (int i = 0; i < n; ++i) {
            int maxLeft = 0, maxRight = 0;
            for (int j = i; j >= 0; j--) {
                maxLeft = max(maxLeft, height[j]);
            }
            for (int k = i; k < n; k++) {
                maxRight = max(maxRight, height[k]);
            }
            res += min(maxLeft, maxRight) - height[i];
        }
        return res;
    }
    // dynamic programming, 12ms, AC, O(n)
    // 用两个数组记录每个位置两边的最大值
    int trap1(vector<int>& height) {
        int n = (int)height.size();
        if (n == 0) return 0;
        vector<int> leftMax(n, 0), rightMax(n, 0);
        leftMax[0] = height[0];
        for (int i = 1; i < n; ++i) {
            leftMax[i] = max(height[i], leftMax[i - 1]);
        }
        rightMax[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            rightMax[i] = max(height[i], rightMax[i + 1]);
        }
        int res = 0;
        for (int i = 0; i < n; ++i) {
            res += min(leftMax[i], rightMax[i]) - height[i];
        }
        return res;
    }
    // 用stack, 22ms, AC, O(n)
    int trap2(vector<int>& height) {
        int n = (int)height.size();
        if (n == 0) return 0;
        stack<int> sta;
        int curr = 0, res = 0;
        while (curr < n) {
            while (!sta.empty() && height[curr] > height[sta.top()]) {
                int pre = sta.top();
                sta.pop();
                if (sta.empty()) break;
                int wid = curr - sta.top() - 1;
                int hei = min(height[sta.top()], height[curr]) - height[pre];
                res += wid * hei;
            }
            sta.push(curr++);
        }
        return res;
    }
    // 双指针, 9ms, AC, O(n)
    int trap3(vector<int>& height) {
        int n = (int)height.size();
        if (n == 0) return 0;
        int res = 0;
        int lo = 0, hi = n - 1;
        int maxLeft = 0, maxRight = 0;
        while (lo < hi) {
            if (height[lo] < height[hi]) {
                height[lo] > maxLeft ? maxLeft = height[lo] : res += maxLeft - height[lo];
                lo++;
            } else {
                height[hi] > maxRight ? maxRight = height[hi] : res += maxRight - height[hi];
                hi--;
            }
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> arr = {2, 0, 2};
    cout << Solution().trap3(arr) << endl;
    return 0;
}
