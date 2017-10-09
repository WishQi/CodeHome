//
//  main.cpp
//  49. Group Anagrams
//
//  Created by limaoqi on 29/09/2017.
//  Copyright © 2017 limaoqi. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    // 35ms, AC, O(n * (k * lgk)):n为字符串数组长度，k为最长字符串的长度
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        map<string, vector<string>> table;
        for (int i = 0; i < (int)strs.size(); i++) {
            string tmpStr = strs[i];
            sort(tmpStr.begin(), tmpStr.end());
            table[tmpStr].push_back(strs[i]);
        }
        for (auto itr = table.begin(); itr != table.end(); itr++) {
            res.push_back(itr->second);
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    vector<string> arr = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> res = Solution().groupAnagrams(arr);
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
