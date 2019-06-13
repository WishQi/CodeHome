//
//  main.cpp
//  207. Course Schedule
//
//  Created by Maoqi Li on 2019/6/13.
//  Copyright © 2019 Maoqi Li. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses, vector<int>());
        vector<int> degree(numCourses, 0);
        for (int i = 0; i < (int)prerequisites.size(); i++) {
            vector<int> edge = prerequisites[i];
            adj[edge[0]].push_back(edge[1]);
            degree[edge[1]]++;
        }
        int n = numCourses;
        queue<int> q = queue<int>();
        for (int i = 0; i < numCourses; i++) {
            if (degree[i] == 0) q.push(i);
        }
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            n--;
            vector<int>& next = adj[curr];
            for (int i = 0; i < (int)next.size(); i++) {
                degree[next[i]]--;
                if (degree[next[i]] == 0) q.push(next[i]);
            }
        }
        return n == 0;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
