//
//  main.cpp
//  MedianOfTwoSortedArrays
//
//  Created by limaoqi on 22/08/2017.
//  Copyright © 2017 limaoqi. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = (int)nums1.size(), n = (int)nums2.size();
        int medianPos = (m + n - 1) / 2;
        double median = 0.0;
        int i = 0, j = 0;
        for (int k = 0; k <= medianPos; ++k) {
            if (i >= m) {
                median = nums2[j++];
            } else if (j >= n) {
                median = nums1[i++];
            } else if (nums1[i] <= nums2[j]) {
                median = nums1[i++];
            } else if (nums1[i] > nums2[j]) {
                median = nums2[j++];
            }
        }
        if ((m + n) % 2 != 0) {
            return median;
        } else if (i == m && j < n) {
            median = (median + nums2[j]) / 2.0;
        } else if (i < m && j == n) {
            median = (median + nums1[i]) / 2.0;
        } else if (nums1[i] <= nums2[j]) {
            median = (median + nums1[i]) / 2.0;
        } else if (nums1[i] > nums2[j]) {
            median = (median + nums2[j]) / 2.0;
        }
        return median;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> nums1 = {1, 2};
    vector<int> nums2 = {3, 4};
    cout << Solution().findMedianSortedArrays(nums1, nums2) << endl;
    return 0;
}
