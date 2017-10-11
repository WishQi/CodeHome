//
//  main.cpp
//  101. Symmetric Tree
//
//  Created by limaoqi on 10/10/2017.
//  Copyright © 2017 limaoqi. All rights reserved.
//

#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    // 6ms, AC, O(n), 扫荡了每一个节点
    bool isMirror(TreeNode *p1, TreeNode *p2) {
        if (p1 == NULL && p2 == NULL) return true;
        if (p1 == NULL || p2 == NULL) return false;
        return p1->val == p2->val && isMirror(p1->left, p2->right) && isMirror(p1->right, p2->left);
    }
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) return true;
        return isMirror(root->left, root->right);
    }
    // 3ms, AC, O(n), 遍历了每一个节点，队列从头开始相邻的一对元素相同
    bool isSymmetric1(TreeNode* root) {
        if (root == NULL) return true;
        queue<TreeNode*> q;
        q.push(root->left);
        q.push(root->right);
        while (!q.empty()) {
            TreeNode *p1 = q.front();
            q.pop();
            TreeNode *p2 = q.front();
            q.pop();
            if (p1 == NULL && p2 == NULL) continue;
            if (p1 == NULL || p2 == NULL) return false;
            if (p1->val != p2->val) return false;
            q.push(p1->left);
            q.push(p2->right);
            q.push(p1->right);
            q.push(p2->left);
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
