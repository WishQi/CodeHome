//
//  main.cpp
//  ReverseInteger
//
//  Created by limaoqi on 24/08/2017.
//  Copyright © 2017 limaoqi. All rights reserved.
//

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

class Solution {
public:
    int reverse(int32_t x) {
        if (x == INT32_MIN) return 0;
        vector<int> digits;
        bool flag = (x >= 0 ? 1 : 0);
        x = abs(x);
        while (x >= 10) {
            digits.push_back(x % 10);
            x /= 10;
        }
        digits.push_back(x);
        int n = (int)digits.size();
        x = 0;
        for (int i = 0; i < digits.size(); ++i) {
            x += digits[i] * pow(10, n - i - 1);
        }
        x = flag ? x : -x;
        if ((flag && x < 0) || (!flag && x >= 0)) {
            return 0;
        }
        return x;
    }
};

int main(int argc, const char * argv[]) {
    cout << INT32_MIN << endl;
    cout << Solution().reverse(INT32_MIN) << endl;
    return 0;
}
