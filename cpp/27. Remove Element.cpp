//
//  main.cpp
//  27. Remove Element
//
//  Created by limaoqi on 04/09/2017.
//  Copyright © 2017 limaoqi. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        for (auto itr = nums.begin(); itr != nums.end();) {
            if (*itr == val) {
                itr = nums.erase(itr);
            } else {
                ++itr;
            }
        }
        return (int)nums.size();
    }
};

int main(int argc, const char * argv[]) {
    vector<int> arr = {0};
    cout << Solution().removeElement(arr, 0) << endl;
    return 0;
}
