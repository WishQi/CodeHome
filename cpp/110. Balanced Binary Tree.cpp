//
//  main.cpp
//  110. Balanced Binary Tree
//
//  Created by limaoqi on 11/10/2017.
//  Copyright © 2017 limaoqi. All rights reserved.
//

#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int depth(TreeNode* root) {
        if (root == NULL) return 0;
        return max(depth(root->left), depth(root->right)) + 1;
    }
    // 9ms, AC, 自顶向下, O(n * logn)
    bool isBalanced(TreeNode* root) {
        if (root == NULL) return true;
        int leftDepth = depth(root->left);
        int rightDepth = depth(root->right);
        return abs(leftDepth - rightDepth) <= 1 && isBalanced(root->left) && isBalanced(root->right);
    }
    // 9ms, AC
    int dfsDepth(TreeNode* root) {
        if (root == NULL) return 0;
        int leftDepth = dfsDepth(root->left);
        int rightDepth = dfsDepth(root->right);
        if (leftDepth == -1 || rightDepth == -1 || abs(leftDepth - rightDepth) > 1) return -1;
        return max(leftDepth, rightDepth) + 1;
    }
    bool isBalanced1(TreeNode* root) {
        return dfsDepth(root) != -1;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
