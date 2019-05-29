//
//  main.cpp
//  124. Binary Tree Maximum Path Sum
//
//  Created by Maoqi Li on 2019/5/29.
//  Copyright © 2019 Maoqi Li. All rights reserved.
//

#include <iostream>
#include <algorithm>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    int _helper(TreeNode* node) {
        if (!node) return 0;
        int maxLeft = _helper(node->left);
        int maxRight = _helper(node->right);
        if (maxLeft > 0 || maxRight > 0) {
            node->val += max(maxLeft, maxRight);
        }
        return node->val;
    }
    void _preorder(TreeNode* node, int& maxVal) {
        if (!node) return;
        int tmp = node->val;
        if (node->left && node->right) {
            if (node->left->val > 0 && node->right->val > 0) {
                tmp = node->val - max(node->left->val, node->right->val) + node->left->val + node->right->val;
            }
        }
        maxVal = max(tmp, maxVal);
        _preorder(node->left, maxVal);
        _preorder(node->right, maxVal);
    }
public:
    int maxPathSum(TreeNode* root) {
        _helper(root);
        int res = INT_MIN;
        _preorder(root, res);
        return res;
    }
};

int main(int argc, const char * argv[]) {
    TreeNode* node1 = new TreeNode(1);
    TreeNode* node2 = new TreeNode(2);
    TreeNode* node3 = new TreeNode(3);
    node1->left = node2;
    node1->right = node3;
    Solution().maxPathSum(node1);
    return 0;
}
