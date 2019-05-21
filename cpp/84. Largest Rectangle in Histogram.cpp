//
//  main.cpp
//  84. Largest Rectangle in Histogram
//
//  Created by Maoqi Li on 2019/5/21.
//  Copyright © 2019 Maoqi Li. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>

using namespace std;


class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if (heights.empty()) return 0;
        stack<int> s;
        int maxSize = 0;
        int n = (int)heights.size();
        for (int i = 0; i <= n; i++) {
            int h = i < n ? heights[i] : -1;
            while (!s.empty() && h < heights[s.top()]) {
                int prevIdx = s.top();
                s.pop();
                int prevh = heights[prevIdx];
                int width = s.empty() ? i : i - 1 - s.top();
                maxSize = max(maxSize, prevh * width);
            }
            s.push(i);
        }
        return maxSize;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> testArr = {2, 1, 5, 6, 2, 3};
    cout << Solution().largestRectangleArea(testArr) << endl;
    return 0;
}
