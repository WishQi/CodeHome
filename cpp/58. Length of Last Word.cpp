//
//  main.cpp
//  58. Length of Last Word
//
//  Created by limaoqi on 03/11/2017.
//  Copyright © 2017 limaoqi. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    // 6ms, AC, O(n)
    int lengthOfLastWord(string s) {
        int len = (int)s.length();
        int end = len - 1;
        while (end >= 0 && s[end] == ' ') end--;
        if (end < 0) return 0;
        int start = end;
        while (start >= 0 && s[start] != ' ') start--;
        return end - start;
    }
};

int main(int argc, const char * argv[]) {
    string s;
    while (getline(cin, s)) {
        cout << Solution().lengthOfLastWord(s) << endl;
    }
    return 0;
}
