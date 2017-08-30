//
//  main.cpp
//  14. Longest Common Prefix
//
//  Created by limaoqi on 30/08/2017.
//  Copyright © 2017 limaoqi. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty() || strs[0].empty()) return "";
        string prefix = "";
        for (int i = 0; i < strs[0].length(); ++i) {
            char ch = strs[0][i];
            for (int j = 1; j < strs.size(); ++j) {
                if (i + 1 > strs[j].length() || strs[j][i] != ch) return prefix;
            }
            prefix.push_back(ch);
        }
        return prefix;
    }
};

int main(int argc, const char * argv[]) {
    vector<string> strs;
    do {
        string str;
        cin >> str;
        strs.push_back(str);
    } while (cin.get() != '\n');
    cout << Solution().longestCommonPrefix(strs) << endl;
    return 0;
}
