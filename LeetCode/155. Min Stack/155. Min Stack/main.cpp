//
//  main.cpp
//  155. Min Stack
//
//  Created by limaoqi on 13/10/2017.
//  Copyright © 2017 limaoqi. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

// 26ms, AC
class MinStack {
private:
    vector<int> _sta;
    int _minElement;
public:
    /** initialize your data structure here. */
    MinStack() {
        _sta = vector<int>();
        _minElement = INT_MAX;
    }
    
    void push(int x) {
        _sta.push_back(x);
        _minElement = min(_minElement, x);
    }
    
    void pop() {
        if (_sta.empty()) return;
        int originTop = _sta.back();
        _sta.pop_back();
        if (_sta.empty()) {
            _minElement = INT_MAX;
        } else if (originTop <= _minElement) {
            _minElement = *min_element(_sta.begin(), _sta.end());
        }
    }
    
    int top() {
        if (_sta.empty()) return NULL;
        return _sta.back();
    }
    
    int getMin() {
        if (_sta.empty()) return NULL;
        return _minElement;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
