//
//  main.cpp
//  22. Generate Parentheses
//
//  Created by 李茂琦 on 03/09/2017.
//  Copyright © 2017 李茂琦. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// wrong answer
class Solution1 {
public:
    vector<string> generateParenthesis(int n) {
        if (n == 1) return vector<string>(1, "()");
        vector<string> res = {"()"};
        for (int i = 2; i <= n; ++i) {
            vector<string> tmp = res;
            for (int i = 0; i < tmp.size(); ++i) {
                res[i] = "(" + tmp[i] + ")";
            }
            for (int i = 0; i < tmp.size() - 1; ++i) {
                res.push_back(tmp[i] + "()");
            }
            for (int i = 0; i < tmp.size(); ++i) {
                res.push_back("()" + tmp[i]);
            }
        }
        return res;
    }
};

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        backTrack(res, "", 0, 0, n);
        return res;
    }
    void backTrack(vector<string> &res, string str, int open, int close, int n) {
        if (str.length() == n * 2) {
            res.push_back(str);
            return;
        }
        if (open < n) {
            backTrack(res, str + "(", open + 1, close, n);
        }
        if (close < open) {
            backTrack(res, str + ")", open, close + 1, n);
        }
    }
};

int main(int argc, const char * argv[]) {
    int n = 0;
    while (cin >> n) {
        vector<string> res = Solution().generateParenthesis(n);
        for (int i = 0; i < res.size(); ++i) {
            cout << res[i] << endl;
        }
    }
    return 0;
}
