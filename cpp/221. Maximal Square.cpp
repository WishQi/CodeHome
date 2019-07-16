//
//  main.cpp
//  221. Maximal Square
//
//  Created by Maoqi Li on 2019/7/16.
//  Copyright © 2019 Maoqi Li. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        int m = (int)matrix.size();
        int n = (int)matrix[0].size();
        vector<vector<int>> side(m, vector<int>(n, 0));
        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '0') {
                    side[i][j] = 0;
                    continue;
                }
                if (i == 0 || j == 0) {
                    side[i][j] = 1;
                } else {
                    side[i][j] = min(min(side[i - 1][j], side[i][j - 1]), side[i - 1][j - 1]) + 1;
                }
                res = max(res, side[i][j] * side[i][j]);
            }
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    vector<vector<char>> matric = {
        {'1','0','1','0','0'},
        {'1','0','1','1','1'},
        {'1','1','1','1','1'},
        {'1','0','0','1','0'}
    };
    Solution().maximalSquare(matric);
    return 0;
}
