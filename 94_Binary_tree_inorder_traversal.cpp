///////////////////////////////////////////////////////////
// Author:    Zhongze Hu
// Subject:   Leetcode_cpp
// Problem:   Binary tree inorder traversal
// Algorithm: Tree traversal, DFS
// Data:      11/04/2015
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> out;
        if(!root) return out;
        inorder(root, out);
        return out;
    }
    void inorder(TreeNode* root, vector<int> &out){
        if(root->left) inorder(root->left,out);
        out.push_back(root->val);
        if(root->right) inorder(root->right,out);
    }
};