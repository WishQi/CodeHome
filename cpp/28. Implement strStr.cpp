//
//  main.cpp
//  28. Implement strStr()
//
//  Created by limaoqi on 05/09/2017.
//  Copyright © 2017 limaoqi. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    // 时间复杂度有点高
    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0;
        int len = (int)needle.length();
        for (int i = 0; i < (int)haystack.size() - len + 1; ++i) {
            if (haystack[i] == needle[0]) {
                if (haystack.substr(i, len) == needle) {
                    return i;
                }
            }
        }
        return -1;
    }
};

int main(int argc, const char * argv[]) {
    string str = "a";
    string needle = "a";
    cout << Solution().strStr(str, needle) << endl;
    return 0;
}
