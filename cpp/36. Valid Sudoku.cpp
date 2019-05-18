//
//  main.cpp
//  36. Valid Sudoku
//
//  Created by limaoqi on 19/09/2017.
//  Copyright © 2017 limaoqi. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // 15ms, AC, O(n * n)
    // 通过三个二维数组来表示某个位置上的数是否已经出现过
    // used1[i][num]为true，表示第i行，num这个数已经出现过
    // used2[j][num]为true，表示第j列，num这个数已经出现过
    // used3[k][num]为true，表示第k个小方块中，num这个数已经出现过
    bool isValidSudoku(vector<vector<char>>& board) {
        bool used1[9][9] = {false}, used2[9][9] = {false}, used3[9][9] = {false};
        for (int i = 0; i < (int)board.size(); ++i) {
            for (int j = 0; j < (int)board[0].size(); ++j) {
                if (board[i][j] != '.') {
                    int num = board[i][j] - '0' - 1, k = i / 3 * 3 + j / 3;
                    if (used1[i][num] || used2[j][num] || used3[k][num]) {
                        return false;
                    }
                    used1[i][num] = used2[j][num] = used3[k][num] = true;
                }
            }
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
