//
//  main.cpp
//  35. Search Insert Position
//
//  Created by limaoqi on 06/09/2017.
//  Copyright © 2017 limaoqi. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int index = 0;
        while (index < nums.size()) {
            if (nums[index] < target) {
                ++index;
            } else {
                break;
            }
        }
        return index;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> arr = {1, 3, 5, 6};
    cout << Solution().searchInsert(arr, 0) << endl;
    return 0;
}
