//
//  main.cpp
//  102. Binary Tree Level Order Traversal
//
//  Created by Maoqi Li on 2019/5/27.
//  Copyright © 2019 Maoqi Li. All rights reserved.
//

#include <iostream>
#include <vector>
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q = queue<TreeNode*>();
        vector<vector<int>> res = vector<vector<int>>();
        if (!root) return res;
        q.push(root);
        while (!q.empty()) {
            int levelNum = (int)q.size();
            vector<int> levelRes = vector<int>();
            for (int i = 0; i < levelNum; i++) {
                TreeNode *node = q.front();
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
                levelRes.push_back(node->val);
                q.pop();
            }
            res.push_back(levelRes);
        }
        return res;
    }
};


int main(int argc, const char * argv[]) {
    TreeNode* node1 = new TreeNode(1);
    TreeNode* node2 = new TreeNode(2);
    TreeNode* node3 = new TreeNode(3);
    TreeNode* node4 = new TreeNode(4);
    TreeNode* node5 = new TreeNode(5);
    TreeNode* node6 = new TreeNode(6);
    TreeNode* node7 = new TreeNode(7);
    node1->left = node2;
    node1->right = node3;
    node2->left = node4;
    node2->right = node5;
    node3->left = node6;
    node3->right = node7;
    Solution().levelOrder(node1);
    return 0;
}
