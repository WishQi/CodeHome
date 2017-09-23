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
    // 第二遍 29ms, AC
    int myAtoi1(string str) {
        if (str.empty()) return 0;
        vector<int> digits;
        bool hasSigned = false, positive = true;
        for (int i = 0; i < (int)str.length(); ++i) {
            if (str[i] == ' ' && !hasSigned) continue;
            if (str[i] == '+' && !hasSigned) {
                hasSigned = true;
                positive = true;
            } else if (str[i] == '-' && !hasSigned) {
                hasSigned = true;
                positive = false;
            } else if (str[i] >= '0' && str[i] <= '9') {
                hasSigned = true;
                digits.push_back((int)(str[i] - '0'));
            } else {
                break;
            }
        }
        if (digits.empty()) return 0;
        int res = 0;
        for (int i = 0; i < (int)digits.size(); ++i) {
            if (((INT_MAX / 10 == res && digits[i] > 7) || (INT_MAX / 10 < res)) && positive) return INT_MAX;
            if (((INT_MAX / 10 == res && digits[i] > 8) || (INT_MAX / 10 < res)) && !positive) return INT_MIN;
            res = res * 10 + digits[i];
        }
        return positive ? res : -res;
    }
    // 另一种写法, 19ms, AC
    int myAtoi2(string str) {
        int i = 0, n = (int)str.length();
        while (i < n && str[i] == ' ') i++;
        int sign = 1;
        if (str[i] == '+' || str[i] == '-') {
            sign = 1 - 2 * (str[i] == '-');
            i++;
        }
        int res = 0;
        while (i < n && str[i] >= '0' && str[i] <= '9') {
            int num = str[i] - '0';
            if (INT_MAX / 10 < res || (INT_MAX / 10 == res && num > 7)) {
                return sign == 1 ? INT_MAX : INT_MIN;
            }
            res = res * 10 + num;
            i++;
        }
        return res * sign;
    }
};


int main(int argc, const char * argv[]) {
    string str = "    10522545459";
    while (cin >> str) {
        cout << Solution().myAtoi2(str) << endl;
    }
    return 0;
}
