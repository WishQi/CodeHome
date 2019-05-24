//
//  main.cpp
//  98. Validate Binary Search Tree
//
//  Created by Maoqi Li on 2019/5/24.
//  Copyright © 2019 Maoqi Li. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution1 {
private:
    vector<int> nodeVal;
    void _inorder(TreeNode* root) {
        if (!root) return;
        _inorder(root->left);
        nodeVal.push_back(root->val);
        _inorder(root->right);
    }
public:
    bool isValidBST(TreeNode* root) {
        nodeVal = vector<int>();
        _inorder(root);
        for (int i = 0; i < (int)nodeVal.size() - 1; i++) {
            if (nodeVal[i + 1] <= nodeVal[i]) return false;
        }
        return true;
    }
};

class Solution2 {
private:
    bool _helper(TreeNode* root, long long lower, long long upper) {
        if (!root) return true;
        if (root->val <= lower) return false;
        if (root->val >= upper) return false;
        return _helper(root->left, lower, root->val) && _helper(root->right, root->val, upper);
    }
public:
    bool isValidBST(TreeNode* root) {
        return _helper(root, INT64_MIN, INT64_MAX);
    }
};


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
