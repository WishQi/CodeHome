//
//  main.cpp
//  96. Unique Binary Search Trees
//
//  Created by Maoqi Li on 2019/5/23.
//  Copyright © 2019 Maoqi Li. All rights reserved.
//

#include <iostream>

using namespace std;


class Solution {
public:
    int numTrees(int n) {
        int F[n + 1];
        fill_n(F, n + 1, 0);
        F[0] = 1;
        F[1] = 1;
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                F[i] += (F[j - 1] * F[i - j]);
            }
        }
        return F[n];
    }
};


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    cout << Solution().numTrees(3) << endl;
    return 0;
}
