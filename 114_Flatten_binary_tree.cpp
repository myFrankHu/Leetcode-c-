///////////////////////////////////////////////////////////
// Author:    Zhongze Hu
// Subject:   Leetcode_cpp
// Problem:   Flatten binary tree to linked list
// Algorithm: pre-order traversal
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
    void flatten(TreeNode* &root) {
        if(!root) return;
        TreeNode* tmp = new TreeNode(0);
        TreeNode* out = tmp;
        flat(root,tmp);
        root = out->right;
    }
    void flat(TreeNode* root, TreeNode* &tmp){
        tmp->right = new TreeNode(root->val);
        tmp = tmp->right;
        if(root->left) flat(root->left,tmp);
        if(root->right) flat(root->right,tmp);
    }
};

