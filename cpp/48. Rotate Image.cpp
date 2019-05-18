//
//  main.cpp
//  48. Rotate Image
//
//  Created by 李茂琦 on 15/03/2018.
//  Copyright © 2018 李茂琦. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // AC, 8ms, 时间复杂度：n * n
    void rotate(vector<vector<int>>& matrix) {
        int N = (int)matrix.size();
        for (int i = 0; i < N / 2; i++) {
            for (int j = i; j < N - i - 1; j++) {
                int m = i, n = j;
                int prev = matrix[m][n];
                for (int k = 0; k < 4; k++) {
                    int tmp = matrix[n][N - 1 - m];
                    matrix[n][N - 1 - m] = prev;
                    prev = tmp;
                    int tmpm = m;
                    m = n;
                    n = N - 1 - tmpm;
                }
            }
        }
    }
};

int main(int argc, const char * argv[]) {
    vector<vector<int>> nums = {{5, 1, 9, 11}, {2, 4, 8, 10}, {13, 3, 6, 7}, {15, 14, 12, 16}};
    Solution().rotate(nums);
    for (int i = 0; i < (int)nums.size(); i++) {
        for (int j = 0; j < (int)nums.size(); j++) {
            cout << nums[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
