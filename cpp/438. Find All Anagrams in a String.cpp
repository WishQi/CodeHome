//
//  main.cpp
//  438. Find All Anagrams in a String
//
//  Created by Maoqi Li on 2019/5/12.
//  Copyright © 2019 Maoqi Li. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        transform(p.begin(), p.end(), p.begin(), ::tolower);
        vector<int> alpha(26, 0);
        for (int i = 0; i < p.length(); i++) {
            ++alpha[(int)(p[i] - 'a')];
        }
        vector<int> start_index;
        if (s.length() < p.length()) {
            return start_index;
        }
        int start = 0;
        while (start <= s.length() - p.length()) {
            int rest = (int)p.length();
            vector<int> tmp(alpha);
            vector<int> pos(26, 0);
            for (int i = 0; i < p.length(); i++) {
                int index = (int)(s[start + i] - 'a');
                if (alpha[index] == 0) {
                    start += i + 1;
                    break;
                } else if (tmp[index] == 0) {
                    start = pos[index] + 1;
                    break;
                } else {
                    pos[index] = start + i;
                    tmp[index]--;
                    --rest;
                    if (rest == 0) {
                        start_index.push_back(start);
                        start++;
                        break;
                    }
                }
            }
        }
        return start_index;
    }
};

int main(int argc, const char * argv[]) {
    Solution().findAnagrams("op", "by");
    return 0;
}
