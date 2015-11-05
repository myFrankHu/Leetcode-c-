///////////////////////////////////////////////////////////
// Author:    Zhongze Hu
// Subject:   Leetcode_cpp
// Problem:   Unique binary search trees II
// Algorithm: Recursion, Divide and conquer
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
    vector<TreeNode*> generateTrees(int n) {
        return newtree(1,n);
    }
    
    vector<TreeNode*> newtree(int start, int end){
        vector<TreeNode*> Trees;
        if(start>end){
            Trees.push_back(NULL);
            return Trees;
        }
        for(int rootval = start; rootval <= end; ++ rootval){
            vector<TreeNode*> left = newtree(start,rootval-1);
            vector<TreeNode*> right = newtree(rootval+1,end);
            for(auto i:left){
                for(auto j:right){
                    TreeNode* root = new TreeNode(rootval);
                    root->left = i;
                    root->right = j;
                    Trees.push_back(root);
                }
            }
        }
        return Trees;
    }
};