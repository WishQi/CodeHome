//
//  main.cpp
//  PalindromeNumber
//
//  Created by limaoqi on 28/08/2017.
//  Copyright © 2017 limaoqi. All rights reserved.
//

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

class Solution {
public:
    // 146ms, AC
    bool isPalindrome(int x) {
        if (x < 0) return false;
        int k = 0;
        for (int i = 10; i >= 0; --i) {
            if (x / (int)pow(10, i)) {
                k = i;
                break;
            }
        }
        int left = k + 1, right = 1;
        while (left > right) {
            int num1 = x / (int)pow(10, left - 1) % 10;
            int num2 = x / (int)pow(10, right - 1) % 10;
            if (num1 != num2) return false;
            --left, ++right;
        }
        return true;
    }
    // 102ms, AC
    bool isPalindrome1(int x) {
        if (x < 0) return false;
        int num = x;
        int k = 0;
        while (num > 0) {
            k++;
            num /= 10;
        }
        cout << k << endl;
        int lo = k - 1, hi = 0;
        while (lo >= hi) {
            int a = x / (int)pow(10, lo) % 10;
            int b = x / (int)pow(10, hi) % 10;
            if (a != b) return false;
            lo--, hi++;
        }
        return true;
    }
    // 178ms, AC
    bool isPalindrome2(int x) {
        if (x < 0 || (x > 0 && x % 10 == 0)) return false;
        int rev = 0;
        while (x > rev) {
            rev = rev * 10 + x % 10;
            x /= 10;
        }
        return x == rev || x == rev / 10;
    }
};

int main(int argc, const char * argv[]) {
    int num;
    while (cin >> num) {
        cout << Solution().isPalindrome2(num) << endl;
    }
    
    return 0;
}
