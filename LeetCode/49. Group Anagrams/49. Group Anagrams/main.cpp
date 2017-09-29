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
#include <set>

using namespace std;

class Solution {
public:
    // Time Limit Exceeded
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        set<string> keys;
        for (int i = 0; i < (int)strs.size(); i++) {
            string keyStr = strs[i];
            sort(keyStr.begin(), keyStr.end());
            if (keys.count(keyStr) != 0) continue;
            keys.insert(keyStr);
            vector<string> tmpStrs = {strs[i]};
            for (int j = i + 1; j < (int)strs.size(); j++) {
                string str = strs[j];
                sort(str.begin(), str.end());
                if (str == keyStr) tmpStrs.push_back(strs[j]);
            }
            res.push_back(tmpStrs);
        }
        return res;
    }
    vector<vector<string>> groupAnagrams1(vector<string>& strs) {
        
    }
};

int main(int argc, const char * argv[]) {
    vector<string> arr = {"eat", "tea", "tan", "ate", "nat", "bat"};
    Solution().groupAnagrams(arr);
    return 0;
}
