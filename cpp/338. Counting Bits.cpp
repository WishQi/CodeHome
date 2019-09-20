//
//  main.cpp
//  338. Counting Bits
//
//  Created by Maoqi Li on 2019/9/20.
//  Copyright © 2019 Maoqi Li. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> countBits(int num) {
        if (num < 0) return {};
        if (num == 0) return {0};
        vector<int> res = vector<int>(num + 1, 0);
        for (int i = 1; i <= num; i++) {
            res[i] = res[i / 2] + i % 2;
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution().countBits(10);
    return 0;
}
