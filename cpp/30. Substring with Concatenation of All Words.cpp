//
//  main.cpp
//  30. Substring with Concatenation of All Words
//
//  Created by limaoqi on 07/09/2017.
//  Copyright © 2017 limaoqi. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        if (s.empty() || words.empty()) return res;
        map<string, int> table;
        for (int i = 0; i < words.size(); ++i) table[words[i]]++;
        int len = (int)words[0].length();
        for (int i = 0; i < len; ++i) {
            map<string, int> tmpTable;
            int start = i, count = 0;
            for (int j = start; j <= (int)s.length() - len; j += len) {
                string str = s.substr(j, len);
                if (table.count(str) > 0) {
                    tmpTable[str]++;
                    count++;
                    while (tmpTable[str] > table[str]) {
                        string leftMost = s.substr(start, len);
                        tmpTable[leftMost]--, count--;
                        start += len;
                    }
                    if (count == words.size()) {
                        res.push_back(start);
                        string leftMost = s.substr(start, len);
                        tmpTable[leftMost]--, count--;
                        start += len;
                    }
                } else {
                    tmpTable.clear();
                    start = j + len;
                    count = 0;
                }
            }
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    string str = "mississippi";
    vector<string> words = {"mississippis"};
    Solution().findSubstring(str, words);
    return 0;
}
