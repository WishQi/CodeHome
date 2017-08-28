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
};

int main(int argc, const char * argv[]) {
    int num;
    while (cin >> num) {
        cout << Solution().isPalindrome(num) << endl;
    }
    
    return 0;
}
