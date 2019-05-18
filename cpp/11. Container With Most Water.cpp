//
//  main.cpp
//  11. Container With Most Water
//
//  Created by limaoqi on 29/08/2017.
//  Copyright © 2017 limaoqi. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// force brute: time exceed
class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxSize = 0;
        for (int i  = 0; i < height.size(); ++i) {
            for (int j = i + 1; j < height.size(); ++j) {
                int containerSize = min(height[i], height[j]) * (j - i);
                maxSize = containerSize > maxSize ? containerSize : maxSize;
            }
        }
        return maxSize;
    }
};

// 思路：维护前后两个指针，每次向前或者向后移动其中的一个
// 总是移动的那个指针，它指向的那一根线较短，因为只有移动较短的那一根，容器区域才有可能变大
class Solution1 {
public:
    int maxArea(vector<int>& height) {
        int maxContainer = 0;
        int low = 0, high = (int)height.size() - 1;
        while (low < high) {
            maxContainer = max(maxContainer, min(height[low], height[high]) * (high - low));
            if (height[low] < height[high]) ++low;
            else --high;
        }
        return maxContainer;
    }
    int maxArea1(vector<int>& height) {
        int maxContainer = 0;
        int low = 0, high = (int)height.size() - 1;
        while (low < high) {
            int h = min(height[low], height[high]);
            maxContainer = max(maxContainer, h * (high - low));
            while (height[low] <= h && low < high) ++low;
            while (height[high] <= h && high > low) --high;
        }
        return maxContainer;
    }
};

int main(int argc, const char * argv[]) {
    
    vector<int> arr;
    while (cin.get() != '\n') {
        int num;
        cin >> num;
        arr.push_back(num);
    }
    cout << Solution1().maxArea(arr);
    
    return 0;
}
