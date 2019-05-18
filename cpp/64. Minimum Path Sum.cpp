//
//  main.cpp
//  64. Minimum Path Sum
//
//  Created by Maoqi Li on 2019/2/24.
//  Copyright © 2019 Maoqi Li. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int SUM[1000][1000] = {0};

class Solution {
public:
    void p(vector<vector<int>>& grid) {
        if (grid.size() == 0) {
            return ;
        }
        if (grid[0].size() == 0) {
            return ;
        }
        SUM[0][0] = grid[0][0];
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (i == 0 && j > 0) {
                    SUM[i][j] = SUM[i][j - 1] + grid[i][j];
                } else if (i > 0 && j == 0) {
                    SUM[i][j] = SUM[i - 1][j] + grid[i][j];
                } else if (i > 0 && j > 0) {
                    SUM[i][j] = min(SUM[i - 1][j], SUM[i][j - 1]) + grid[i][j];
                }
            }
        }
    }
    int minPathSum(vector<vector<int>>& grid) {
        p(grid);
        int x = (int)grid.size();
        if (x == 0) {
            return 0;
        }
        int y = (int)grid[0].size();
        if (y == 0) {
            return 0;
        }
        return SUM[x - 1][y - 1];
    }
};

int main(int argc, const char * argv[]) {
    vector<vector<int>> grid = {
        {1, 3, 1},
        {1, 5, 1},
        {4, 2, 1}
    };
    cout << Solution().minPathSum(grid) << endl;
    
    return 0;
}
