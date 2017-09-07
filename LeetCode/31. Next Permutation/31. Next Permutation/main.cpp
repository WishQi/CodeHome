//
//  main.cpp
//  31. Next Permutation
//
//  Created by limaoqi on 07/09/2017.
//  Copyright © 2017 limaoqi. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = (int)nums.size();
        if (n <= 1) return;
        if (n == 2) {
            swap(nums[0], nums[1]);
            return;
        }
        for (int i = n - 2; i >= 0; --i) {
            int j;
            for (j = i + 1; j < n; ++j) {
                if (nums[i] < nums[j]) {
                    swap(nums[i], nums[j]);
                    break;
                }
            }
            if (j == n) {
                int tmp = nums[i];
                for (int k = i; k < n - 1; ++k) {
                    nums[k] = nums[k + 1];
                }
                nums[n - 1] = tmp;
            } else {
                break;
            }
        }
    }
};

int main(int argc, const char * argv[]) {
    vector<int> arr = {1, 1, 5};
    Solution().nextPermutation(arr);
    for (int i = 0; i < arr.size(); ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
