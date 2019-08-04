//
//  main.cpp
//  238. Product of Array Except Self
//
//  Created by Maoqi Li on 2019/8/4.
//  Copyright © 2019 Maoqi Li. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class SolutionA {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result(nums.size(), 0);
        if (nums.size() <= 1) return result;
        int n = (int)nums.size();
        vector<int> pre(n, 0);
        vector<int> post(n, 0);
        pre[0] = nums[0];
        post[n - 1] = nums[n - 1];
        for (int i = 1; i < n; i++) pre[i] = pre[i - 1] * nums[i];
        for (int i = n - 2; i >= 0; i--) post[i] = post[i + 1] * nums[i];
        result[0] = post[1];
        result[n - 1] = pre[n - 2];
        for (int i = 1; i < n - 1; i++) result[i] = pre[i - 1] * post[i + 1];
        return result;
    }
};

class SolutionB {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result(nums.size(), 0);
        int n = (int)nums.size();
        vector<int> zero_flags = {};
        int product = 1;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                zero_flags.push_back(i);
            } else {
                product *= nums[i];
            }
        }
        if (zero_flags.size() > 1) return result;
        if (zero_flags.size() == 1) {
            result[zero_flags[0]] = product;
            return result;
        }
        for (int i = 0; i < n; i++) result[i] = product / nums[i];
        return result;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
