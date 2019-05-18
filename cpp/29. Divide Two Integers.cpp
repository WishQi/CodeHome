//
//  main.cpp
//  29. Divide Two Integers
//
//  Created by limaoqi on 06/09/2017.
//  Copyright © 2017 limaoqi. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    // time exceed
    int divide(int dividend, int divisor) {
        if (divisor == 0) return INT_MAX;
        if (dividend == 0) return 0;
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;
        if (divisor == 1) return dividend;
        if (divisor == -1) return -dividend;
        int a = abs(dividend), b = abs(divisor);
        int diff = a - b, res = 0;
        while (diff >= 0) {
            ++res;
            diff -= b;
        }
        if ((dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0)) {
            res = -res;
        }
        return res;
    }
    int divide1(int dividend, int divisor) {
        if (divisor == 0 || (dividend == INT_MIN && divisor == -1)) return INT_MAX;
        if (dividend == 0) return 0;
        int sign = (dividend > 0) ^ (divisor > 0) ? -1 : 1;
        long long a = labs(dividend), b = labs(divisor);
        int res = 0;
        while (a >= b) {
            long long tmp = b;
            int multiple = 1;
            while (a >= (tmp << 1)) {
                tmp <<= 1;
                multiple <<= 1;
            }
            a -= tmp;
            res += multiple;
        }
        return sign == -1 ? -res : res;
    }
};

int main(int argc, const char * argv[]) {
    int a, b;
    cout << INT_MAX << " " << INT_MIN << endl;
    while (cin >> a && cin >> b) {
        int c = a / b;
        cout << c << " ";
        cout << Solution().divide1(a, b) << endl;
    }
    return 0;
}

// 2147483647 -2147483648
//-2147483648 -1
