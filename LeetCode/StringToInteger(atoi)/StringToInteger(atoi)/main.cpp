//
//  main.cpp
//  StringToInteger(atoi)
//
//  Created by limaoqi on 25/08/2017.
//  Copyright © 2017 limaoqi. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        if (str.empty()) return 0;
        vector<int> digits;
        bool hasSigned = false, positive = true;
        for (int i = 0; i < str.length(); ++i) {
            if (str[i] == ' ' && digits.empty() && !hasSigned) continue;
            if (str[i] >= '0' && str[i] <= '9') {
                digits.push_back((int)str[i] - 48);
            } else if (str[i] == '+' && !hasSigned) {
                positive = true;
                hasSigned = true;
            } else if (str[i] == '-' && !hasSigned) {
                positive = false;
                hasSigned = true;
            } else {
                break;
            }
        }
        if (digits.empty()) {
            return 0;
        }
        int result = 0;
        for (int i = 0; i < digits.size(); ++i) {
            if (((INT_MAX / 10 == result && digits[i] > 7) || (INT_MAX / 10 < result)) && positive) {
                return INT_MAX;
            }
            if (((INT_MAX / 10 == result && digits[i] > 8) || (INT_MAX / 10 < result)) && !positive) {
                return INT_MIN;
            }
            result = result * 10 + digits[i];
        }
        return positive ? result : -result;
    }
};


int main(int argc, const char * argv[]) {
    string str = "    10522545459";
    while (cin >> str) {
        cout << Solution().myAtoi(str) << endl;
    }
    return 0;
}
