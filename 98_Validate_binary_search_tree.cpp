///////////////////////////////////////////////////////////
// Author:    Zhongze Hu
// Subject:   Leetcode_cpp
// Problem:   Validate binary search tree
// Algorithm: DFS,long long int
// Data:      11/10/2015
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
    bool isValidBST(TreeNode* root) {
        return Validate(root,(long long int)INT_MIN-1,(long long int)INT_MAX+1);
    }
    bool Validate(TreeNode* root, long long int smallest, long long int biggest){
        if(root == NULL) return true;
        if(root->val <= smallest) return false;
        if(root->val >= biggest) return false;
        return Validate(root->left,smallest,biggest>root->val?root->val:biggest)&&Validate(root->right,smallest<root->val?root->val:smallest,biggest);
    }
};