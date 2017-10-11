//
//  main.cpp
//  104. Maximum Depth of Binary Tree
//
//  Created by limaoqi on 10/10/2017.
//  Copyright © 2017 limaoqi. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    // 6ms, AC, O(n), 深度优先搜索
    void ds(TreeNode *node, int& maxDepth, int depth) {
        if (node == NULL) {
            maxDepth = max(maxDepth, depth);
            return;
        }
        ds(node->left, maxDepth, depth + 1);
        ds(node->right, maxDepth, depth + 1);
    }
    int maxDepth(TreeNode* root) {
        int maxDepth = 0;
        ds(root, maxDepth, 0);
        return maxDepth;
    }
    // 别人的简单写法, 6ms, AC
    int maxDepth1(TreeNode* root) {
        if (root == NULL) return 0;
        return max(maxDepth1(root->left), maxDepth1(root->right)) + 1;
    }
};

int main(int argc, const char * argv[]) {
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    cout << Solution().maxDepth1(root) << endl;
    return 0;
}
