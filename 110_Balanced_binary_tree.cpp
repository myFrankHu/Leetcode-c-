///////////////////////////////////////////////////////////
// Author:    Zhongze Hu
// Subject:   Leetcode_cpp
// Problem:   Balanced binary tree
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
    bool isBalanced(TreeNode* root) {
        int depth = 0;
        return isBalancedHelper(root, depth);
    }
    bool isBalancedHelper(TreeNode* root,int&depth)
    {
        if(!root)
        {
            depth = 0;
            return true;
        }
        int left,right;
        if(isBalancedHelper(root->left,left) && isBalancedHelper(root->right,right) && abs(left-right)<2){
            depth = max(left,right)+1;
            return true;
        }
        return false;
    }
};