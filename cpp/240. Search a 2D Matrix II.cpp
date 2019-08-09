//
//  main.cpp
//  240. Search a 2D Matrix II
//
//  Created by Maoqi Li on 2019/8/9.
//  Copyright © 2019 Maoqi Li. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty()) return false;
        int m = (int)matrix.size();
        int n = (int)matrix[0].size();
        int i = 0;
        int j = n - 1;
        while (i < m && j >= 0) {
            if (matrix[i][j] == target) return true;
            if (matrix[i][j] > target) {
                j--;
            } else {
                i++;
            }
        }
        return false;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<vector<int>> test = {
        {1,4,7,11,15},
        {2,5,8,12,19},
        {3,6,9,16,22},
        {10,13,14,17,24},
        {18,21,23,26,30}
    };
    cout << Solution().searchMatrix(test, 18) << endl;
    return 0;
}
