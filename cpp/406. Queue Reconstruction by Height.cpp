//
//  main.cpp
//  406. Queue Reconstruction by Height
//
//  Created by Maoqi Li on 2019/9/20.
//  Copyright © 2019 Maoqi Li. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), [](vector<int>& v1, vector<int>& v2) {
            return v1[0] > v2[0] || (v1[0] == v2[0] && v1[1] < v2[1]);
        });
        vector<vector<int>> result;
        for (auto itr: people) {
            result.insert(result.begin() + itr[1], itr);
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    return 0;
}
