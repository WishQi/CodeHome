//
//  main.cpp
//  121. Best Time to Buy and Sell Stock
//
//  Created by limaoqi on 11/10/2017.
//  Copyright © 2017 limaoqi. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // 13ms, AC, O(n)
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int diff = 0;
        for (int i = 0; i < (int)prices.size(); i++) {
            if (prices[i] < minPrice) {
                minPrice = prices[i];
            } else {
                diff = max(diff, prices[i] - minPrice);
            }
        }
        return diff;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> prices = {2, 1, 2, 0, 1};
    cout << Solution().maxProfit(prices) << endl;
    return 0;
}
