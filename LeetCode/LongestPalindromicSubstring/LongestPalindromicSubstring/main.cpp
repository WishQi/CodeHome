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
};

class Solution2 {
public:
    string longestPalindrome(string s) {
        int length = (int)s.length();
        int start = 0, maxLength = 1;
        for (int i = 1; i < length; ++i) {
            // even
            int low = i - 1, high = i;
            while (low >= 0 && high < length && s[low] == s[high]) {
                --low;
                ++high;
            }
            if (high - low - 1 > maxLength) {
                start = low + 1;
                maxLength = high - low - 1;
            }
            // odd
            low = i - 1, high = i + 1;
            while (low >= 0 && high < length && s[low] == s[high]) {
                --low;
                ++high;
            }
            if (high - low - 1 > maxLength) {
                start = low + 1;
                maxLength = high - low - 1;
            }
        }
        return s.substr(start, maxLength);
    }
};

int main(int argc, const char * argv[]) {
    string s = "defgfed";
    cin >> s;
    cout << Solution1().longestPalindrome(s) << endl;
    return 0;
}
