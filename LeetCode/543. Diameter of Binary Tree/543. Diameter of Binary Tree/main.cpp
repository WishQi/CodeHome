//
//  main.cpp
//  543. Diameter of Binary Tree
//
//  Created by Maoqi Li on 2019/5/15.
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
    int ans = 0;
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        height(root);
        return ans - 1;
    }
    int height(TreeNode* root) {
        if (!root) return 0;
        int leftHight = height(root->left) + 1;
        int rightHight = height(root->right) + 1;
        ans = max(ans, leftHight + rightHight - 1);
        return max(leftHight, rightHight);
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
