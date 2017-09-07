//
//  main.cpp
//  32. Longest Valid Parentheses
//
//  Created by limaoqi on 07/09/2017.
//  Copyright © 2017 limaoqi. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    // dynamic program
    int longestValidParentheses(string s) {
        int n = (int)s.length();
        vector<int> dp(n, 0);
        int maxLen = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == ')' && i > 0) {
                if (s[i - 1] == '(') {
                    if (i - 2 >= 0) {
                        dp[i] = dp[i - 2] + 2;
                    } else {
                        dp[i] = 2;
                    }
                } else {
                    int left = i - dp[i - 1] - 1;
                    if (left >= 0 && s[left] == '(') {
                        dp[i] = dp[i - 1] + dp[left - 1] + 2;
                    }
                }
            }
            if (dp[i] > maxLen) maxLen = dp[i];
        }
        return maxLen;
    }
    // stack
    int longestValidParentheses1(string s) {
        stack<int> sta;
        sta.push(-1);
        int maxLen = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(') {
                sta.push(i);
            } else if (!sta.empty()){
                sta.pop();
                if (sta.empty()) {
                    sta.push(i);
                } else {
                    int len = i - sta.top();
                    if (len > maxLen) maxLen = len;
                }
            }
        }
        return maxLen;
    }
};

int main(int argc, const char * argv[]) {
    string str = "()(())";
    cout << Solution().longestValidParentheses1(str) << endl;
    return 0;
}
