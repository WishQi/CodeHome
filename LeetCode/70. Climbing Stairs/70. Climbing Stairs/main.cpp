//
//  main.cpp
//  70. Climbing Stairs
//
//  Created by limaoqi on 09/10/2017.
//  Copyright © 2017 limaoqi. All rights reserved.
//

#include <iostream>

using namespace std;

typedef unsigned long long ull;

class Solution {
public:
    // 0ms, AC, fibonacci数列
    int climbStairs(int n) {
        int first = 1;
        int second = 2;
        if (n == 1) return first;
        if (n == 2) return second;
        for (int i = 3; i <= n; i++) {
            int third = first + second;
            first = second;
            second = third;
        }
        return second;
    }
};

int main(int argc, const char * argv[]) {
    int n;
    while (cin >> n) {
        cout << Solution().climbStairs(n) << endl;
    }
    return 0;
}
