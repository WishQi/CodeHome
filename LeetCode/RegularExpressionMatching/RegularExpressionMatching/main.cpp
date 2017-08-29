//
//  main.cpp
//  RegularExpressionMatching
//
//  Created by limaoqi on 28/08/2017.
//  Copyright © 2017 limaoqi. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

// recursive
class Solution {
public:
    bool isMatch(string s, string p) {
        if (p.empty()) return s.empty();
        if (p.size() == 1) {
            return s.size() == 1 && (s[0] == p[0] || p[0] == '.');
        } else if (p[1] != '*') {
            return !s.empty() && (s[0] == p[0] || p[0] == '.') && isMatch(s.substr(1), p.substr(1));
        } else {
            return (!s.empty() && (s[0] == p[0] || p[0] == '.') && isMatch(s.substr(1), p)) || isMatch(s, p.substr(2));
        }
    }
};

// dynamic programming
class Solution1 {
public:
    bool isMatch(string s, string p) {
        bool dp[1001][1001];
        memset(dp, false, sizeof(dp));
        int m = (int)s.size(), n = (int)p.size();
        dp[0][0] = true;
        for (int i = 1; i <= m; ++i) dp[i][0] = false;
        for (int i = 1; i <= n; ++i) dp[0][i] = i > 1 && p[i - 1] == '*' && dp[0][i - 2];
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (p[j - 1] != '*') {
                    dp[i][j] = dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
                } else {
                    dp[i][j] = dp[i][j - 2] || ((s[i - 1] == p[j - 2] || p[j - 2] == '.') && dp[i - 1][j]);
                }
            }
        }
        return dp[m][n];
    }
};

int main(int argc, const char * argv[]) {
    string s, p;
    while (cin >> s >> p) {
        cout << Solution1().isMatch(s, p) << endl;
    }
    
    
    return 0;
}
