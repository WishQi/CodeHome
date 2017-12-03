//
//  main.cpp
//  538. Convert BST to Greater Tree
//
//  Created by 李茂琦 on 03/12/2017.
//  Copyright © 2017 李茂琦. All rights reserved.
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
    // 39ms, AC, O(n)
    TreeNode* convertBST(TreeNode* root) {
        int sum = 0;
        change(root, sum);
        return root;
    }
    void change(TreeNode *root, int &sum) {
        if (root != NULL) {
            change(root->right, sum);
            sum += root->val;
            root->val = sum;
            change(root->left, sum);
        }
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
