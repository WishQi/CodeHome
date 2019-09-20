//
//  main.cpp
//  295. Find Median from Data Stream
//
//  Created by Maoqi Li on 2019/8/24.
//  Copyright © 2019 Maoqi Li. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class MedianFinder {
private:
    vector<int> _container;
public:
    /** initialize your data structure here. */
    MedianFinder() {
        _container = vector<int>();
    }
    
    void addNum(int num) {
        if (_container.empty()) {
            _container.push_back(num);
            return;
        }
        int i = 0;
        while (i < _container.size() && _container[i] <= num) {
            i++;
        }
        if (i == _container.size()) {
            _container.push_back(num);
        } else {
            _container.insert(_container.begin() + i, num);
        }
    }
    
    double findMedian() {
        int n = (int)_container.size();
        if (n % 2 != 0) {
            return _container[n / 2];
        }
        return (_container[n / 2 - 1] + _container[n / 2]) / 2.0;
    }
};

class MedianFinder1 {
private:
    priority_queue<int> _low;
    priority_queue<int, vector<int>, greater<int>> _high;
public:
    /** initialize your data structure here. */
    MedianFinder1() {
        _low = priority_queue<int>();
        _high = priority_queue<int, vector<int>, greater<int>>();
    }
    
    void addNum(int num) {
        _low.push(num);
        _high.push(_low.top());
        _low.pop();
        while (_low.size() < _high.size()) {
            _low.push(_high.top());
            _high.pop();
        }
    }
    
    double findMedian() {
        return _low.size() == _high.size() ? (_low.top() + _high.top()) * 0.5 : _low.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

int main(int argc, const char * argv[]) {
    MedianFinder *test = new MedianFinder();
    test->addNum(1);
    test->addNum(2);
    cout << test->findMedian() << endl;
    test->addNum(3);
    cout << test->findMedian() << endl;
    return 0;
}
