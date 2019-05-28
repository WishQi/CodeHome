//
//  main.cpp
//  105. Construct Binary Tree from Preorder and Inorder Traversal
//
//  Created by Maoqi Li on 2019/5/28.
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
    TreeNode* _helper(vector<int>& preorder, vector<int>& inorder, int preStart, int preEnd, int inStart, int inEnd) {
        if (preStart > preEnd || inStart > inEnd || preStart >= preorder.size() || inStart >= inorder.size()) {
            return nullptr;
        }
        int rootVal = preorder[preStart];
        int idx = 0;
        while (idx < inorder.size()) {
            if (inorder[idx] == rootVal) break;
            idx++;
        }
        TreeNode* root = new TreeNode(rootVal);
        root->left = _helper(preorder, inorder, preStart + 1, preStart + idx - inStart, inStart, idx - 1);
        root->right = _helper(preorder, inorder, preStart + idx - inStart + 1, preEnd, idx + 1, inEnd);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return _helper(preorder, inorder, 0, (int)preorder.size() - 1, 0, (int)inorder.size() - 1);
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
