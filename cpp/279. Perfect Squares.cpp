//
//  main.cpp
//  279. Perfect Squares
//
//  Created by Maoqi Li on 2019/8/18.
//  Copyright © 2019 Maoqi Li. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int numSquares(int n) {
        vector<int> dp = vector<int>(n + 1, INT32_MAX);
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j * j <= i; j++) {
                dp[i] = min(dp[i],  dp[i - j * j] + 1);
            }
        }
        return dp[n];
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    cout << Solution().numSquares(10) << endl;
    return 0;
}
