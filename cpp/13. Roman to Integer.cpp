//
//  main.cpp
//  13. Roman to Integer
//
//  Created by limaoqi on 30/08/2017.
//  Copyright © 2017 limaoqi. All rights reserved.
//

#include <iostream>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        map<char, int> table = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };
        int result = 0, i = 0;
        while (i < s.length()) {
            if (i + 1 < s.length() && table[s[i]] < table[s[i + 1]]) {
                result += (table[s[i + 1]] - table[s[i]]);
                i += 2;
            } else {
                result += table[s[i]];
                ++i;
            }
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    string str;
    while (cin >> str) {
        cout << Solution().romanToInt(str) << endl;
    }
    return 0;
}
