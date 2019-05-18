//
//  main.cpp
//  226. Invert Binary Tree
//
//  Created by limaoqi on 19/10/2017.
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
    // 0ms, AC, recursive
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL) return NULL;
        TreeNode *left = invertTree(root->left);
        TreeNode *right = invertTree(root->right);
        root->left = right;
        root->right = left;
        return root;
    }
    // 0ms, AC, literative
    TreeNode* invertTree1(TreeNode* root) {
        if (root == NULL) return NULL;
        queue<TreeNode *> qu;
        qu.push(root);
        while (!qu.empty()) {
            TreeNode *node = qu.front();
            qu.pop();
            TreeNode *tmp = node->left;
            node->left = node->right;
            node->right = tmp;
            if (node->left != NULL) qu.push(node->left);
            if (node->right != NULL) qu.push(node->right);
        }
        return root;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
