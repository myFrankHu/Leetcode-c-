///////////////////////////////////////////////////////////
// Author:    Zhongze Hu
// Subject:   Leetcode_cpp
// Problem:   Construct binary tree from inorder and preorder traversal
// Algorithm: Tree traversal
// Data:      11/20/2015
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
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int ps, int pe, int is, int ie){
        if(ps > pe) return NULL;
        TreeNode* root = new TreeNode(preorder[ps]);
        int i = is;
        while(inorder[i] != preorder[ps]) ++i;
        root->left = build(preorder,inorder,ps+1,ps+i-is,is,i-1);
        root->right = build(preorder,inorder,ps+i+1-is,pe,i+1,ie);
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder, inorder,0,preorder.size()-1,0,inorder.size()-1);
    }
};
