//
//  main.cpp
//  76. Minimum Window Substring
//
//  Created by Maoqi Li on 2019/3/10.
//  Copyright © 2019 Maoqi Li. All rights reserved.
//

#include <iostream>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty() || s.length() < t.length()) return "";
        map<char, int> letterCount;
        for (int i = 0; i < (int)t.length(); i++) {
            letterCount[t[i]]++;
        }
        map<char, int> windowCount;
        int left = 0;
        int right = 0;
        int formed = 0;
        int required = (int)letterCount.size();
        int ans[] = {0, -1}; // start, length
        while (right < s.length()) {
            char c = s[right];
            windowCount[c]++;
            if (letterCount.find(c) != letterCount.end() && windowCount[c] == letterCount[c]) {
                formed++;
            }
            while (left <= right && formed == required) {
                c = s[left];
                if (ans[1] == -1 || right - left + 1 < ans[1]) {
                    ans[0] = left;
                    ans[1] = right - left + 1;
                }
                windowCount[c]--;
                if (letterCount.find(c) != letterCount.end() && windowCount[c] < letterCount[c]) {
                    formed--;
                }
                left++;
            }
            right++;
        }
        return ans[1] == -1 ? "" : s.substr(ans[0], ans[1]);
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    cout << Solution().minWindow("aa", "aa") << endl;
    return 0;
}
