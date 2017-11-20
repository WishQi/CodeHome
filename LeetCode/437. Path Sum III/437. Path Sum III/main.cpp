//
//  main.cpp
//  437. Path Sum III
//
//  Created by limaoqi on 20/11/2017.
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
    // 36ms, AC, DFS遍历了每一天路径, O(n * lgn)
    int pathSum(TreeNode* root, int sum) {
        if (root == NULL) return 0;
        return pathSumFrom(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
    }
    int pathSumFrom(TreeNode *root, int sum) {
        if (root == NULL) return 0;
        return (root->val == sum ? 1 : 0) + pathSumFrom(root->left, sum - root->val) + pathSumFrom(root->right, sum - root->val);
    }
};

int main(int argc, const char * argv[]) {
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(-3);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(2);
    root->right->right = new TreeNode(11);
    root->left->left->left = new TreeNode(3);
    root->left->left->right = new TreeNode(-2);
    root->left->right->right = new TreeNode(1);
    cout << Solution().pathSum(root, 8);
    return 0;
}
