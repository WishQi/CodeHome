//
//  main.cpp
//  461. Hamming Distance
//
//  Created by limaoqi on 01/12/2017.
//  Copyright © 2017 limaoqi. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    // 3ms, AC
    int hammingDistance(int x, int y) {
        // x, y >= 0
        int num = x ^ y, count = 0;
        while (num) {
            count++;
            num &= num - 1;
        }
        return count;
    }
};

int main(int argc, const char * argv[]) {
    cout << Solution().hammingDistance(-2, 4) << endl;
    return 0;
}
