//
//  main.cpp
//  LongestSubstringWithoutRepeatingCharacters
//
//  Created by limaoqi on 18/08/2017.
//  Copyright © 2017 limaoqi. All rights reserved.
//

#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    // 35 ms(AC)
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) return 0;
        map<char, int> table = {};
        vector<int> lengthArr = {};
        table[s[0]] = 0;
        lengthArr.push_back(1);
        for (int i = 1; i < s.length(); ++i) {
            int distance = 0, length = 0;
            auto itr = table.find(s[i]);
            if (itr != table.end()) {
                distance = i - itr->second;
                length = lengthArr[i - 1] + 1;
                if (distance > length) {
                    lengthArr.push_back(length);
                } else {
                    lengthArr.push_back(distance);
                }
            } else {
                lengthArr.push_back(lengthArr[i - 1] + 1);
            }
            table[s[i]] = i;
        }
        return *max_element(lengthArr.begin(), lengthArr.end());
    }
    // 35 ms(AC)
    int lengthOfLongestSubstring1(string s) {
        map<char, int> table;
        int res = 0;
        int n = (int)s.length();
        for (int i = 0, j = 0; j < n; ++j) {
            if (table.count(s[j])) {
                i = max(i, table[s[j]] + 1);
            }
            res = max(res, j - i + 1);
            table[s[j]] = j;
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    
    string s = "12345";
    cout << Solution().lengthOfLongestSubstring1(s) << endl;
    
    return 0;
}
