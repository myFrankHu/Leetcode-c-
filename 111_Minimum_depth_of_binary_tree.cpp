///////////////////////////////////////////////////////////
// Author:    Zhongze Hu
// Subject:   Leetcode_cpp
// Problem:   Minimum depth of binary tree
// Algorithm: Calculate depth of a tree
// Data:      11/25/2015
///////////////////////////////////////////////////////////

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        if(!root->left && !root->right) return 1;
        if(!root->left) return (1+minDepth(root->right));
        if(!root->right) return (1+minDepth(root->left));
        return (1+min(minDepth(root->right),minDepth(root->left)));
    }
};