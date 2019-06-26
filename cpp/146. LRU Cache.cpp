//
//  main.cpp
//  146. LRU Cache
//
//  Created by Maoqi Li on 2019/6/21.
//  Copyright © 2019 Maoqi Li. All rights reserved.
//

#include <iostream>
#include <unordered_map>
#include <list>

using namespace std;

class LRUCache {
public:
    LRUCache(int capacity): _capacity(capacity) {}
    
    int get(int key) {
        auto itr = _hash.find(key);
        if (itr == _hash.end()) return -1;
        _cache.splice(_cache.begin(), _cache, itr->second);
        return itr->second->second;
    }
    
    void put(int key, int value) {
        auto itr = _hash.find(key);
        if (itr == _hash.end()) {
            _cache.insert(_cache.begin(), make_pair(key, value));
            _hash[key] = _cache.begin();
        } else {
            itr->second->second = value;
            _cache.splice(_cache.begin(), _cache, itr->second);
        }
        if (_cache.size() > _capacity) {
            _hash.erase(_cache.back().first);
            _cache.pop_back();
        }
    }
private:
    int _capacity;
    list<pair<int, int>> _cache;
    unordered_map<int, list<pair<int, int>>::iterator> _hash;
};


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
