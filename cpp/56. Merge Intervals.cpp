//
//  main.cpp
//  56. Merge Intervals
//
//  Created by 李茂琦 on 2018/9/30.
//  Copyright © 2018 李茂琦. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

bool compareIntervals(Interval a, Interval b) {
    return a.start < b.start;
}

class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> result = vector<Interval>();
        if (intervals.empty()) {
            return result;
        }
        sort(intervals.begin(), intervals.end(), compareIntervals);
        Interval tmp = intervals[0];
        for (int i = 1; i < intervals.size(); ++i) {
            Interval elem = intervals[i];
            if (tmp.end < elem.start) {
                result.push_back(tmp);
                tmp = elem;
            } else if (tmp.end < elem.end) {
                tmp.end = elem.end;
            }
        }
        result.push_back(tmp);
        return result;
    }
};



int main(int argc, const char * argv[]) {
//    [[1,3],[2,6],[8,10],[15,18]]
    vector<Interval> intervals = {Interval(1, 3), Interval(2, 6), Interval(8, 10), Interval(15, 18)};
    Solution().merge(intervals);
    return 0;
}
