//
//  main.cpp
//  20. Valid Parentheses
//
//  Created by limaoqi on 01/09/2017.
//  Copyright © 2017 limaoqi. All rights reserved.
//

#include <iostream>
#include <string>
#include <map>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        map<char, char> table = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };
        stack<char> sta;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                sta.push(s[i]);
            } else {
                if (sta.empty() || sta.top() != table[s[i]]) return false;
                sta.pop();
            }
        }
        return sta.empty();
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
