//
//  main.cpp
//  26. Remove Duplicates from Sorted Array
//
//  Created by limaoqi on 04/09/2017.
//  Copyright © 2017 limaoqi. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        auto itr = nums.begin();
        while (itr != nums.end()) {
            if (itr > nums.begin() && *itr == *(itr - 1)) {
                itr = nums.erase(itr);
            } else {
                ++itr;
            }
        }
        return (int)nums.size();
    }
};

int main(int argc, const char * argv[]) {
    vector<int> arr = {1, 1, 2, 2};
    cout << Solution().removeDuplicates(arr) << endl;
    return 0;
}
