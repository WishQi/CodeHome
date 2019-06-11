//
//  main.cpp
//  139. Word Break
//
//  Created by Maoqi Li on 2019/6/11.
//  Copyright © 2019 Maoqi Li. All rights reserved.
//

#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if (s.empty()) return true;
        if (wordDict.empty()) return false;
        set<string> wordSet = set<string>(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        for (int i = 1; i <= s.size(); i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (dp[j] && wordSet.find(s.substr(j, i - j)) != wordSet.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.size()];
    }
};


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
