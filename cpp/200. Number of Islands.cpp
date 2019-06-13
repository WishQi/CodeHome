//
//  main.cpp
//  200. Number of Islands
//
//  Created by Maoqi Li on 2019/6/13.
//  Copyright © 2019 Maoqi Li. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    void _dfs(int i, int j, vector<vector<char>>& grid, int m, int n) {
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == '0') return;
        grid[i][j] = '0';
        _dfs(i - 1, j, grid, m, n);
        _dfs(i + 1, j, grid, m, n);
        _dfs(i, j - 1, grid, m, n);
        _dfs(i, j + 1, grid, m, n);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;
        if (grid[0].empty()) return 0;
        int m = (int)grid.size();
        int n = (int)grid[0].size();
        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    _dfs(i, j, grid, m, n);
                    res++;
                }
            }
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
