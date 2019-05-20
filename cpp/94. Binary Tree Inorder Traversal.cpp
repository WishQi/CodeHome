//
//  main.cpp
//  94. Binary Tree Inorder Traversal
//
//  Created by Maoqi Li on 2019/5/20.
//  Copyright © 2019 Maoqi Li. All rights reserved.
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
private:
    void _inOrder(TreeNode* root, vector<int>& result) {
        if (!root) return;
        _inOrder(root->left, result);
        result.push_back(root->val);
        _inOrder(root->right, result);
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result = vector<int>();
        _inOrder(root, result);
        return result;
    }
};


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
