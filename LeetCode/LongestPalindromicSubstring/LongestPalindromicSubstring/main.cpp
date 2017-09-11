//
//  main.cpp
//  LongestPalindromicSubstring
//
//  Created by limaoqi on 23/08/2017.
//  Copyright © 2017 limaoqi. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

// dynamic programming
class Solution1 {
public:
    // 89ms, AC, O((n + 1) * n / 2)
    string longestPalindrome(string s) {
        if (s.length() <= 1) return s;
        bool dp[1001][1001] = { false };
        memset(dp, 0, sizeof(dp));
        int length = (int)s.length();
        dp[length - 1][length - 1] = true;
        int start = length - 1, maxLength = 1;
        for (int i = length - 2; i >= 0; --i) {
            for (int j = i; j < length; ++j) {
                dp[i][j] = ((s[i] == s[j]) && ((j - i + 1) < 3 || dp[i + 1][j - 1]));
                if (dp[i][j] && j - i + 1 > maxLength) {
                    start = i;
                    maxLength = j - i + 1;
                }
            }
        }
        return s.substr(start, maxLength);
    }
    // 82ms, AC, O((n + 1) * n / 2)
    string longestPalindrome1(string s) {
        int len = (int)s.length();
        if (len <= 1) return s;
        bool dp[1001][1001] = {false};
        memset(dp, false, sizeof(dp));
        int start = len - 1, maxLen = 0;
        for (int i = len - 1; i >= 0; --i) {
            for (int j = i; j < len; ++j) {
                int tmpLen = j - i + 1;
                dp[i][j] = s[i] == s[j] && (tmpLen <= 3 || dp[i + 1][j - 1]);
                if (dp[i][j] && tmpLen > maxLen) {
                    start = i;
                    maxLen = tmpLen;
                }
            }
        }
        return s.substr(start, maxLen);
    }
};

class Solution2 {
public:
    // 12ms, AC, O((n + 2) * n / 4)
    string longestPalindrome(string s) {
        int len = (int)s.length();
        if (len <= 1) return s;
        int start = 0, maxLen = 1;
        for (int i = 1; i < len; ++i) {
            // odd
            int lo = i - 1, hi = i;
            while (lo >= 0 && hi < len && s[lo] == s[hi]) {
                lo--;
                hi++;
            }
            int tmpLen = hi - lo - 1;
            if (tmpLen > maxLen) {
                start = lo + 1;
                maxLen = tmpLen;
            }
            // even
            lo = i - 1, hi = i + 1;
            while (lo >= 0 && hi < len && s[lo] == s[hi]) {
                lo--;
                hi++;
            }
            tmpLen = hi - lo - 1;
            if (tmpLen > maxLen) {
                start = lo + 1;
                maxLen = tmpLen;
            }
        }
        return s.substr(start, maxLen);
    }
};

int main(int argc, const char * argv[]) {
    string s = "defgfed";
    while (cin >> s) {
        cout << Solution2().longestPalindrome(s) << endl;
    }
    return 0;
}
