//
//  main.cpp
//  79. Word Search
//
//  Created by Maoqi Li on 2019/5/16.
//  Copyright © 2019 Maoqi Li. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>

using namespace std;


class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (board.empty()) return false;
        if (board[0].empty()) return false;
        for (int i = 0; i < (int)board.size(); i++) {
            for (int j = 0; j < (int)board[i].size(); j++) {
                if (_exit(board, i, j, word, 0)) return true;
            }
        }
        return false;
    }
private:
    int a[1000][1000] = {0};
    bool _exit(vector<vector<char>>& board, int m, int n, string& word, int index) {
        if (index == (int)word.length()) {
            return true;
        }
        if (m < 0 || m >= board.size() || n < 0 || n >= board[m].size() || a[m][n] || board[m][n] != word[index]) {
            return false;
        }
        a[m][n] = 1;
        bool result = _exit(board, m + 1, n, word, index + 1) || _exit(board, m - 1, n, word, index + 1) || _exit(board, m, n + 1, word, index + 1) || _exit(board, m, n - 1, word, index + 1);
        a[m][n] = 0;
        return result;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    vector<vector<char>> board = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'E', 'S'},
        {'A', 'D', 'E', 'E'}
    };
    cout << Solution().exist(board, "ABCESEEEFS") << endl;
    return 0;
}
