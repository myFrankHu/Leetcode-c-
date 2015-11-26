///////////////////////////////////////////////////////////
// Author:    Zhongze Hu
// Subject:   Leetcode_cpp
// Problem:   Path sum II
// Algorithm: recursion
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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> out;
        vector<int> tmp;
        getPathSum(root, out, tmp, sum);
        return out;
    }
    void getPathSum(TreeNode* root, vector<vector<int>> &ans, vector<int> &tmp, int sum){
        if(!root) return;
        if(root->val == sum && !root->left && !root->right){
            tmp.push_back(sum);
            ans.push_back(tmp);
            tmp.pop_back();
        }
        else{
            tmp.push_back(root->val);
            getPathSum(root->left, ans, tmp, sum-root->val);
            getPathSum(root->right, ans, tmp, sum-root->val);
            tmp.pop_back();
        }
    }
};