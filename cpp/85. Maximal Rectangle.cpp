//
//  main.cpp
//  85. Maximal Rectangle
//
//  Created by Maoqi Li on 2019/5/22.
//  Copyright © 2019 Maoqi Li. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        if (matrix[0].empty()) return 0;
        int m = (int)matrix.size();
        int n = (int)matrix[0].size();
        int left[n], right[n], height[n];
        fill_n(left, n, 0);
        fill_n(right, n, n - 1);
        fill_n(height, n, 0);
        int maxArea = 0;
        for (int i = 0; i < m; i++) {
            int cur_left = 0, cur_right = n;
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '1') {
                    height[j] += 1;
                } else {
                    height[j] = 0;
                }
            }
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '1') {
                    left[j] = max(left[j], cur_left);
                } else {
                    left[j] = 0;
                    cur_left = j + 1;
                }
            }
            for (int j = n - 1; j >= 0; j--) {
                if (matrix[i][j] == '1') {
                    right[j] = min(right[j], cur_right);
                } else {
                    right[j] =  n - 1;
                    cur_right = j - 1;
                }
            }
            for (int j = 0; j < n; j++) {
                maxArea = max(maxArea, (right[j] - left[j] + 1) * height[j]);
            }
        }
        return maxArea;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    vector<vector<char>> matrix = {
        {'1','0','1','0','0'},
        {'1','0','1','1','1'},
        {'1','1','1','1','1'},
        {'1','0','0','1','0'}
    };
    return 0;
}
