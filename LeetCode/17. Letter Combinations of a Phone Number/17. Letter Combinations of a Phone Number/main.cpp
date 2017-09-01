//
//  main.cpp
//  17. Letter Combinations of a Phone Number
//
//  Created by limaoqi on 31/08/2017.
//  Copyright © 2017 limaoqi. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 时间复杂度太高了
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return vector<string>();
        vector<vector<char>> table = {
            {},
            {},
            {'a', 'b', 'c'},
            {'d', 'e', 'f'},
            {'g', 'h', 'i'},
            {'j', 'k', 'l'},
            {'m', 'n', 'o'},
            {'p', 'q', 'r', 's'},
            {'t', 'u', 'v'},
            {'w', 'x', 'y', 'z'}
        };
        vector<string> res = {""};
        for (int i = 0; i < digits.size(); ++i) {
            vector<char> chs = table[(int)digits[i] - 48];
            vector<string> tmp;
            for (int j = 0; j < chs.size(); ++j) {
                for (int k = 0; k < res.size(); ++k) {
                    tmp.push_back(res[k] + chs[j]);
                }
            }
            res.swap(tmp);
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    string digits = "23";
    vector<string> res = Solution().letterCombinations(digits);
    for (int i = 0; i < res.size(); ++i) {
        cout << res[i] << " ";
    }
    return 0;
}
