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
    // 45ms: O((m + n - 1) / 2)
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
    // 62ms: O(log(min(m, n)))
    double findMedianSortedArrays1(vector<int>& nums1, vector<int>& nums2) {
        int m  = (int)nums1.size(), n = (int)nums2.size();
        if (m > n) return findMedianSortedArrays1(nums2, nums1);
        int lo = 0, hi = m, halfLen = (m + n + 1) / 2;
        while (lo <= hi) {
            int i = (lo + hi) / 2, j = halfLen - i;
            if (i >= 1 && nums1[i - 1] > nums2[j]) {
                hi = i - 1;
            } else if (i < m && nums2[j - 1] > nums1[i]) {
                lo = i + 1;
            } else {
                int left = 0;
                if (i == 0 && j > 0) {
                    left = nums2[j - 1];
                } else if (j == 0 && i > 0) {
                    left = nums1[i - 1];
                } else {
                    left = max(nums1[i - 1], nums2[j - 1]);
                }
                if ((m + n) % 2) return left;
                int right = 0;
                if (i == m && j < n) {
                    right = nums2[j];
                } else if (j == n && i < m) {
                    right = nums1[i];
                } else {
                    right = min(nums1[i], nums2[j]);
                }
                return (left + right) / 2.0;
            }
        }
        return 0.0;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> nums1 = {4, 5};
    vector<int> nums2 = {1, 2, 3};
    cout << Solution().findMedianSortedArrays1(nums1, nums2) << endl;
    return 0;
}
